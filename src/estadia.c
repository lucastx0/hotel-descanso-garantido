#include <stdio.h>
#include <string.h>
#include "estadia.h"
#include "cliente.h"
#include "quarto.h"
#include "utils.h"

#define ARQUIVO_ESTADIAS "data/estadias.dat"

int gerar_proximo_codigo_estadia() {
    FILE *arquivo = fopen(ARQUIVO_ESTADIAS, "rb");
    int max_codigo = 0;
    Estadia estadia;
    
    if (arquivo != NULL) {
        while (fread(&estadia, sizeof(Estadia), 1, arquivo)) {
            if (estadia.ativo && estadia.codigo > max_codigo) {
                max_codigo = estadia.codigo;
            }
        }
        fclose(arquivo);
    }
    
    return max_codigo + 1;
}

int verificar_disponibilidade_quarto(int numero_quarto, const char *data_entrada, 
                                    const char *data_saida) {
    FILE *arquivo = fopen(ARQUIVO_ESTADIAS, "rb");
    if (arquivo == NULL) {
        return 1; // Se não há estadias, está disponível
    }
    
    Estadia estadia;
    while (fread(&estadia, sizeof(Estadia), 1, arquivo)) {
        if (estadia.ativo && !estadia.finalizada && 
            estadia.numero_quarto == numero_quarto) {
            
            // Verifica se há sobreposição de datas
            if (verificar_sobreposicao_datas(data_entrada, data_saida,
                                           estadia.data_entrada, estadia.data_saida)) {
                fclose(arquivo);
                return 0; // Não disponível
            }
        }
    }
    
    fclose(arquivo);
    return 1; // Disponível
}

int cadastrar_estadia(int codigo_cliente, int quantidade_hospedes, 
                     const char *data_entrada, const char *data_saida) {
    Estadia estadia;
    
    // Validações
    if (quantidade_hospedes <= 0) {
        printf("[v0] Erro: Quantidade de hóspedes deve ser maior que zero\n");
        return -1;
    }
    
    // Verifica se o cliente existe
    Cliente cliente;
    if (!pesquisar_cliente_por_codigo(codigo_cliente, &cliente)) {
        printf("[v0] Erro: Cliente com código %d não encontrado\n", codigo_cliente);
        return -1;
    }
    
    // Valida datas
    if (!validar_data(data_entrada) || !validar_data(data_saida)) {
        printf("[v0] Erro: Data inválida. Use o formato DD/MM/AAAA\n");
        return -1;
    }
    
    if (comparar_datas(data_entrada, data_saida) >= 0) {
        printf("[v0] Erro: Data de saída deve ser posterior à data de entrada\n");
        return -1;
    }
    
    // Busca quarto disponível
    int numero_quarto = buscar_quarto_disponivel(quantidade_hospedes, data_entrada, data_saida);
    if (numero_quarto == -1) {
        printf("[v0] Erro: Não há quartos disponíveis para %d hóspedes no período solicitado\n", 
               quantidade_hospedes);
        return -1;
    }
    
    // Calcula quantidade de diárias
    int diarias = calcular_diarias(data_entrada, data_saida);
    
    // Gera código da estadia
    int codigo = gerar_proximo_codigo_estadia();
    
    // Preenche a estrutura
    estadia.codigo = codigo;
    strncpy(estadia.data_entrada, data_entrada, 10);
    estadia.data_entrada[10] = '\0';
    strncpy(estadia.data_saida, data_saida, 10);
    estadia.data_saida[10] = '\0';
    estadia.quantidade_diarias = diarias;
    estadia.codigo_cliente = codigo_cliente;
    estadia.numero_quarto = numero_quarto;
    estadia.finalizada = 0;
    estadia.ativo = 1;
    
    // Salva no arquivo
    FILE *arquivo = fopen(ARQUIVO_ESTADIAS, "ab");
    if (arquivo == NULL) {
        printf("[v0] Erro ao abrir arquivo de estadias\n");
        return -1;
    }
    
    fwrite(&estadia, sizeof(Estadia), 1, arquivo);
    fclose(arquivo);
    
    // Atualiza status do quarto para ocupado
    atualizar_status_quarto(numero_quarto, OCUPADO);
    
    printf("Estadia cadastrada com sucesso!\n");
    printf("Código da estadia: %d\n", codigo);
    printf("Quarto alocado: %d\n", numero_quarto);
    printf("Quantidade de diárias: %d\n", diarias);
    
    return codigo;
}

