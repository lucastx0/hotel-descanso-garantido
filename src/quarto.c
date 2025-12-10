#include <stdio.h>
#include <string.h>
#include "quarto.h"
#include "estadia.h"
#include "utils.h"

#define ARQUIVO_QUARTOS "data/quartos.dat"

int cadastrar_quarto(int numero, int quantidade_hospedes, float valor_diaria) {
    Quarto quarto;
    
    // Validações
    if (numero <= 0) {
        printf("[v0] Erro: Número do quarto deve ser maior que zero\n");
        return -1;
    }
    
    if (quantidade_hospedes <= 0) {
        printf("[v0] Erro: Quantidade de hóspedes deve ser maior que zero\n");
        return -1;
    }
    
    if (valor_diaria <= 0) {
        printf("[v0] Erro: Valor da diária deve ser maior que zero\n");
        return -1;
    }
    
    // Verifica se já existe quarto com esse número
    Quarto temp;
    if (pesquisar_quarto_por_numero(numero, &temp)) {
        printf("[v0] Erro: Já existe um quarto com o número %d\n", numero);
        return -1;
    }
    
    // Preenche a estrutura
    quarto.numero = numero;
    quarto.quantidade_hospedes = quantidade_hospedes;
    quarto.valor_diaria = valor_diaria;
    quarto.status = DESOCUPADO;
    quarto.ativo = 1;
    
    // Salva no arquivo
    FILE *arquivo = fopen(ARQUIVO_QUARTOS, "ab");
    if (arquivo == NULL) {
        printf("[v0] Erro ao abrir arquivo de quartos\n");
        return -1;
    }
    
    fwrite(&quarto, sizeof(Quarto), 1, arquivo);
    fclose(arquivo);
    
    printf("Quarto cadastrado com sucesso! Número: %d\n", quarto.numero);
    return quarto.numero;
}

int pesquisar_quarto_por_numero(int numero, Quarto *quarto) {
    FILE *arquivo = fopen(ARQUIVO_QUARTOS, "rb");
    if (arquivo == NULL) {
        return 0;
    }
    
    Quarto temp;
    while (fread(&temp, sizeof(Quarto), 1, arquivo)) {
        if (temp.ativo && temp.numero == numero) {
            *quarto = temp;
            fclose(arquivo);
            return 1;
        }
    }
    
    fclose(arquivo);
    return 0;
}

int buscar_quarto_disponivel(int quantidade_hospedes, const char *data_entrada, 
                             const char *data_saida) {
    FILE *arquivo = fopen(ARQUIVO_QUARTOS, "rb");
    if (arquivo == NULL) {
        printf("[v0] Nenhum quarto cadastrado\n");
        return -1;
    }
    
    Quarto quarto;
    while (fread(&quarto, sizeof(Quarto), 1, arquivo)) {
        if (quarto.ativo && 
            quarto.quantidade_hospedes >= quantidade_hospedes &&
            quarto.status == DESOCUPADO) {
            
            // Verifica se o quarto está realmente disponível no período
            if (verificar_disponibilidade_quarto(quarto.numero, data_entrada, data_saida)) {
                fclose(arquivo);
                return quarto.numero;
            }
        }
    }
    
    fclose(arquivo);
    return -1;
}

int atualizar_status_quarto(int numero, StatusQuarto status) {
    FILE *arquivo = fopen(ARQUIVO_QUARTOS, "rb+");
    if (arquivo == NULL) {
        printf("[v0] Erro ao abrir arquivo de quartos\n");
        return 0;
    }
    
    Quarto quarto;
    long posicao;
    int atualizado = 0;
    
    while ((posicao = ftell(arquivo)), fread(&quarto, sizeof(Quarto), 1, arquivo)) {
        if (quarto.ativo && quarto.numero == numero) {
            quarto.status = status;
            fseek(arquivo, posicao, SEEK_SET);
            fwrite(&quarto, sizeof(Quarto), 1, arquivo);
            atualizado = 1;
            break;
        }
    }
    
    fclose(arquivo);
    return atualizado;
}

void listar_quartos() {
    FILE *arquivo = fopen(ARQUIVO_QUARTOS, "rb");
    if (arquivo == NULL) {
        printf("Nenhum quarto cadastrado.\n");
        return;
    }
    
    Quarto quarto;
    int count = 0;
    
    printf("\n=== LISTA DE QUARTOS ===\n");
    while (fread(&quarto, sizeof(Quarto), 1, arquivo)) {
        if (quarto.ativo) {
            exibir_quarto(&quarto);
            count++;
        }
    }
    
    if (count == 0) {
        printf("Nenhum quarto cadastrado.\n");
    } else {
        printf("\nTotal de quartos: %d\n", count);
    }
    
    fclose(arquivo);
}

void exibir_quarto(const Quarto *quarto) {
    printf("\n--- Quarto ---\n");
    printf("Número: %d\n", quarto->numero);
    printf("Capacidade: %d hóspedes\n", quarto->quantidade_hospedes);
    printf("Valor da diária: R$ %.2f\n", quarto->valor_diaria);
    printf("Status: %s\n", quarto->status == OCUPADO ? "OCUPADO" : "DESOCUPADO");
    printf("--------------\n");
}
