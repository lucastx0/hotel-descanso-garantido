#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "cliente.h"
#include "funcionario.h"
#include "quarto.h"
#include "estadia.h"
#include "utils.h"

void exibir_menu() {
    printf("\n");
    printf("╔════════════════════════════════════════════╗\n");
    printf("║   HOTEL DESCANSO GARANTIDO - SISTEMA      ║\n");
    printf("╠════════════════════════════════════════════╣\n");
    printf("║ [1]  Cadastrar Cliente                     ║\n");
    printf("║ [2]  Cadastrar Funcionário                 ║\n");
    printf("║ [3]  Cadastrar Quarto                      ║\n");
    printf("║ [4]  Cadastrar Estadia                     ║\n");
    printf("║ [5]  Dar Baixa em Estadia                  ║\n");
    printf("║ [6]  Pesquisar Cliente                     ║\n");
    printf("║ [7]  Pesquisar Funcionário                 ║\n");
    printf("║ [8]  Listar Estadias de Cliente            ║\n");
    printf("║ [9]  Calcular Pontos de Fidelidade         ║\n");
    printf("║ [10] Listar Todos os Clientes              ║\n");
    printf("║ [11] Listar Todos os Funcionários          ║\n");
    printf("║ [12] Listar Todos os Quartos               ║\n");
    printf("║ [13] Listar Todas as Estadias              ║\n");
    printf("║ [0]  Sair                                  ║\n");
    printf("╚════════════════════════════════════════════╝\n");
    printf("Escolha uma opção: ");
}

void menu_cadastrar_cliente() {
    char nome[MAX_NOME], endereco[MAX_ENDERECO], telefone[MAX_TELEFONE];
    
    printf("\n=== CADASTRAR CLIENTE ===\n");
    printf("Nome: ");
    limpar_buffer();
    fgets(nome, MAX_NOME, stdin);
    nome[strcspn(nome, "\n")] = 0;
    
    printf("Endereço: ");
    fgets(endereco, MAX_ENDERECO, stdin);
    endereco[strcspn(endereco, "\n")] = 0;
    
    printf("Telefone: ");
    fgets(telefone, MAX_TELEFONE, stdin);
    telefone[strcspn(telefone, "\n")] = 0;
    
    cadastrar_cliente(0, nome, endereco, telefone);
    pausar();
}

void menu_cadastrar_funcionario() {
    char nome[MAX_NOME], telefone[MAX_TELEFONE], cargo[MAX_CARGO];
    float salario;
    
    printf("\n=== CADASTRAR FUNCIONÁRIO ===\n");
    printf("Nome: ");
    limpar_buffer();
    fgets(nome, MAX_NOME, stdin);
    nome[strcspn(nome, "\n")] = 0;
    
    printf("Telefone: ");
    fgets(telefone, MAX_TELEFONE, stdin);
    telefone[strcspn(telefone, "\n")] = 0;
    
    printf("Cargo: ");
    fgets(cargo, MAX_CARGO, stdin);
    cargo[strcspn(cargo, "\n")] = 0;
    
    printf("Salário: R$ ");
    scanf("%f", &salario);
    
    cadastrar_funcionario(0, nome, telefone, cargo, salario);
    pausar();
}

void menu_cadastrar_quarto() {
    int numero, quantidade_hospedes;
    float valor_diaria;
    
    printf("\n=== CADASTRAR QUARTO ===\n");
    printf("Número do quarto: ");
    limpar_buffer();
    scanf("%d", &numero);
    
    printf("Capacidade (número de hóspedes): ");
    scanf("%d", &quantidade_hospedes);
    
    printf("Valor da diária: R$ ");
    scanf("%f", &valor_diaria);
    
    cadastrar_quarto(numero, quantidade_hospedes, valor_diaria);
    pausar();
}

void menu_cadastrar_estadia() {
    int codigo_cliente, quantidade_hospedes;
    char data_entrada[11], data_saida[11];
    
    printf("\n=== CADASTRAR ESTADIA ===\n");
    printf("Código do cliente: ");
    limpar_buffer();
    scanf("%d", &codigo_cliente);
    
    printf("Quantidade de hóspedes: ");
    scanf("%d", &quantidade_hospedes);
    
    printf("Data de entrada (DD/MM/AAAA): ");
    limpar_buffer();
    fgets(data_entrada, 11, stdin);
    data_entrada[strcspn(data_entrada, "\n")] = 0;
    
    printf("Data de saída (DD/MM/AAAA): ");
    fgets(data_saida, 11, stdin);
    data_saida[strcspn(data_saida, "\n")] = 0;
    
    cadastrar_estadia(codigo_cliente, quantidade_hospedes, data_entrada, data_saida);
    pausar();
}

