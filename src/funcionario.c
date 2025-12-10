#include <stdio.h>
#include <string.h>
#include "funcionario.h"
#include "utils.h"

#define ARQUIVO_FUNCIONARIOS "data/funcionarios.dat"

int gerar_proximo_codigo_funcionario() {
    FILE *arquivo = fopen(ARQUIVO_FUNCIONARIOS, "rb");
    int max_codigo = 0;
    Funcionario funcionario;
    
    if (arquivo != NULL) {
        while (fread(&funcionario, sizeof(Funcionario), 1, arquivo)) {
            if (funcionario.ativo && funcionario.codigo > max_codigo) {
                max_codigo = funcionario.codigo;
            }
        }
        fclose(arquivo);
    }
    
    return max_codigo + 1;
}

int cadastrar_funcionario(int codigo, const char *nome, const char *telefone, 
                         const char *cargo, float salario) {
    Funcionario funcionario;
    
    // Validações
    if (nome == NULL || strlen(nome) == 0) {
        printf("[v0] Erro: Nome do funcionário é obrigatório\n");
        return -1;
    }
    
    if (salario <= 0) {
        printf("[v0] Erro: Salário deve ser maior que zero\n");
        return -1;
    }
    
    // Gera código automaticamente se não fornecido
    if (codigo == 0) {
        codigo = gerar_proximo_codigo_funcionario();
    }
    
    // Verifica se já existe funcionário com esse código
    Funcionario temp;
    if (pesquisar_funcionario_por_codigo(codigo, &temp)) {
        printf("[v0] Erro: Já existe um funcionário com o código %d\n", codigo);
        return -1;
    }
    
    // Preenche a estrutura
    funcionario.codigo = codigo;
    strncpy(funcionario.nome, nome, MAX_NOME - 1);
    funcionario.nome[MAX_NOME - 1] = '\0';
    strncpy(funcionario.telefone, telefone, MAX_TELEFONE - 1);
    funcionario.telefone[MAX_TELEFONE - 1] = '\0';
    strncpy(funcionario.cargo, cargo, MAX_CARGO - 1);
    funcionario.cargo[MAX_CARGO - 1] = '\0';
    funcionario.salario = salario;
    funcionario.ativo = 1;
    
    // Salva no arquivo
    FILE *arquivo = fopen(ARQUIVO_FUNCIONARIOS, "ab");
    if (arquivo == NULL) {
        printf("[v0] Erro ao abrir arquivo de funcionários\n");
        return -1;
    }
    
    fwrite(&funcionario, sizeof(Funcionario), 1, arquivo);
    fclose(arquivo);
    
    printf("Funcionário cadastrado com sucesso! Código: %d\n", funcionario.codigo);
    return funcionario.codigo;
}

int pesquisar_funcionario_por_codigo(int codigo, Funcionario *funcionario) {
    FILE *arquivo = fopen(ARQUIVO_FUNCIONARIOS, "rb");
    if (arquivo == NULL) {
        return 0;
    }
    
    Funcionario temp;
    while (fread(&temp, sizeof(Funcionario), 1, arquivo)) {
        if (temp.ativo && temp.codigo == codigo) {
            *funcionario = temp;
            fclose(arquivo);
            return 1;
        }
    }
    
    fclose(arquivo);
    return 0;
}

void pesquisar_funcionario_por_nome(const char *nome) {
    FILE *arquivo = fopen(ARQUIVO_FUNCIONARIOS, "rb");
    if (arquivo == NULL) {
        printf("Nenhum funcionário cadastrado.\n");
        return;
    }
    
    Funcionario funcionario;
    int encontrou = 0;
    
    printf("\n=== RESULTADOS DA PESQUISA ===\n");
    while (fread(&funcionario, sizeof(Funcionario), 1, arquivo)) {
        if (funcionario.ativo && strstr(funcionario.nome, nome) != NULL) {
            exibir_funcionario(&funcionario);
            encontrou = 1;
        }
    }
    
    if (!encontrou) {
        printf("Nenhum funcionário encontrado com o nome \"%s\"\n", nome);
    }
    
    fclose(arquivo);
}

void listar_funcionarios() {
    FILE *arquivo = fopen(ARQUIVO_FUNCIONARIOS, "rb");
    if (arquivo == NULL) {
        printf("Nenhum funcionário cadastrado.\n");
        return;
    }
    
    Funcionario funcionario;
    int count = 0;
    
    printf("\n=== LISTA DE FUNCIONÁRIOS ===\n");
    while (fread(&funcionario, sizeof(Funcionario), 1, arquivo)) {
        if (funcionario.ativo) {
            exibir_funcionario(&funcionario);
            count++;
        }
    }
    
    if (count == 0) {
        printf("Nenhum funcionário cadastrado.\n");
    } else {
        printf("\nTotal de funcionários: %d\n", count);
    }
    
    fclose(arquivo);
}

void exibir_funcionario(const Funcionario *funcionario) {
    printf("\n--- Funcionário ---\n");
    printf("Código: %d\n", funcionario->codigo);
    printf("Nome: %s\n", funcionario->nome);
    printf("Telefone: %s\n", funcionario->telefone);
    printf("Cargo: %s\n", funcionario->cargo);
    printf("Salário: R$ %.2f\n", funcionario->salario);
    printf("-------------------\n");
}
