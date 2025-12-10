#ifndef STRUCTS_H
#define STRUCTS_H

#define MAX_NOME 100
#define MAX_ENDERECO 200
#define MAX_TELEFONE 20
#define MAX_CARGO 50

// Status do quarto
typedef enum {
    DESOCUPADO = 0,
    OCUPADO = 1
} StatusQuarto;

// Estrutura para Cliente
typedef struct {
    int codigo;
    char nome[MAX_NOME];
    char endereco[MAX_ENDERECO];
    char telefone[MAX_TELEFONE];
    int ativo; // 1 = ativo, 0 = inativo/deletado
} Cliente;

// Estrutura para Funcionário
typedef struct {
    int codigo;
    char nome[MAX_NOME];
    char telefone[MAX_TELEFONE];
    char cargo[MAX_CARGO];
    float salario;
    int ativo; // 1 = ativo, 0 = inativo/deletado
} Funcionario;

// Estrutura para Quarto
typedef struct {
    int numero;
    int quantidade_hospedes;
    float valor_diaria;
    StatusQuarto status;
    int ativo; // 1 = ativo, 0 = inativo/deletado
} Quarto;

// Estrutura para Estadia
typedef struct {
    int codigo;
    char data_entrada[11]; // formato DD/MM/AAAA
    char data_saida[11];   // formato DD/MM/AAAA
    int quantidade_diarias;
    int codigo_cliente;
    int numero_quarto;
    int finalizada; // 0 = ativa, 1 = finalizada
    int ativo; // 1 = ativo, 0 = inativo/deletado
} Estadia;

#endif
