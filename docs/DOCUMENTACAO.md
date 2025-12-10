# Documentação do Sistema Hotel Descanso Garantido

**Autor:** Lucas Cardoso  
**Instituição:** PUC Minas - Engenharia de Software  
**Disciplinas:** Fundamentos de Engenharia de Software e Algoritmos e Estruturas de Dados I  
**Professores:** Ivan Araújo (FES) e Lucca S P Lacerda (AED I)

## 1. Apresentação

O **Sistema Hotel Descanso Garantido** é uma solução de software desenvolvida para automatizar e gerenciar as operações do Hotel Descanso Garantido, localizado em Itacaré - BA. O sistema substitui controles manuais em planilhas e cadernos, eliminando problemas como reservas duplicadas e perda de informações.

### Objetivo

Desenvolver um sistema robusto em linguagem C que permita:
- Cadastramento eficiente de clientes, funcionários, quartos e estadias
- Controle preciso de disponibilidade de quartos
- Gestão automatizada de reservas e check-outs
- Programa de fidelidade para retenção de clientes
- Persistência de dados em arquivos binários

## 2. Backlog do Produto

### Sprint 0 - Planejamento (3 dias)
**Data**: 04/11/2025 - 06/11/2025

**Tarefas Realizadas:**
- ✅ Análise dos requisitos do sistema
- ✅ Definição da arquitetura modular
- ✅ Criação das estruturas de dados principais
- ✅ Planejamento do backlog e divisão de tarefas
- ✅ Configuração do ambiente de desenvolvimento
- ✅ Criação do repositório Git

**Responsável**: Equipe completa

---

### Sprint 1 - Módulos Básicos (4 dias)
**Data**: 07/11/2025 - 10/11/2025

**Tarefas**:
1. ✅ **Módulo de Estruturas e Utilitários** - Responsável: Membro 1
   - Definição de structs (Cliente, Funcionario, Quarto, Estadia)
   - Funções utilitárias (validação de data, cálculo de diárias)
   - Funções de manipulação de arquivos

2. ✅ **Módulo de Clientes** - Responsável: Membro 2
   - Função de cadastro com validação
   - Geração automática de código
   - Pesquisa por código e nome
   - Listagem de clientes

3. ✅ **Módulo de Funcionários** - Responsável: Membro 3
   - Função de cadastro com validação
   - Geração automática de código
   - Pesquisa por código e nome
   - Listagem de funcionários

**Entregas**:
- Estruturas de dados definidas
- Três módulos funcionais com testes básicos
- Documentação de assinaturas das funções

---

### Sprint 2 - Módulo de Quartos (4 dias)
**Data**: 11/11/2025 - 14/11/2025

**Tarefas**:
1. ✅ **Cadastro e Gestão de Quartos** - Responsável: Membro 1
   - Função de cadastro de quartos
   - Validação de números únicos
   - Controle de status (ocupado/desocupado)
   - Listagem de quartos

2. ✅ **Busca de Quartos Disponíveis** - Responsável: Membro 2
   - Algoritmo de busca por capacidade
   - Verificação de disponibilidade por período
   - Integração com módulo de estadias

**Entregas**:
- Módulo de quartos completo
- Funções de busca e alocação
- Testes de disponibilidade

---

### Sprint 3 - Módulo de Estadias (4 dias)
**Data**: 15/11/2025 - 18/11/2025

**Tarefas**:
1. ✅ **Cadastro de Estadias** - Responsável: Membro 3
   - Função de cadastro com validações completas
   - Alocação automática de quartos
   - Cálculo de quantidade de diárias
   - Validação de datas e períodos

2. ✅ **Finalização de Estadias** - Responsável: Membro 1
   - Função de baixa em estadia
   - Cálculo de valor total
   - Atualização de status do quarto
   - Geração de comprovante

3. ✅ **Consultas de Estadias** - Responsável: Membro 2
   - Listagem de estadias por cliente
   - Verificação de sobreposição de datas
   - Consultas gerais

**Entregas**:
- Módulo de estadias completo
- Sistema de reservas funcional
- Validações de regras de negócio

---

### Sprint 4 - Funcionalidades Avançadas e Interface (4 dias)
**Data**: 19/11/2025 - 22/11/2025

**Tarefas**:
1. ✅ **Programa de Fidelidade** - Responsável: Membro 3
   - Cálculo de pontos de fidelidade
   - Relatório de pontos por cliente
   - Integração com estadias

2. ✅ **Interface do Usuário** - Responsável: Membro 2
   - Menu principal interativo
   - Submenus para cada funcionalidade
   - Mensagens de erro e sucesso
   - Formatação e usabilidade

3. ✅ **Integração Final** - Responsável: Membro 1
   - Integração de todos os módulos
   - Testes de fluxo completo
   - Correção de bugs

**Entregas**:
- Sistema completo e funcional
- Interface amigável
- Programa de fidelidade implementado

---

### Sprint 5 - Testes e Documentação (3 dias)
**Data**: 23/11/2025 - 25/11/2025

**Tarefas**:
1. ✅ **Casos de Teste** - Responsável: Equipe completa
   - Planejamento de casos de teste
   - Execução manual de testes
   - Relatórios de execução

