# Sistema Hotel Descanso Garantido

**Autor:** Lucas Cardoso  
**Curso:** Bacharelado em Engenharia de Software  
**Instituição:** Pontifícia Universidade Católica de Minas Gerais  
**Disciplinas:** Fundamentos de Engenharia de Software e Algoritmos e Estruturas de Dados I

Sistema de gerenciamento para o Hotel Descanso Garantido, desenvolvido em C como trabalho interdisciplinar das disciplinas de Fundamentos de Engenharia de Software e Algoritmos e Estruturas de Dados I.

## 📋 Descrição

O sistema permite gerenciar clientes, funcionários, quartos e estadias de um hotel, utilizando arquivos binários para persistência de dados.

## 🚀 Funcionalidades

### Módulo de Clientes
- ✅ Cadastro de clientes com geração automática de código
- ✅ Pesquisa por código ou nome
- ✅ Listagem de todos os clientes
- ✅ Validação de duplicidade de códigos

### Módulo de Funcionários
- ✅ Cadastro de funcionários com geração automática de código
- ✅ Pesquisa por código ou nome
- ✅ Listagem de todos os funcionários
- ✅ Validação de duplicidade de códigos

### Módulo de Quartos
- ✅ Cadastro de quartos com número único
- ✅ Controle de capacidade de hóspedes
- ✅ Controle de status (ocupado/desocupado)
- ✅ Gerenciamento de valores de diárias
- ✅ Listagem de todos os quartos

### Módulo de Estadias
- ✅ Cadastro de estadias com alocação automática de quartos
- ✅ Validação de disponibilidade do quarto no período
- ✅ Cálculo automático de quantidade de diárias
- ✅ Dar baixa em estadia com cálculo do valor total
- ✅ Listagem de estadias por cliente
- ✅ Cálculo de pontos de fidelidade (10 pontos por diária)
- ✅ Validação de datas e períodos

## 🛠️ Tecnologias Utilizadas

- **Linguagem**: C (padrão C99)
- **Compilador**: GCC
- **Estruturas de Dados**: Structs, arquivos binários
- **Metodologia**: Scrum (desenvolvimento em sprints)

## 📁 Estrutura do Projeto

\`\`\`
hotel-descanso-garantido/
├── src/
│   ├── main.c              # Programa principal com menu
│   ├── structs.h           # Definição das estruturas de dados
│   ├── cliente.h/.c        # Módulo de clientes
│   ├── funcionario.h/.c    # Módulo de funcionários
│   ├── quarto.h/.c         # Módulo de quartos
│   ├── estadia.h/.c        # Módulo de estadias
│   └── utils.h/.c          # Funções utilitárias
├── data/                   # Arquivos de dados (gerado automaticamente)
├── obj/                    # Arquivos objeto (gerado na compilação)
├── bin/                    # Executável (gerado na compilação)
├── docs/                   # Documentação do projeto
├── Makefile               # Automatização da compilação
└── README.md              # Este arquivo
\`\`\`

## 🔧 Compilação e Execução

### Usando Makefile (Recomendado)

\`\`\`bash
# Compilar o projeto
make

# Compilar e executar
make run

# Limpar arquivos de compilação
make clean

# Limpar tudo (incluindo dados)
make cleanall
\`\`\`

### Compilação Manual

\`\`\`bash
# Criar diretórios
mkdir -p obj bin data

# Compilar
gcc -Wall -Wextra -std=c99 -I./src -c src/utils.c -o obj/utils.o
gcc -Wall -Wextra -std=c99 -I./src -c src/cliente.c -o obj/cliente.o
gcc -Wall -Wextra -std=c99 -I./src -c src/funcionario.c -o obj/funcionario.o
gcc -Wall -Wextra -std=c99 -I./src -c src/quarto.c -o obj/quarto.o
gcc -Wall -Wextra -std=c99 -I./src -c src/estadia.c -o obj/estadia.o
gcc -Wall -Wextra -std=c99 -I./src -c src/main.c -o obj/main.o

# Linkar
gcc obj/*.o -o bin/hotel

# Executar
./bin/hotel
\`\`\`

## 📊 Persistência de Dados

O sistema utiliza arquivos binários para armazenar os dados:

- `data/clientes.dat` - Dados dos clientes
- `data/funcionarios.dat` - Dados dos funcionários
- `data/quartos.dat` - Dados dos quartos
- `data/estadias.dat` - Dados das estadias

## 🎯 Regras de Negócio

1. **Clientes e Quartos**: Devem estar cadastrados antes de criar uma estadia
2. **Códigos Únicos**: Não permite duplicação de códigos de clientes/funcionários
3. **Números Únicos**: Não permite duplicação de números de quartos
4. **Disponibilidade**: Estadias só podem ser criadas para quartos desocupados
5. **Datas**: Data de saída deve ser posterior à data de entrada
6. **Sobreposição**: Não permite estadias com períodos sobrepostos para o mesmo quarto
7. **Pontos de Fidelidade**: Cliente ganha 10 pontos por diária
8. **Status do Quarto**: Atualizado automaticamente ao criar/finalizar estadias

## 👥 Desenvolvimento

### Metodologia Scrum

O projeto foi desenvolvido seguindo a metodologia Scrum com:
- **Sprints**: 3-4 dias cada
- **Backlog do Produto**: Organizado por funcionalidades
- **Tarefas**: Distribuídas entre os membros do grupo
- **Documentação**: Evoluída a cada sprint

### Divisão de Módulos

Cada módulo (cliente, funcionário, quarto, estadia) foi desenvolvido como biblioteca independente com:
- Assinaturas de funções bem definidas
- Documentação de propósito e parâmetros
- Casos de teste planejados
- Implementação incremental (sucesso → exceções)

## 📝 Documentação Adicional

Consulte a pasta `docs/` para:
- Backlog do produto e evolução por sprint
- Documentação completa das funções
- Casos de teste e relatórios de execução
- Diagramas e especificações

## ⚠️ Observações

- O sistema utiliza formato de data DD/MM/AAAA
- Valores monetários em Reais (R$)
- Todas as validações são realizadas antes das operações
- Mensagens de erro são exibidas quando há problemas

## 📧 Suporte

**Desenvolvedor:** Lucas Cardoso  
**Professores:**
- **FES**: Ivan Araújo
- **AED I**: Lucca S P Lacerda

---

**Pontifícia Universidade Católica de Minas Gerais**  
**Instituto de Ciências Exatas e Informática**  
**Bacharelado em Engenharia de Software**
