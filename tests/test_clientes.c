#define MUNIT_ENABLE_ASSERT_ALIASES
#define MUNIT_IMPLEMENTATION
#include "munit.h"
#include "../src/cliente.h"
#include "../src/structs.h"
#include <stdio.h>
#include <string.h>

static void* test_setup(const MunitParameter params[], void* user_data) {
    // Remove arquivo de teste anterior
    remove("data/clientes.dat");
    return NULL;
}

static void test_teardown(void* fixture) {
    // Limpeza se necessário
}

// Teste 1: Cadastro válido de cliente
static MunitResult test_cadastrar_cliente_valido(const MunitParameter params[], void* fixture) {
    int codigo = cadastrar_cliente(0, "João Silva", "Rua A, 123", "11999999999");
    
    munit_assert_int(codigo, >, 0);
    
    Cliente cliente;
    int encontrado = pesquisar_cliente_por_codigo(codigo, &cliente);
    munit_assert_true(encontrado);
    munit_assert_string_equal(cliente.nome, "João Silva");
    munit_assert_string_equal(cliente.endereco, "Rua A, 123");
    munit_assert_string_equal(cliente.telefone, "11999999999");
    
    return MUNIT_OK;
}

// Teste 2: Cadastro com nome vazio (deve falhar)
static MunitResult test_cadastrar_cliente_nome_vazio(const MunitParameter params[], void* fixture) {
    int codigo = cadastrar_cliente(0, "", "Rua B, 456", "11988888888");
    
    munit_assert_int(codigo, ==, -1);
    
    return MUNIT_OK;
}

// Teste 3: Cadastro com código duplicado (deve falhar)
static MunitResult test_cadastrar_cliente_codigo_duplicado(const MunitParameter params[], void* fixture) {
    cadastrar_cliente(100, "Maria Santos", "Rua C, 789", "11977777777");
    int codigo2 = cadastrar_cliente(100, "Pedro Costa", "Rua D, 321", "11966666666");
    
    munit_assert_int(codigo2, ==, -1);
    
    return MUNIT_OK;
}

// Teste 4: Pesquisa por código existente
static MunitResult test_pesquisar_cliente_existente(const MunitParameter params[], void* fixture) {
    int codigo = cadastrar_cliente(0, "Ana Oliveira", "Rua E, 555", "11955555555");
    
    Cliente cliente;
    int encontrado = pesquisar_cliente_por_codigo(codigo, &cliente);
    
    munit_assert_true(encontrado);
    munit_assert_int(cliente.codigo, ==, codigo);
    munit_assert_string_equal(cliente.nome, "Ana Oliveira");
    
    return MUNIT_OK;
}

// Teste 5: Pesquisa por código inexistente
static MunitResult test_pesquisar_cliente_inexistente(const MunitParameter params[], void* fixture) {
    Cliente cliente;
    int encontrado = pesquisar_cliente_por_codigo(9999, &cliente);
    
    munit_assert_false(encontrado);
    
    return MUNIT_OK;
}

// Teste 6: Pesquisa por nome parcial
static MunitResult test_pesquisar_cliente_por_nome(const MunitParameter params[], void* fixture) {
    cadastrar_cliente(0, "Carlos Silva", "Rua F, 111", "11944444444");
    cadastrar_cliente(0, "Carlos Santos", "Rua G, 222", "11933333333");
    
    // Este teste apenas verifica que não há crash
    // A função pesquisar_cliente_por_nome imprime na tela
    pesquisar_cliente_por_nome("Carlos");
    
    return MUNIT_OK;
}

// Teste 7: Geração automática de código
static MunitResult test_gerar_codigo_automatico(const MunitParameter params[], void* fixture) {
    int codigo1 = cadastrar_cliente(0, "Cliente 1", "End 1", "111");
    int codigo2 = cadastrar_cliente(0, "Cliente 2", "End 2", "222");
    int codigo3 = cadastrar_cliente(0, "Cliente 3", "End 3", "333");
    
    munit_assert_int(codigo2, ==, codigo1 + 1);
    munit_assert_int(codigo3, ==, codigo2 + 1);
    
    return MUNIT_OK;
}

// Definição dos testes
static MunitTest cliente_tests[] = {
    { "/cadastrar_valido", test_cadastrar_cliente_valido, test_setup, test_teardown, MUNIT_TEST_OPTION_NONE, NULL },
    { "/cadastrar_nome_vazio", test_cadastrar_cliente_nome_vazio, test_setup, test_teardown, MUNIT_TEST_OPTION_NONE, NULL },
    { "/cadastrar_codigo_duplicado", test_cadastrar_cliente_codigo_duplicado, test_setup, test_teardown, MUNIT_TEST_OPTION_NONE, NULL },
    { "/pesquisar_existente", test_pesquisar_cliente_existente, test_setup, test_teardown, MUNIT_TEST_OPTION_NONE, NULL },
    { "/pesquisar_inexistente", test_pesquisar_cliente_inexistente, test_setup, test_teardown, MUNIT_TEST_OPTION_NONE, NULL },
    { "/pesquisar_por_nome", test_pesquisar_cliente_por_nome, test_setup, test_teardown, MUNIT_TEST_OPTION_NONE, NULL },
    { "/gerar_codigo_automatico", test_gerar_codigo_automatico, test_setup, test_teardown, MUNIT_TEST_OPTION_NONE, NULL },
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static const MunitSuite cliente_suite = {
    "/cliente", cliente_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[]) {
    return munit_run_suite(&cliente_suite);
}