2. ✅ **Documentação** - Responsável: Equipe completa
   - Documentação de funções
   - Manual do usuário
   - Relatório técnico
   - README do projeto

3. ✅ **Preparação de Dados de Teste** - Responsável: Membro 1
   - Criação de arquivos com dados de exemplo
   - Cenários de teste completos

**Entregas**:
- Casos de teste documentados
- Relatórios de execução
- Documentação completa

---

### Sprint 6 - Apresentação Final (2 dias)
**Data**: 26/11/2025 - 27/11/2025

**Tarefas**:
1. ✅ **Gravação da Apresentação** - Responsável: Equipe completa
   - Roteiro de apresentação
   - Demonstração de funcionalidades
   - Gravação do vídeo (pitch)
   - Edição final

2. ✅ **Entrega Final** - Responsável: Equipe completa
   - Organização de todos os arquivos
   - Verificação de requisitos
   - Upload no Canvas

**Entregas**:
- Vídeo de apresentação
- Projeto completo no Git
- Entrega no Canvas

---

## 3. Evolução do Backlog

### Estado Inicial (Sprint 0)

| ID | Tarefa | Responsável | Status | Sprint |
|----|--------|-------------|--------|--------|
| 1 | Estruturas de dados | Membro 1 | 🔴 A fazer | 1 |
| 2 | Módulo de Clientes | Membro 2 | 🔴 A fazer | 1 |
| 3 | Módulo de Funcionários | Membro 3 | 🔴 A fazer | 1 |
| 4 | Módulo de Quartos | Membro 1 | 🔴 A fazer | 2 |
| 5 | Busca de Quartos | Membro 2 | 🔴 A fazer | 2 |
| 6 | Cadastro de Estadias | Membro 3 | 🔴 A fazer | 3 |
| 7 | Finalização de Estadias | Membro 1 | 🔴 A fazer | 3 |
| 8 | Consultas de Estadias | Membro 2 | 🔴 A fazer | 3 |
| 9 | Programa de Fidelidade | Membro 3 | 🔴 A fazer | 4 |
| 10 | Interface do Usuário | Membro 2 | 🔴 A fazer | 4 |
| 11 | Integração Final | Membro 1 | 🔴 A fazer | 4 |
| 12 | Testes e Documentação | Equipe | 🔴 A fazer | 5 |
| 13 | Apresentação | Equipe | 🔴 A fazer | 6 |

### Estado Final (Após Sprint 6)

| ID | Tarefa | Responsável | Status | Sprint |
|----|--------|-------------|--------|--------|
| 1 | Estruturas de dados | Membro 1 | ✅ Concluído | 1 |
| 2 | Módulo de Clientes | Membro 2 | ✅ Concluído | 1 |
| 3 | Módulo de Funcionários | Membro 3 | ✅ Concluído | 1 |
| 4 | Módulo de Quartos | Membro 1 | ✅ Concluído | 2 |
| 5 | Busca de Quartos | Membro 2 | ✅ Concluído | 2 |
| 6 | Cadastro de Estadias | Membro 3 | ✅ Concluído | 3 |
| 7 | Finalização de Estadias | Membro 1 | ✅ Concluído | 3 |
| 8 | Consultas de Estadias | Membro 2 | ✅ Concluído | 3 |
| 9 | Programa de Fidelidade | Membro 3 | ✅ Concluído | 4 |
| 10 | Interface do Usuário | Membro 2 | ✅ Concluído | 4 |
| 11 | Integração Final | Membro 1 | ✅ Concluído | 4 |
| 12 | Testes e Documentação | Equipe | ✅ Concluído | 5 |
| 13 | Apresentação | Equipe | ✅ Concluído | 6 |

---

## 4. Arquitetura do Sistema

### Organização Modular

O sistema foi desenvolvido seguindo o paradigma de programação estruturada com organização modular:

\`\`\`
Sistema Hotel Descanso Garantido
│
├── Módulo de Estruturas (structs.h)
│   └── Definições de tipos de dados
│
├── Módulo de Utilitários (utils.h/.c)
│   ├── Validação de datas
│   ├── Cálculos de período
│   ├── Manipulação de strings
│   └── Funções auxiliares
│
├── Módulo de Clientes (cliente.h/.c)
│   ├── Cadastro
│   ├── Pesquisa
│   └── Listagem
│
├── Módulo de Funcionários (funcionario.h/.c)
│   ├── Cadastro
│   ├── Pesquisa
│   └── Listagem
│
├── Módulo de Quartos (quarto.h/.c)
│   ├── Cadastro
│   ├── Busca por disponibilidade
│   ├── Atualização de status
│   └── Listagem
│
├── Módulo de Estadias (estadia.h/.c)
│   ├── Cadastro
│   ├── Finalização
│   ├── Consultas
│   └── Cálculo de pontos
│
└── Programa Principal (main.c)
    ├── Menu interativo
    └── Integração de módulos
\`\`\`

### Persistência de Dados

Arquivos binários são utilizados para armazenar dados de forma eficiente:
- Leitura e escrita direta de estruturas
- Acesso rápido aos registros
- Menor uso de espaço em disco
- Portabilidade entre sistemas

---

*Continua na próxima seção...*
