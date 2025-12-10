Sistema Hotel Descanso Garantido

Autor: Lucas Cardoso
Curso: Bacharelado em Engenharia de Software
Instituicao: Pontificia Universidade Catolica de Minas Gerais
Disciplinas: Fundamentos de Engenharia de Software e Algoritmos e Estruturas de Dados I

Sistema de gerenciamento para o Hotel Descanso Garantido, desenvolvido em C 
como trabalho interdisciplinar das disciplinas de Fundamentos de Engenharia 
de Software e Algoritmos e Estruturas de Dados I.

================================================================================

DESCRICAO

O sistema permite gerenciar clientes, funcionarios, quartos e estadias de um 
hotel, utilizando arquivos binarios para persistencia de dados.

================================================================================

FUNCIONALIDADES

Modulo de Clientes
- Cadastro de clientes com geracao automatica de codigo
- Pesquisa por codigo ou nome
- Listagem de todos os clientes
- Validacao de duplicidade de codigos

Modulo de Funcionarios
- Cadastro de funcionarios com geracao automatica de codigo
- Pesquisa por codigo ou nome
- Listagem de todos os funcionarios
- Validacao de duplicidade de codigos

Modulo de Quartos
- Cadastro de quartos com numero unico
- Controle de capacidade de hospedes
- Controle de status (ocupado/desocupado)
- Gerenciamento de valores de diarias
- Listagem de todos os quartos

Modulo de Estadias
- Cadastro de estadias com alocacao automatica de quartos
- Validacao de disponibilidade do quarto no periodo
- Calculo automatico de quantidade de diarias
- Dar baixa em estadia com calculo do valor total
- Listagem de estadias por cliente
- Calculo de pontos de fidelidade (10 pontos por diaria)
- Validacao de datas e periodos

================================================================================

TECNOLOGIAS UTILIZADAS

- Linguagem: C (padrao C99)
- Compilador: GCC
- Estruturas de Dados: Structs, arquivos binarios
- Metodologia: Scrum (desenvolvimento em sprints)

================================================================================

ESTRUTURA DO PROJETO

hotel-descanso-garantido/
  src/
    main.c              Programa principal com menu
    structs.h           Definicao das estruturas de dados
    cliente.h/.c        Modulo de clientes
    funcionario.h/.c    Modulo de funcionarios
    quarto.h/.c         Modulo de quartos
    estadia.h/.c        Modulo de estadias
    utils.h/.c          Funcoes utilitarias
  data/                 Arquivos de dados (gerado automaticamente)
  obj/                  Arquivos objeto (gerado na compilacao)
  bin/                  Executavel (gerado na compilacao)
  docs/                 Documentacao do projeto
  Makefile              Automatizacao da compilacao
  README.txt            Este arquivo

================================================================================

COMPILACAO E EXECUCAO

Usando Makefile (Recomendado)

  Compilar o projeto:
  make

  Compilar e executar:
  make run

  Limpar arquivos de compilacao:
  make clean

  Limpar tudo (incluindo dados):
  make cleanall

Compilacao Manual

  Criar diretorios:
  mkdir -p obj bin data

  Compilar:
  gcc -Wall -Wextra -std=c99 -I./src -c src/utils.c -o obj/utils.o
  gcc -Wall -Wextra -std=c99 -I./src -c src/cliente.c -o obj/cliente.o
  gcc -Wall -Wextra -std=c99 -I./src -c src/funcionario.c -o obj/funcionario.o
  gcc -Wall -Wextra -std=c99 -I./src -c src/quarto.c -o obj/quarto.o
  gcc -Wall -Wextra -std=c99 -I./src -c src/estadia.c -o obj/estadia.o
  gcc -Wall -Wextra -std=c99 -I./src -c src/main.c -o obj/main.o

  Linkar:
  gcc obj/*.o -o bin/hotel

  Executar:
  ./bin/hotel

================================================================================

PERSISTENCIA DE DADOS

O sistema utiliza arquivos binarios para armazenar os dados:

- data/clientes.dat - Dados dos clientes
- data/funcionarios.dat - Dados dos funcionarios
- data/quartos.dat - Dados dos quartos
- data/estadias.dat - Dados das estadias

================================================================================

REGRAS DE NEGOCIO

1. Clientes e Quartos: Devem estar cadastrados antes de criar uma estadia
2. Codigos Unicos: Nao permite duplicacao de codigos de clientes/funcionarios
3. Numeros Unicos: Nao permite duplicacao de numeros de quartos
4. Disponibilidade: Estadias so podem ser criadas para quartos desocupados
5. Datas: Data de saida deve ser posterior a data de entrada
6. Sobreposicao: Nao permite estadias com periodos sobrepostos para o mesmo quarto
7. Pontos de Fidelidade: Cliente ganha 10 pontos por diaria
8. Status do Quarto: Atualizado automaticamente ao criar/finalizar estadias

================================================================================

DESENVOLVIMENTO

Metodologia Scrum

O projeto foi desenvolvido seguindo a metodologia Scrum com:
- Sprints: 3-4 dias cada
- Backlog do Produto: Organizado por funcionalidades
- Tarefas: Distribuidas entre os membros do grupo
- Documentacao: Evoluida a cada sprint

Divisao de Modulos

Cada modulo (cliente, funcionario, quarto, estadia) foi desenvolvido como 
biblioteca independente com:
- Assinaturas de funcoes bem definidas
- Documentacao de proposito e parametros
- Casos de teste planejados
- Implementacao incremental (sucesso → excecoes)

================================================================================

DOCUMENTACAO ADICIONAL

Consulte a pasta docs/ para:
- Backlog do produto e evolucao por sprint
- Documentacao completa das funcoes
- Casos de teste e relatorios de execucao
- Diagramas e especificacoes

================================================================================

OBSERVACOES

- O sistema utiliza formato de data DD/MM/AAAA
- Valores monetarios em Reais (R$)
- Todas as validacoes sao realizadas antes das operacoes
- Mensagens de erro sao exibidas quando ha problemas

================================================================================

SUPORTE

Desenvolvedor: Lucas Cardoso

Professores:
- FES: Ivan Araujo
- AED I: Lucca S P Lacerda

================================================================================

Pontificia Universidade Catolica de Minas Gerais
Instituto de Ciencias Exatas e Informatica
Bacharelado em Engenharia de Software
