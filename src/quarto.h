#ifndef QUARTO_H
#define QUARTO_H

#include "structs.h"

/**
 * Cadastra um novo quarto no sistema
 * @param numero: número único do quarto
 * @param quantidade_hospedes: capacidade de hóspedes do quarto
 * @param valor_diaria: valor da diária do quarto
 * @return número do quarto cadastrado ou -1 em caso de erro
 */
int cadastrar_quarto(int numero, int quantidade_hospedes, float valor_diaria);

/**
 * Pesquisa quarto por número
 * @param numero: número do quarto a ser pesquisado
 * @param quarto: ponteiro para armazenar os dados do quarto encontrado
 * @return 1 se encontrado, 0 caso contrário
 */
int pesquisar_quarto_por_numero(int numero, Quarto *quarto);

/**
 * Busca quarto disponível para determinada quantidade de hóspedes
 * @param quantidade_hospedes: quantidade de hóspedes necessária
 * @param data_entrada: data de entrada no formato DD/MM/AAAA
 * @param data_saida: data de saída no formato DD/MM/AAAA
 * @return número do quarto disponível ou -1 se não encontrado
 */
int buscar_quarto_disponivel(int quantidade_hospedes, const char *data_entrada, 
                             const char *data_saida);

/**
 * Atualiza o status de um quarto
 * @param numero: número do quarto
 * @param status: novo status (OCUPADO ou DESOCUPADO)
 * @return 1 se atualizado com sucesso, 0 caso contrário
 */
int atualizar_status_quarto(int numero, StatusQuarto status);

/**
 * Lista todos os quartos cadastrados
 */
void listar_quartos();

/**
 * Exibe informações de um quarto
 * @param quarto: ponteiro para a estrutura do quarto
 */
void exibir_quarto(const Quarto *quarto);

#endif
