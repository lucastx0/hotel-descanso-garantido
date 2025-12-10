#define MUNIT_ENABLE_ASSERT_ALIASES
#define MUNIT_IMPLEMENTATION
#include "munit.h"
#include "../src/quarto.h"
#include "../src/structs.h"
#include <stdio.h>

static void* test_setup(const MunitParameter params[], void* user_data) {
    remove("data/quartos.dat");
    return NULL;
}

static void test_teardown(void* fixture) {
}

// Teste 1: Cadastro válido de quarto
static MunitResult test_cadastrar_quarto_valido(const MunitParameter params[], void* fixture) {
    int numero = cadastrar_quarto(101, 2, 150.00);
    
    munit_assert_int(numero, ==, 101);
    
    Quarto quarto;
    int encontrado = pesquisar_quarto_por_numero(101, &quarto);
    munit_assert_true(encontrado);
    munit_assert_int(quarto.quantidade_hospedes, ==, 2);
    munit_assert_float(quarto.valor_diaria, ==, 150.00);
    munit_assert_int(quarto.status, ==, DESOCUPADO);
    
    return MUNIT_OK;
}

// Teste 2: Cadastro com número inválido
static MunitResult test_cadastrar_quarto_numero_invalido(const MunitParameter params[], void* fixture) {
    int numero = cadastrar_quarto(-1, 2, 150.00);
    
    munit_assert_int(numero, ==, -1);
    
    return MUNIT_OK;
}

// Teste 3: Cadastro com valor de diária inválido
static MunitResult test_cadastrar_quarto_valor_invalido(const MunitParameter params[], void* fixture) {
    int numero = cadastrar_quarto(102, 3, -50.00);
    
    munit_assert_int(numero, ==, -1);
    
    return MUNIT_OK;
}

// Teste 4: Cadastro com quantidade de hóspedes inválida
static MunitResult test_cadastrar_quarto_hospedes_invalido(const MunitParameter params[], void* fixture) {
    int numero = cadastrar_quarto(103, 0, 200.00);
    
    munit_assert_int(numero, ==, -1);
    
    return MUNIT_OK;
}

// Teste 5: Atualização de status do quarto
static MunitResult test_atualizar_status_quarto(const MunitParameter params[], void* fixture) {
    cadastrar_quarto(104, 2, 180.00);
    
    int atualizado = atualizar_status_quarto(104, OCUPADO);
    munit_assert_true(atualizado);
    
    Quarto quarto;
    pesquisar_quarto_por_numero(104, &quarto);
    munit_assert_int(quarto.status, ==, OCUPADO);
    
    return MUNIT_OK;
}

// Teste 6: Cadastro com número duplicado
static MunitResult test_cadastrar_quarto_duplicado(const MunitParameter params[], void* fixture) {
    cadastrar_quarto(105, 2, 150.00);
    int numero2 = cadastrar_quarto(105, 3, 200.00);
    
    munit_assert_int(numero2, ==, -1);
    
    return MUNIT_OK;
}

static MunitTest quarto_tests[] = {
    { "/cadastrar_valido", test_cadastrar_quarto_valido, test_setup, test_teardown, MUNIT_TEST_OPTION_NONE, NULL },
    { "/cadastrar_numero_invalido", test_cadastrar_quarto_numero_invalido, test_setup, test_teardown, MUNIT_TEST_OPTION_NONE, NULL },
    { "/cadastrar_valor_invalido", test_cadastrar_quarto_valor_invalido, test_setup, test_teardown, MUNIT_TEST_OPTION_NONE, NULL },
    { "/cadastrar_hospedes_invalido", test_cadastrar_quarto_hospedes_invalido, test_setup, test_teardown, MUNIT_TEST_OPTION_NONE, NULL },
    { "/atualizar_status", test_atualizar_status_quarto, test_setup, test_teardown, MUNIT_TEST_OPTION_NONE, NULL },
    { "/cadastrar_duplicado", test_cadastrar_quarto_duplicado, test_setup, test_teardown, MUNIT_TEST_OPTION_NONE, NULL },
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static const MunitSuite quarto_suite = {
    "/quarto", quarto_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[]) {
    return munit_run_suite(&quarto_suite);
}
