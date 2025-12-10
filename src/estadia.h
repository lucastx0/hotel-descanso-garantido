#ifndef ESTADIA_H
#define ESTADIA_H

#include "structs.h"

/**
 * Cadastra uma nova estadia no sistema
 * @param codigo_cliente: código do cliente que irá se hospedar
 * @param quantidade_hospedes: quantidade de hóspedes
 * @param data_entrada: data de entrada no formato DD/MM/AAAA
 * @param data_saida: data de saída no formato DD/MM/AAAA
 * @return código da estadia cadastrada ou -1 em caso de erro
 */
int cadastrar_estadia(int codigo_cliente, int quantidade_hospedes, 
                     const char *data_entrada, const char *data_saida);

/**
 * Dá baixa em uma estadia e calcula o valor total
 * @param codigo_estadia: código da estadia a ser finalizada
 * @return valor total a ser pago ou -1 em caso de erro
 */
float dar_baixa_estadia(int codigo_estadia);

/**
 * Lista todas as estadias de um cliente
 * @param codigo_cliente: código do cliente
 */
void listar_estadias_cliente(int codigo_cliente);

/**
 * Calcula pontos de fidelidade de um cliente
 * @param codigo_cliente: código do cliente
 * @return total de pontos de fidelidade
 */
int calcular_pontos_fidelidade(int codigo_cliente);

/**
 * Verifica disponibilidade de quarto em um período
 * @param numero_quarto: número do quarto
 * @param data_entrada: data de entrada no formato DD/MM/AAAA
 * @param data_saida: data de saída no formato DD/MM/AAAA
 * @return 1 se disponível, 0 caso contrário
 */
int verificar_disponibilidade_quarto(int numero_quarto, const char *data_entrada, 
                                    const char *data_saida);

/**
 * Gera próximo código disponível para estadia
 * @return próximo código disponível
 */
int gerar_proximo_codigo_estadia();

/**
 * Pesquisa estadia por código
 * @param codigo: código da estadia
 * @param estadia: ponteiro para armazenar os dados da estadia
 * @return 1 se encontrada, 0 caso contrário
 */
int pesquisar_estadia_por_codigo(int codigo, Estadia *estadia);

/**
 * Exibe informações de uma estadia
 * @param estadia: ponteiro para a estrutura da estadia
 */
void exibir_estadia(const Estadia *estadia);

/**
 * Lista todas as estadias ativas
 */
void listar_estadias();

#endif
