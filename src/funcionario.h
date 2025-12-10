#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "structs.h"

/**
 * Cadastra um novo funcionário no sistema
 * @param codigo: código único do funcionário (gerado automaticamente se 0)
 * @param nome: nome completo do funcionário
 * @param telefone: telefone do funcionário
 * @param cargo: cargo do funcionário
 * @param salario: salário do funcionário
 * @return código do funcionário cadastrado ou -1 em caso de erro
 */
int cadastrar_funcionario(int codigo, const char *nome, const char *telefone, 
                         const char *cargo, float salario);

/**
 * Pesquisa funcionário por código
 * @param codigo: código do funcionário a ser pesquisado
 * @param funcionario: ponteiro para armazenar os dados do funcionário encontrado
 * @return 1 se encontrado, 0 caso contrário
 */
int pesquisar_funcionario_por_codigo(int codigo, Funcionario *funcionario);

/**
 * Pesquisa funcionários por nome (busca parcial)
 * @param nome: nome ou parte do nome a ser pesquisado
 */
void pesquisar_funcionario_por_nome(const char *nome);

/**
 * Lista todos os funcionários cadastrados
 */
void listar_funcionarios();

/**
 * Gera próximo código disponível para funcionário
 * @return próximo código disponível
 */
int gerar_proximo_codigo_funcionario();

/**
 * Exibe informações de um funcionário
 * @param funcionario: ponteiro para a estrutura do funcionário
 */
void exibir_funcionario(const Funcionario *funcionario);

#endif
