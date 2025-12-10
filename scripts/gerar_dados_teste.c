#include <stdio.h>
#include <string.h>
#include "../src/structs.h"

#define ARQUIVO_CLIENTES "data/clientes.dat"
#define ARQUIVO_FUNCIONARIOS "data/funcionarios.dat"
#define ARQUIVO_QUARTOS "data/quartos.dat"
#define ARQUIVO_ESTADIAS "data/estadias.dat"

void gerar_clientes() {
    FILE *arquivo = fopen(ARQUIVO_CLIENTES, "wb");
    if (!arquivo) {
        printf("Erro ao criar arquivo de clientes\n");
        return;
    }
    
    Cliente clientes[] = {
        {1, "João Silva", "Rua das Flores, 123 - São Paulo/SP", "(11) 98765-4321", 1},
        {2, "Maria Santos", "Av. Paulista, 1000 - São Paulo/SP", "(11) 97654-3210", 1},
        {3, "Pedro Costa", "Rua Augusta, 500 - São Paulo/SP", "(11) 96543-2109", 1},
        {4, "Ana Oliveira", "Rua Oscar Freire, 200 - São Paulo/SP", "(11) 95432-1098", 1},
        {5, "Carlos Ferreira", "Av. Rebouças, 3000 - São Paulo/SP", "(11) 94321-0987", 1}
    };
    
    for (int i = 0; i < 5; i++) {
        fwrite(&clientes[i], sizeof(Cliente), 1, arquivo);
    }
    
    fclose(arquivo);
    printf("✓ 5 clientes cadastrados com sucesso!\n");
}

void gerar_funcionarios() {
    FILE *arquivo = fopen(ARQUIVO_FUNCIONARIOS, "wb");
    if (!arquivo) {
        printf("Erro ao criar arquivo de funcionários\n");
        return;
    }
    
    Funcionario funcionarios[] = {
        {1, "José Alves", "(11) 91234-5678", "Recepcionista", 2500.00, 1},
        {2, "Lucia Ferreira", "(11) 91234-5679", "Gerente", 4500.00, 1},
        {3, "Roberto Lima", "(11) 91234-5680", "Camareira", 1800.00, 1}
    };
    
    for (int i = 0; i < 3; i++) {
        fwrite(&funcionarios[i], sizeof(Funcionario), 1, arquivo);
    }
    
    fclose(arquivo);
    printf("✓ 3 funcionários cadastrados com sucesso!\n");
}

void gerar_quartos() {
    FILE *arquivo = fopen(ARQUIVO_QUARTOS, "wb");
    if (!arquivo) {
        printf("Erro ao criar arquivo de quartos\n");
        return;
    }
    
    Quarto quartos[] = {
        {101, 2, 150.00, DESOCUPADO, 1},
        {102, 2, 150.00, OCUPADO, 1},
        {103, 3, 200.00, DESOCUPADO, 1},
        {104, 3, 200.00, DESOCUPADO, 1},
        {105, 4, 280.00, DESOCUPADO, 1},
        {201, 2, 180.00, OCUPADO, 1},
        {202, 2, 180.00, DESOCUPADO, 1},
        {203, 1, 120.00, DESOCUPADO, 1}
    };
    
    for (int i = 0; i < 8; i++) {
        fwrite(&quartos[i], sizeof(Quarto), 1, arquivo);
    }
    
    fclose(arquivo);
    printf("✓ 8 quartos cadastrados com sucesso!\n");
}

void gerar_estadias() {
    FILE *arquivo = fopen(ARQUIVO_ESTADIAS, "wb");
    if (!arquivo) {
        printf("Erro ao criar arquivo de estadias\n");
        return;
    }
    
    Estadia estadias[] = {
        {1, "01/12/2024", "05/12/2024", 4, 1, 102, 0, 1},  // Estadia ativa
        {2, "10/11/2024", "15/11/2024", 5, 2, 201, 1, 1},  // Estadia finalizada
        {3, "20/11/2024", "25/11/2024", 5, 3, 103, 1, 1}   // Estadia finalizada
    };
    
    for (int i = 0; i < 3; i++) {
        fwrite(&estadias[i], sizeof(Estadia), 1, arquivo);
    }
    
    fclose(arquivo);
    printf("✓ 3 estadias cadastradas com sucesso (1 ativa, 2 finalizadas)!\n");
}

int main() {
    printf("\n=== GERANDO DADOS DE TESTE ===\n\n");
    
    gerar_clientes();
    gerar_funcionarios();
    gerar_quartos();
    gerar_estadias();
    
    printf("\n=== DADOS DE TESTE GERADOS COM SUCESSO ===\n");
    printf("\nOs seguintes arquivos foram criados na pasta 'data/':\n");
    printf("  - clientes.dat (5 clientes)\n");
    printf("  - funcionarios.dat (3 funcionários)\n");
    printf("  - quartos.dat (8 quartos)\n");
    printf("  - estadias.dat (3 estadias)\n\n");
    
    return 0;
}
