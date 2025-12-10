CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -I./src -I./tests
SRCDIR = src
OBJDIR = obj
BINDIR = bin
DATADIR = data
TESTDIR = tests
SCRIPTSDIR = scripts

# Arquivos fonte principais
SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SOURCES))
EXECUTABLE = $(BINDIR)/hotel

# Arquivos de teste
TEST_SOURCES = $(wildcard $(TESTDIR)/test_*.c)
TEST_EXECUTABLES = $(patsubst $(TESTDIR)/%.c,$(BINDIR)/%,$(TEST_SOURCES))

# Script de geração de dados
SCRIPT_GERAR_DADOS = $(SCRIPTSDIR)/gerar_dados_teste.c
EXEC_GERAR_DADOS = $(BINDIR)/gerar_dados_teste

# Regra principal
all: dirs $(EXECUTABLE)

# Cria diretórios necessários
dirs:
	@mkdir -p $(OBJDIR) $(BINDIR) $(DATADIR)

# Regra para criar o executável principal
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@
	@echo "✓ Compilação do sistema concluída com sucesso!"

# Regra para compilar arquivos objeto
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compila o script de geração de dados
$(EXEC_GERAR_DADOS): $(SCRIPT_GERAR_DADOS) $(filter-out $(OBJDIR)/main.o, $(OBJECTS))
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $^ -o $@
	@echo "✓ Script de geração de dados compilado!"

# Gera dados de teste pré-preenchidos
generate-data: dirs $(EXEC_GERAR_DADOS)
	@echo ""
	@echo "Gerando dados de teste..."
	@./$(EXEC_GERAR_DADOS)

# Compila os testes
compile-tests: dirs $(TEST_EXECUTABLES)
	@echo "✓ Todos os testes compilados com sucesso!"

$(BINDIR)/test_%: $(TESTDIR)/test_%.c $(filter-out $(OBJDIR)/main.o, $(OBJECTS))
	$(CC) $(CFLAGS) $^ -o $@

# Executa todos os testes automatizados
tests: compile-tests
	@echo ""
	@echo "================================================================================"
	@echo "  EXECUTANDO BATERIA COMPLETA DE TESTES AUTOMATIZADOS"
	@echo "================================================================================"
	@for test in $(TEST_EXECUTABLES); do \
		$$test || exit 1; \
	done
	@echo ""
	@echo "================================================================================"
	@echo "  ✓ TODOS OS TESTES PASSARAM COM SUCESSO!"
	@echo "================================================================================"
	@echo ""

# Executa teste específico
test-clientes: $(BINDIR)/test_clientes
	@./$(BINDIR)/test_clientes

test-funcionarios: $(BINDIR)/test_funcionarios
	@./$(BINDIR)/test_funcionarios

test-quartos: $(BINDIR)/test_quartos
	@./$(BINDIR)/test_quartos

test-estadias: $(BINDIR)/test_estadias
	@./$(BINDIR)/test_estadias

# Limpa arquivos gerados
clean:
	rm -rf $(OBJDIR) $(BINDIR)
	@echo "✓ Arquivos de compilação removidos!"

# Limpa também os dados
cleanall: clean
	rm -rf $(DATADIR)
	@echo "✓ Todos os arquivos gerados removidos!"

# Executa o programa
run: all
	./$(EXECUTABLE)

# Setup completo: compila tudo e gera dados de teste
setup: all generate-data
	@echo ""
	@echo "================================================================================"
	@echo "  ✓ SETUP COMPLETO FINALIZADO!"
	@echo "================================================================================"
	@echo "  O sistema está pronto para uso com dados de teste pré-carregados."
	@echo "  Execute: make run"
	@echo "================================================================================"
	@echo ""

# Regras que não são arquivos
.PHONY: all dirs clean cleanall run tests compile-tests test-clientes test-funcionarios test-quartos test-estadias generate-data setup
