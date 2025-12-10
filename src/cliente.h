#ifndef CLIENTE_H
#define CLIENTE_H

#include "structs.h"

/**
 * Cadastra um novo cliente no sistema
 * @param codigo: código único do cliente (gerado automaticamente se 0)
 * @param nome: nome completo do cliente
 * @param endereco: endereço do cliente
 * @param telefone: telefone do cliente
 * @return código do cliente cadastrado ou -1 em caso de erro
 */
int cadastrar_cliente(int codigo, const char *nome, const char *endereco, const char *telefone);

/**
 * Pesquisa cliente por código
 * @param codigo: código do cliente a ser pesquisado
 * @param cliente: ponteiro para armazenar os dados do cliente encontrado
 * @return 1 se encontrado, 0 caso contrário
 */
int pesquisar_cliente_por_codigo(int codigo, Cliente *cliente);

/**
 * Pesquisa clientes por nome (busca parcial)
 * @param nome: nome ou parte do nome a ser pesquisado
 */
void pesquisar_cliente_por_nome(const char *nome);

/**
 * Lista todos os clientes cadastrados
 */
void listar_clientes();

/**
 * Gera próximo código disponível para cliente
 * @return próximo código disponível
 */
int gerar_proximo_codigo_cliente();

/**
 * Exibe informações de um cliente
 * @param cliente: ponteiro para a estrutura do cliente
 */
void exibir_cliente(const Cliente *cliente);

#endif
