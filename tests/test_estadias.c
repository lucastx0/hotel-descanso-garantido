#define MUNIT_ENABLE_ASSERT_ALIASES
#define MUNIT_IMPLEMENTATION
#include "munit.h"
#include "../src/estadia.h"
#include "../src/cliente.h"
#include "../src/quarto.h"
#include "../src/structs.h"
#include <stdio.h>

static void* test_setup(const MunitParameter params[], void* user_data) {
    remove("data/estadias.dat");
    remove("data/clientes.dat");
    remove("data/quartos.dat");
    return NULL;
}

static void test_teardown(void* fixture) {
}

// Teste 1: Cadastro válido de estadia
static MunitResult test_cadastrar_estadia_valida(const MunitParameter params[], void* fixture) {
    // Prepara dados
    int codigo_cliente = cadastrar_cliente(0, "Teste Cliente", "End Teste", "119999");
    cadastrar_quarto(201, 2, 150.00);
    
    int codigo = cadastrar_estadia(0, "01/12/2024", "05/12/2024", codigo_cliente, 201);
    
    munit_assert_int(codigo, >, 0);
    
    Estadia estadia;
    int encontrado = pesquisar_estadia_por_codigo(codigo, &estadia);
    munit_assert_true(encontrado);
    munit_assert_int(estadia.quantidade_diarias, ==, 4);
    
    return MUNIT_OK;
}

// Teste 2: Cadastro com cliente inexistente
static MunitResult test_cadastrar_estadia_cliente_invalido(const MunitParameter params[], void* fixture) {
    cadastrar_quarto(202, 2, 150.00);
    
    int codigo = cadastrar_estadia(0, "01/12/2024", "05/12/2024", 9999, 202);
    
    munit_assert_int(codigo, ==, -1);
    
    return MUNIT_OK;
}

// Teste 3: Cadastro com quarto inexistente
static MunitResult test_cadastrar_estadia_quarto_invalido(const MunitParameter params[], void* fixture) {
    int codigo_cliente = cadastrar_cliente(0, "Cliente Teste 2", "End 2", "118888");
    
    int codigo = cadastrar_estadia(0, "01/12/2024", "05/12/2024", codigo_cliente, 9999);
    
    munit_assert_int(codigo, ==, -1);
    
    return MUNIT_OK;
}

// Teste 4: Cadastro com data de saída anterior à entrada
static MunitResult test_cadastrar_estadia_datas_invalidas(const MunitParameter params[], void* fixture) {
    int codigo_cliente = cadastrar_cliente(0, "Cliente Teste 3", "End 3", "117777");
    cadastrar_quarto(203, 2, 150.00);
    
    int codigo = cadastrar_estadia(0, "05/12/2024", "01/12/2024", codigo_cliente, 203);
    
    munit_assert_int(codigo, ==, -1);
    
    return MUNIT_OK;
}

// Teste 5: Finalização de estadia
static MunitResult test_finalizar_estadia(const MunitParameter params[], void* fixture) {
    int codigo_cliente = cadastrar_cliente(0, "Cliente Teste 4", "End 4", "116666");
    cadastrar_quarto(204, 2, 150.00);
    int codigo_estadia = cadastrar_estadia(0, "01/12/2024", "05/12/2024", codigo_cliente, 204);
    
    int resultado = finalizar_estadia(codigo_estadia);
    munit_assert_true(resultado);
    
    Estadia estadia;
    pesquisar_estadia_por_codigo(codigo_estadia, &estadia);
    munit_assert_int(estadia.finalizada, ==, 1);
    
    return MUNIT_OK;
}

// Teste 6: Cálculo de pontos de fidelidade
static MunitResult test_calcular_pontos_fidelidade(const MunitParameter params[], void* fixture) {
    int codigo_cliente = cadastrar_cliente(0, "Cliente Fidelidade", "End 5", "115555");
    cadastrar_quarto(205, 2, 100.00);
    
    // Cadastra estadias
    cadastrar_estadia(0, "01/01/2024", "11/01/2024", codigo_cliente, 205);
    finalizar_estadia(1);
    
    int pontos = calcular_pontos_fidelidade(codigo_cliente);
    munit_assert_int(pontos, ==, 10); // 10 diárias
    
    return MUNIT_OK;
}

static MunitTest estadia_tests[] = {
    { "/cadastrar_valida", test_cadastrar_estadia_valida, test_setup, test_teardown, MUNIT_TEST_OPTION_NONE, NULL },
    { "/cadastrar_cliente_invalido", test_cadastrar_estadia_cliente_invalido, test_setup, test_teardown, MUNIT_TEST_OPTION_NONE, NULL },
    { "/cadastrar_quarto_invalido", test_cadastrar_estadia_quarto_invalido, test_setup, test_teardown, MUNIT_TEST_OPTION_NONE, NULL },
    { "/cadastrar_datas_invalidas", test_cadastrar_estadia_datas_invalidas, test_setup, test_teardown, MUNIT_TEST_OPTION_NONE, NULL },
    { "/finalizar_estadia", test_finalizar_estadia, test_setup, test_teardown, MUNIT_TEST_OPTION_NONE, NULL },
    { "/calcular_pontos_fidelidade", test_calcular_pontos_fidelidade, test_setup, test_teardown, MUNIT_TEST_OPTION_NONE, NULL },
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static const MunitSuite estadia_suite = {
    "/estadia", estadia_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[]) {
    return munit_run_suite(&estadia_suite);
}
