#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "utils.h"

int validar_data(const char *data) {
    if (strlen(data) != 10) {
        return 0;
    }
    
    // Verifica formato DD/MM/AAAA
    if (data[2] != '/' || data[5] != '/') {
        return 0;
    }
    
    // Verifica se são dígitos
    for (int i = 0; i < 10; i++) {
        if (i != 2 && i != 5 && !isdigit(data[i])) {
            return 0;
        }
    }
    
    // Extrai dia, mês e ano
    int dia = (data[0] - '0') * 10 + (data[1] - '0');
    int mes = (data[3] - '0') * 10 + (data[4] - '0');
    int ano = (data[6] - '0') * 1000 + (data[7] - '0') * 100 + 
              (data[8] - '0') * 10 + (data[9] - '0');
    
    // Validações básicas
    if (mes < 1 || mes > 12) {
        return 0;
    }
    
    if (dia < 1 || dia > 31) {
        return 0;
    }
    
    // Validação de dias por mês
    int dias_mes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // Ano bissexto
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
        dias_mes[1] = 29;
    }
    
    if (dia > dias_mes[mes - 1]) {
        return 0;
    }
    
    return 1;
}

int comparar_datas(const char *data1, const char *data2) {
    // Extrai componentes de data1
    int dia1 = (data1[0] - '0') * 10 + (data1[1] - '0');
    int mes1 = (data1[3] - '0') * 10 + (data1[4] - '0');
    int ano1 = (data1[6] - '0') * 1000 + (data1[7] - '0') * 100 + 
               (data1[8] - '0') * 10 + (data1[9] - '0');
    
    // Extrai componentes de data2
    int dia2 = (data2[0] - '0') * 10 + (data2[1] - '0');
    int mes2 = (data2[3] - '0') * 10 + (data2[4] - '0');
    int ano2 = (data2[6] - '0') * 1000 + (data2[7] - '0') * 100 + 
               (data2[8] - '0') * 10 + (data2[9] - '0');
    
    // Compara anos
    if (ano1 != ano2) {
        return ano1 - ano2;
    }
    
    // Compara meses
    if (mes1 != mes2) {
        return mes1 - mes2;
    }
    
    // Compara dias
    return dia1 - dia2;
}

int calcular_diarias(const char *data_entrada, const char *data_saida) {
    // Extrai componentes de data_entrada
    int dia1 = (data_entrada[0] - '0') * 10 + (data_entrada[1] - '0');
    int mes1 = (data_entrada[3] - '0') * 10 + (data_entrada[4] - '0');
    int ano1 = (data_entrada[6] - '0') * 1000 + (data_entrada[7] - '0') * 100 + 
               (data_entrada[8] - '0') * 10 + (data_entrada[9] - '0');
    
    // Extrai componentes de data_saida
    int dia2 = (data_saida[0] - '0') * 10 + (data_saida[1] - '0');
    int mes2 = (data_saida[3] - '0') * 10 + (data_saida[4] - '0');
    int ano2 = (data_saida[6] - '0') * 1000 + (data_saida[7] - '0') * 100 + 
               (data_saida[8] - '0') * 10 + (data_saida[9] - '0');
    
    // Conversão simples para dias (aproximação)
    int dias1 = ano1 * 365 + mes1 * 30 + dia1;
    int dias2 = ano2 * 365 + mes2 * 30 + dia2;
    
    return dias2 - dias1;
}

int verificar_sobreposicao_datas(const char *entrada1, const char *saida1,
                                 const char *entrada2, const char *saida2) {
    // Período 1: [entrada1, saida1]
    // Período 2: [entrada2, saida2]
    
    // Não há sobreposição se um período termina antes do outro começar
    if (comparar_datas(saida1, entrada2) <= 0) {
        return 0; // saida1 <= entrada2
    }
    
    if (comparar_datas(saida2, entrada1) <= 0) {
        return 0; // saida2 <= entrada1
    }
    
    return 1; // Há sobreposição
}

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void criar_diretorio_data() {
    #ifdef _WIN32
        mkdir("data");
    #else
        mkdir("data", 0777);
    #endif
}

void pausar() {
    printf("\nPressione ENTER para continuar...");
    limpar_buffer();
    getchar();
}
