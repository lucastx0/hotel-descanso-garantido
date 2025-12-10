#include <stdio.h>
#include <string.h>
#include "cliente.h"
#include "utils.h"

#define ARQUIVO_CLIENTES "data/clientes.dat"

int gerar_proximo_codigo_cliente() {
    FILE *arquivo = fopen(ARQUIVO_CLIENTES, "rb");
    int max_codigo = 0;
    Cliente cliente;
    
    if (arquivo != NULL) {
        while (fread(&cliente, sizeof(Cliente), 1, arquivo)) {
            if (cliente.ativo && cliente.codigo > max_codigo) {
                max_codigo = cliente.codigo;
            }
        }
        fclose(arquivo);
    }
    
    return max_codigo + 1;
}

int cadastrar_cliente(int codigo, const char *nome, const char *endereco, const char *telefone) {
    Cliente cliente;
    
    // Validações
    if (nome == NULL || strlen(nome) == 0) {
        printf("[v0] Erro: Nome do cliente é obrigatório\n");
        return -1;
    }
    
    // Gera código automaticamente se não fornecido
    if (codigo == 0) {
        codigo = gerar_proximo_codigo_cliente();
    }
    
    // Verifica se já existe cliente com esse código
    Cliente temp;
    if (pesquisar_cliente_por_codigo(codigo, &temp)) {
        printf("[v0] Erro: Já existe um cliente com o código %d\n", codigo);
        return -1;
    }
    
    // Preenche a estrutura
    cliente.codigo = codigo;
    strncpy(cliente.nome, nome, MAX_NOME - 1);
    cliente.nome[MAX_NOME - 1] = '\0';
    strncpy(cliente.endereco, endereco, MAX_ENDERECO - 1);
    cliente.endereco[MAX_ENDERECO - 1] = '\0';
    strncpy(cliente.telefone, telefone, MAX_TELEFONE - 1);
    cliente.telefone[MAX_TELEFONE - 1] = '\0';
    cliente.ativo = 1;
    
    // Salva no arquivo
    FILE *arquivo = fopen(ARQUIVO_CLIENTES, "ab");
    if (arquivo == NULL) {
        printf("[v0] Erro ao abrir arquivo de clientes\n");
        return -1;
    }
    
    fwrite(&cliente, sizeof(Cliente), 1, arquivo);
    fclose(arquivo);
    
    printf("Cliente cadastrado com sucesso! Código: %d\n", cliente.codigo);
    return cliente.codigo;
}

int pesquisar_cliente_por_codigo(int codigo, Cliente *cliente) {
    FILE *arquivo = fopen(ARQUIVO_CLIENTES, "rb");
    if (arquivo == NULL) {
        return 0;
    }
    
    Cliente temp;
    while (fread(&temp, sizeof(Cliente), 1, arquivo)) {
        if (temp.ativo && temp.codigo == codigo) {
            *cliente = temp;
            fclose(arquivo);
            return 1;
        }
    }
    
    fclose(arquivo);
    return 0;
}

void pesquisar_cliente_por_nome(const char *nome) {
    FILE *arquivo = fopen(ARQUIVO_CLIENTES, "rb");
    if (arquivo == NULL) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }
    
    Cliente cliente;
    int encontrou = 0;
    
    printf("\n=== RESULTADOS DA PESQUISA ===\n");
    while (fread(&cliente, sizeof(Cliente), 1, arquivo)) {
        if (cliente.ativo && strstr(cliente.nome, nome) != NULL) {
            exibir_cliente(&cliente);
            encontrou = 1;
        }
    }
    
    if (!encontrou) {
        printf("Nenhum cliente encontrado com o nome \"%s\"\n", nome);
    }
    
    fclose(arquivo);
}

void listar_clientes() {
    FILE *arquivo = fopen(ARQUIVO_CLIENTES, "rb");
    if (arquivo == NULL) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }
    
    Cliente cliente;
    int count = 0;
    
    printf("\n=== LISTA DE CLIENTES ===\n");
    while (fread(&cliente, sizeof(Cliente), 1, arquivo)) {
        if (cliente.ativo) {
            exibir_cliente(&cliente);
            count++;
        }
    }
    
    if (count == 0) {
        printf("Nenhum cliente cadastrado.\n");
    } else {
        printf("\nTotal de clientes: %d\n", count);
    }
    
    fclose(arquivo);
}

void exibir_cliente(const Cliente *cliente) {
    printf("\n--- Cliente ---\n");
    printf("Código: %d\n", cliente->codigo);
    printf("Nome: %s\n", cliente->nome);
    printf("Endereço: %s\n", cliente->endereco);
    printf("Telefone: %s\n", cliente->telefone);
    printf("---------------\n");
}
