#define MUNIT_ENABLE_ASSERT_ALIASES
#define MUNIT_IMPLEMENTATION
#include "munit.h"
#include "../src/funcionario.h"
#include "../src/structs.h"
#include <stdio.h>

static void* test_setup(const MunitParameter params[], void* user_data) {
    remove("data/funcionarios.dat");
    return NULL;
}

static void test_teardown(void* fixture) {
}

// Teste 1: Cadastro válido de funcionário
static MunitResult test_cadastrar_funcionario_valido(const MunitParameter params[], void* fixture) {
    int codigo = cadastrar_funcionario(0, "José Alves", "11999998888", "Recepcionista", 2500.00);
    
    munit_assert_int(codigo, >, 0);
    
    Funcionario funcionario;
    int encontrado = pesquisar_funcionario_por_codigo(codigo, &funcionario);
    munit_assert_true(encontrado);
    munit_assert_string_equal(funcionario.nome, "José Alves");
    munit_assert_string_equal(funcionario.cargo, "Recepcionista");
    munit_assert_float(funcionario.salario, ==, 2500.00);
    
    return MUNIT_OK;
}

// Teste 2: Cadastro com salário inválido
static MunitResult test_cadastrar_funcionario_salario_invalido(const MunitParameter params[], void* fixture) {
    int codigo = cadastrar_funcionario(0, "Pedro Lima", "11888887777", "Gerente", -1000.00);
    
    munit_assert_int(codigo, ==, -1);
    
    return MUNIT_OK;
}

// Teste 3: Cadastro com nome vazio
static MunitResult test_cadastrar_funcionario_nome_vazio(const MunitParameter params[], void* fixture) {
    int codigo = cadastrar_funcionario(0, "", "11777776666", "Camareira", 1800.00);
    
    munit_assert_int(codigo, ==, -1);
    
    return MUNIT_OK;
}

// Teste 4: Pesquisa por código existente
static MunitResult test_pesquisar_funcionario_existente(const MunitParameter params[], void* fixture) {
    int codigo = cadastrar_funcionario(0, "Lucia Ferreira", "11666665555", "Gerente", 4500.00);
    
    Funcionario funcionario;
    int encontrado = pesquisar_funcionario_por_codigo(codigo, &funcionario);
    
    munit_assert_true(encontrado);
    munit_assert_int(funcionario.codigo, ==, codigo);
    
    return MUNIT_OK;
}

// Teste 5: Pesquisa por código inexistente
static MunitResult test_pesquisar_funcionario_inexistente(const MunitParameter params[], void* fixture) {
    Funcionario funcionario;
    int encontrado = pesquisar_funcionario_por_codigo(9999, &funcionario);
    
    munit_assert_false(encontrado);
    
    return MUNIT_OK;
}

static MunitTest funcionario_tests[] = {
    { "/cadastrar_valido", test_cadastrar_funcionario_valido, test_setup, test_teardown, MUNIT_TEST_OPTION_NONE, NULL },
    { "/cadastrar_salario_invalido", test_cadastrar_funcionario_salario_invalido, test_setup, test_teardown, MUNIT_TEST_OPTION_NONE, NULL },
    { "/cadastrar_nome_vazio", test_cadastrar_funcionario_nome_vazio, test_setup, test_teardown, MUNIT_TEST_OPTION_NONE, NULL },
    { "/pesquisar_existente", test_pesquisar_funcionario_existente, test_setup, test_teardown, MUNIT_TEST_OPTION_NONE, NULL },
    { "/pesquisar_inexistente", test_pesquisar_funcionario_inexistente, test_setup, test_teardown, MUNIT_TEST_OPTION_NONE, NULL },
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static const MunitSuite funcionario_suite = {
    "/funcionario", funcionario_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[]) {
    return munit_run_suite(&funcionario_suite);
}