float dar_baixa_estadia(int codigo_estadia) {
    FILE *arquivo = fopen(ARQUIVO_ESTADIAS, "rb+");
    if (arquivo == NULL) {
        printf("[v0] Erro ao abrir arquivo de estadias\n");
        return -1;
    }
    
    Estadia estadia;
    long posicao;
    int encontrada = 0;
    
    while ((posicao = ftell(arquivo)), fread(&estadia, sizeof(Estadia), 1, arquivo)) {
        if (estadia.ativo && estadia.codigo == codigo_estadia) {
            encontrada = 1;
            
            if (estadia.finalizada) {
                printf("[v0] Erro: Esta estadia já foi finalizada\n");
                fclose(arquivo);
                return -1;
            }
            
            // Busca informações do quarto
            Quarto quarto;
            if (!pesquisar_quarto_por_numero(estadia.numero_quarto, &quarto)) {
                printf("[v0] Erro: Quarto não encontrado\n");
                fclose(arquivo);
                return -1;
            }
            
            // Calcula valor total
            float valor_total = estadia.quantidade_diarias * quarto.valor_diaria;
            
            // Marca estadia como finalizada
            estadia.finalizada = 1;
            fseek(arquivo, posicao, SEEK_SET);
            fwrite(&estadia, sizeof(Estadia), 1, arquivo);
            
            // Atualiza status do quarto para desocupado
            atualizar_status_quarto(estadia.numero_quarto, DESOCUPADO);
            
            printf("\n=== BAIXA DE ESTADIA ===\n");
            printf("Código da estadia: %d\n", codigo_estadia);
            printf("Quantidade de diárias: %d\n", estadia.quantidade_diarias);
            printf("Valor da diária: R$ %.2f\n", quarto.valor_diaria);
            printf("VALOR TOTAL A PAGAR: R$ %.2f\n", valor_total);
            printf("========================\n");
            
            fclose(arquivo);
            return valor_total;
        }
    }
    
    fclose(arquivo);
    
    if (!encontrada) {
        printf("[v0] Erro: Estadia com código %d não encontrada\n", codigo_estadia);
    }
    
    return -1;
}

void listar_estadias_cliente(int codigo_cliente) {
    FILE *arquivo = fopen(ARQUIVO_ESTADIAS, "rb");
    if (arquivo == NULL) {
        printf("Nenhuma estadia cadastrada.\n");
        return;
    }
    
    // Verifica se o cliente existe
    Cliente cliente;
    if (!pesquisar_cliente_por_codigo(codigo_cliente, &cliente)) {
        printf("[v0] Cliente com código %d não encontrado\n", codigo_cliente);
        fclose(arquivo);
        return;
    }
    
    Estadia estadia;
    int count = 0;
    
    printf("\n=== ESTADIAS DO CLIENTE: %s ===\n", cliente.nome);
    while (fread(&estadia, sizeof(Estadia), 1, arquivo)) {
        if (estadia.ativo && estadia.codigo_cliente == codigo_cliente) {
            exibir_estadia(&estadia);
            count++;
        }
    }
    
    if (count == 0) {
        printf("Nenhuma estadia encontrada para este cliente.\n");
    } else {
        printf("\nTotal de estadias: %d\n", count);
    }
    
    fclose(arquivo);
}

int calcular_pontos_fidelidade(int codigo_cliente) {
    FILE *arquivo = fopen(ARQUIVO_ESTADIAS, "rb");
    if (arquivo == NULL) {
        return 0;
    }
    
    // Verifica se o cliente existe
    Cliente cliente;
    if (!pesquisar_cliente_por_codigo(codigo_cliente, &cliente)) {
        printf("[v0] Cliente com código %d não encontrado\n", codigo_cliente);
        fclose(arquivo);
        return -1;
    }
    
    Estadia estadia;
    int total_diarias = 0;
    
    while (fread(&estadia, sizeof(Estadia), 1, arquivo)) {
        if (estadia.ativo && estadia.codigo_cliente == codigo_cliente) {
            total_diarias += estadia.quantidade_diarias;
        }
    }
    
    fclose(arquivo);
    
    int pontos = total_diarias * 10; // 10 pontos por diária
    
    printf("\n=== PONTOS DE FIDELIDADE ===\n");
    printf("Cliente: %s\n", cliente.nome);
    printf("Total de diárias: %d\n", total_diarias);
    printf("PONTOS DE FIDELIDADE: %d\n", pontos);
    printf("============================\n");
    
    return pontos;
}

int pesquisar_estadia_por_codigo(int codigo, Estadia *estadia) {
    FILE *arquivo = fopen(ARQUIVO_ESTADIAS, "rb");
    if (arquivo == NULL) {
        return 0;
    }
    
    Estadia temp;
    while (fread(&temp, sizeof(Estadia), 1, arquivo)) {
        if (temp.ativo && temp.codigo == codigo) {
            *estadia = temp;
            fclose(arquivo);
            return 1;
        }
    }
    
    fclose(arquivo);
    return 0;
}

void exibir_estadia(const Estadia *estadia) {
    printf("\n--- Estadia ---\n");
    printf("Código: %d\n", estadia->codigo);
    printf("Cliente (código): %d\n", estadia->codigo_cliente);
    printf("Quarto: %d\n", estadia->numero_quarto);
    printf("Data de entrada: %s\n", estadia->data_entrada);
    printf("Data de saída: %s\n", estadia->data_saida);
    printf("Quantidade de diárias: %d\n", estadia->quantidade_diarias);
    printf("Status: %s\n", estadia->finalizada ? "FINALIZADA" : "ATIVA");
    printf("---------------\n");
}

void listar_estadias() {
    FILE *arquivo = fopen(ARQUIVO_ESTADIAS, "rb");
    if (arquivo == NULL) {
        printf("Nenhuma estadia cadastrada.\n");
        return;
    }
    
    Estadia estadia;
    int count = 0;
    
    printf("\n=== LISTA DE ESTADIAS ===\n");
    while (fread(&estadia, sizeof(Estadia), 1, arquivo)) {
        if (estadia.ativo) {
            exibir_estadia(&estadia);
            count++;
        }
    }
    
    if (count == 0) {
        printf("Nenhuma estadia cadastrada.\n");
    } else {
        printf("\nTotal de estadias: %d\n", count);
    }
    
    fclose(arquivo);
}