void menu_dar_baixa_estadia() {
    int codigo_estadia;
    
    printf("\n=== DAR BAIXA EM ESTADIA ===\n");
    printf("Código da estadia: ");
    limpar_buffer();
    scanf("%d", &codigo_estadia);
    
    dar_baixa_estadia(codigo_estadia);
    pausar();
}

void menu_pesquisar_cliente() {
    int opcao;
    
    printf("\n=== PESQUISAR CLIENTE ===\n");
    printf("[1] Pesquisar por código\n");
    printf("[2] Pesquisar por nome\n");
    printf("Escolha: ");
    limpar_buffer();
    scanf("%d", &opcao);
    
    if (opcao == 1) {
        int codigo;
        printf("Código do cliente: ");
        scanf("%d", &codigo);
        
        Cliente cliente;
        if (pesquisar_cliente_por_codigo(codigo, &cliente)) {
            exibir_cliente(&cliente);
        } else {
            printf("Cliente não encontrado.\n");
        }
    } else if (opcao == 2) {
        char nome[MAX_NOME];
        printf("Nome (ou parte do nome): ");
        limpar_buffer();
        fgets(nome, MAX_NOME, stdin);
        nome[strcspn(nome, "\n")] = 0;
        
        pesquisar_cliente_por_nome(nome);
    }
    
    pausar();
}

void menu_pesquisar_funcionario() {
    int opcao;
    
    printf("\n=== PESQUISAR FUNCIONÁRIO ===\n");
    printf("[1] Pesquisar por código\n");
    printf("[2] Pesquisar por nome\n");
    printf("Escolha: ");
    limpar_buffer();
    scanf("%d", &opcao);
    
    if (opcao == 1) {
        int codigo;
        printf("Código do funcionário: ");
        scanf("%d", &codigo);
        
        Funcionario funcionario;
        if (pesquisar_funcionario_por_codigo(codigo, &funcionario)) {
            exibir_funcionario(&funcionario);
        } else {
            printf("Funcionário não encontrado.\n");
        }
    } else if (opcao == 2) {
        char nome[MAX_NOME];
        printf("Nome (ou parte do nome): ");
        limpar_buffer();
        fgets(nome, MAX_NOME, stdin);
        nome[strcspn(nome, "\n")] = 0;
        
        pesquisar_funcionario_por_nome(nome);
    }
    
    pausar();
}

void menu_listar_estadias_cliente() {
    int codigo_cliente;
    
    printf("\n=== LISTAR ESTADIAS DE CLIENTE ===\n");
    printf("Código do cliente: ");
    limpar_buffer();
    scanf("%d", &codigo_cliente);
    
    listar_estadias_cliente(codigo_cliente);
    pausar();
}

void menu_calcular_pontos_fidelidade() {
    int codigo_cliente;
    
    printf("\n=== CALCULAR PONTOS DE FIDELIDADE ===\n");
    printf("Código do cliente: ");
    limpar_buffer();
    scanf("%d", &codigo_cliente);
    
    calcular_pontos_fidelidade(codigo_cliente);
    pausar();
}

int main() {
    int opcao;
    
    // Cria diretório data se não existir
    criar_diretorio_data();
    
    printf("╔════════════════════════════════════════════╗\n");
    printf("║     BEM-VINDO AO HOTEL DESCANSO GARANTIDO  ║\n");
    printf("║            Sistema de Gestão               ║\n");
    printf("╚════════════════════════════════════════════╝\n");
    
    do {
        exibir_menu();
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                menu_cadastrar_cliente();
                break;
            case 2:
                menu_cadastrar_funcionario();
                break;
            case 3:
                menu_cadastrar_quarto();
                break;
            case 4:
                menu_cadastrar_estadia();
                break;
            case 5:
                menu_dar_baixa_estadia();
                break;
            case 6:
                menu_pesquisar_cliente();
                break;
            case 7:
                menu_pesquisar_funcionario();
                break;
            case 8:
                menu_listar_estadias_cliente();
                break;
            case 9:
                menu_calcular_pontos_fidelidade();
                break;
            case 10:
                listar_clientes();
                pausar();
                break;
            case 11:
                listar_funcionarios();
                pausar();
                break;
            case 12:
                listar_quartos();
                pausar();
                break;
            case 13:
                listar_estadias();
                pausar();
                break;
            case 0:
                printf("\nObrigado por usar o Sistema Hotel Descanso Garantido!\n");
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
                pausar();
        }
    } while (opcao != 0);
    
    return 0;
}
