#ifndef UTILS_H
#define UTILS_H

/**
 * Valida formato de data DD/MM/AAAA
 * @param data: string com a data
 * @return 1 se válida, 0 caso contrário
 */
int validar_data(const char *data);

/**
 * Calcula quantidade de diárias entre duas datas
 * @param data_entrada: data de entrada no formato DD/MM/AAAA
 * @param data_saida: data de saída no formato DD/MM/AAAA
 * @return quantidade de diárias
 */
int calcular_diarias(const char *data_entrada, const char *data_saida);

/**
 * Compara duas datas
 * @param data1: primeira data no formato DD/MM/AAAA
 * @param data2: segunda data no formato DD/MM/AAAA
 * @return negativo se data1 < data2, 0 se iguais, positivo se data1 > data2
 */
int comparar_datas(const char *data1, const char *data2);

/**
 * Verifica se há sobreposição entre dois períodos de datas
 * @param entrada1: data de entrada do primeiro período
 * @param saida1: data de saída do primeiro período
 * @param entrada2: data de entrada do segundo período
 * @param saida2: data de saída do segundo período
 * @return 1 se há sobreposição, 0 caso contrário
 */
int verificar_sobreposicao_datas(const char *entrada1, const char *saida1,
                                 const char *entrada2, const char *saida2);

/**
 * Limpa buffer de entrada
 */
void limpar_buffer();

/**
 * Cria diretório data se não existir
 */
void criar_diretorio_data();

/**
 * Pausa a execução e aguarda entrada do usuário
 */
void pausar();

#endif
