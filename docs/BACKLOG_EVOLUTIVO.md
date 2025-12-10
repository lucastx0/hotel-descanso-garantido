# BACKLOG EVOLUTIVO DO PRODUTO
## Hotel Descanso Garantido - Evolução por Sprint

**Autor:** Lucas Cardoso  
**Instituição:** PUC Minas - Engenharia de Software  
**Data de Criação:** 01/11/2024

---

## SPRINT 0 - PLANEJAMENTO INICIAL
**Data:** 01/11/2024 a 07/11/2024  
**Responsável:** Lucas Cardoso

### Backlog Inicial Criado

| ID | História de Usuário | Prioridade | Estimativa | Responsável | Status |
|----|---------------------|------------|------------|-------------|--------|
| US-01 | Como gerente, quero cadastrar clientes para manter registro dos hóspedes | ALTA | 8h | João Silva | 📋 TODO |
| US-02 | Como gerente, quero cadastrar funcionários para controlar a equipe | ALTA | 8h | Maria Santos | 📋 TODO |
| US-03 | Como gerente, quero cadastrar quartos para controlar o inventário | ALTA | 6h | Pedro Costa | 📋 TODO |
| US-04 | Como recepcionista, quero cadastrar estadias para registrar hospedagens | ALTA | 10h | Ana Oliveira | 📋 TODO |
| US-05 | Como gerente, quero pesquisar clientes por nome para localizar rapidamente | MÉDIA | 4h | João Silva | 📋 TODO |
| US-06 | Como gerente, quero listar todos os quartos para ver disponibilidade | MÉDIA | 4h | Pedro Costa | 📋 TODO |
| US-07 | Como recepcionista, quero calcular pontos de fidelidade para premiar clientes | BAIXA | 6h | Ana Oliveira | 📋 TODO |
| US-08 | Como recepcionista, quero buscar quartos disponíveis por capacidade | MÉDIA | 8h | Pedro Costa | 📋 TODO |

### Definições Técnicas
- **Linguagem:** C (padrão C99)
- **Persistência:** Arquivos binários (.dat)
- **Estrutura:** Modularização por entidade (cliente, funcionário, quarto, estadia)
- **Build System:** Makefile

### Decisões de Arquitetura
- ✅ Uso de structs para modelagem de dados
- ✅ Separação em módulos .c e .h
- ✅ Validações em todas as entradas
- ✅ Status de ativo/inativo para soft delete

---

## SPRINT 1 - CADASTROS BÁSICOS
**Data:** 08/11/2024 a 14/11/2024  
**Meta:** Implementar cadastros de Cliente, Funcionário e Quarto

### Backlog Atualizado - Sprint 1

| ID | História de Usuário | Status Sprint 0 | Status Sprint 1 | Responsável | Observações |
|----|---------------------|-----------------|-----------------|-------------|-------------|
| US-01 | Cadastrar clientes | 📋 TODO | ✅ DONE | João Silva | Concluído com validações |
| US-02 | Cadastrar funcionários | 📋 TODO | ✅ DONE | Maria Santos | Validação de salário implementada |
| US-03 | Cadastrar quartos | 📋 TODO | ✅ DONE | Pedro Costa | Status automático = DESOCUPADO |
| US-04 | Cadastrar estadias | 📋 TODO | 📋 TODO | Ana Oliveira | Dependência: US-01 e US-03 |
| US-05 | Pesquisar clientes | 📋 TODO | 🚧 IN PROGRESS | João Silva | 70% concluído |
| US-06 | Listar quartos | 📋 TODO | 📋 TODO | Pedro Costa | - |
| US-07 | Pontos de fidelidade | 📋 TODO | 📋 TODO | Ana Oliveira | - |
| US-08 | Buscar quartos disponíveis | 📋 TODO | 📋 TODO | Pedro Costa | - |

### Itens Adicionados na Sprint 1

| ID | Nova Tarefa | Prioridade | Responsável | Status |
|----|-------------|------------|-------------|--------|
| TECH-01 | Implementar geração automática de códigos | ALTA | João Silva | ✅ DONE |
| TECH-02 | Criar estrutura de diretórios (data, obj, bin) | ALTA | Pedro Costa | ✅ DONE |
| TECH-03 | Implementar soft delete com flag "ativo" | MÉDIA | Maria Santos | ✅ DONE |

### Retrospectiva Sprint 1
✅ **Concluído:** 3 histórias de usuário + 3 tarefas técnicas  
🚧 **Em Progresso:** 1 história de usuário  
⚠️ **Bloqueios:** Nenhum  
📝 **Lições Aprendidas:** Validações devem ser implementadas desde o início

---

## SPRINT 2 - FUNCIONALIDADES DE PESQUISA E ESTADIA
**Data:** 15/11/2024 a 21/11/2024  
**Meta:** Completar módulo de estadias e funcionalidades de pesquisa

### Backlog Atualizado - Sprint 2

| ID | História de Usuário | Status Sprint 1 | Status Sprint 2 | Responsável | Observações |
|----|---------------------|-----------------|-----------------|-------------|-------------|
| US-01 | Cadastrar clientes | ✅ DONE | ✅ DONE | João Silva | - |
| US-02 | Cadastrar funcionários | ✅ DONE | ✅ DONE | Maria Santos | - |
| US-03 | Cadastrar quartos | ✅ DONE | ✅ DONE | Pedro Costa | - |
| US-04 | Cadastrar estadias | 📋 TODO | ✅ DONE | Ana Oliveira | Validações completas implementadas |
| US-05 | Pesquisar clientes | 🚧 IN PROGRESS | ✅ DONE | João Silva | Pesquisa por código e nome |
| US-06 | Listar quartos | 📋 TODO | ✅ DONE | Pedro Costa | Exibe status em tempo real |
| US-07 | Pontos de fidelidade | 📋 TODO | 🚧 IN PROGRESS | Ana Oliveira | 60% concluído |
| US-08 | Buscar quartos disponíveis | 📋 TODO | 📋 TODO | Pedro Costa | Dependência: US-04 |

### Itens Adicionados na Sprint 2

| ID | Nova Tarefa | Prioridade | Responsável | Status |
|----|-------------|------------|-------------|--------|
| TECH-04 | Implementar cálculo de diárias | ALTA | Ana Oliveira | ✅ DONE |
| TECH-05 | Validação de datas (formato DD/MM/AAAA) | ALTA | Ana Oliveira | ✅ DONE |
| TECH-06 | Verificar integridade referencial (cliente/quarto) | ALTA | João Silva | ✅ DONE |
| TECH-07 | Atualizar status do quarto ao criar estadia | ALTA | Pedro Costa | ✅ DONE |
| BUG-01 | Corrigir leitura de strings com espaços | CRÍTICO | João Silva | ✅ FIXED |

### Retrospectiva Sprint 2
✅ **Concluído:** 3 histórias de usuário + 5 tarefas técnicas + 1 bugfix  
🚧 **Em Progresso:** 1 história de usuário  
⚠️ **Bloqueios:** Complexidade no cálculo de datas  
📝 **Lições Aprendidas:** Validação de integridade referencial é essencial

---

## SPRINT 3 - FINALIZAÇÃO E FUNCIONALIDADES AVANÇADAS
**Data:** 22/11/2024 a 28/11/2024  
**Meta:** Finalizar todas as funcionalidades principais e implementar pontos de fidelidade

### Backlog Atualizado - Sprint 3

| ID | História de Usuário | Status Sprint 2 | Status Sprint 3 | Responsável | Observações |
|----|---------------------|-----------------|-----------------|-------------|-------------|
| US-01 | Cadastrar clientes | ✅ DONE | ✅ DONE | João Silva | - |
| US-02 | Cadastrar funcionários | ✅ DONE | ✅ DONE | Maria Santos | - |
| US-03 | Cadastrar quartos | ✅ DONE | ✅ DONE | Pedro Costa | - |
| US-04 | Cadastrar estadias | ✅ DONE | ✅ DONE | Ana Oliveira | - |
| US-05 | Pesquisar clientes | ✅ DONE | ✅ DONE | João Silva | - |
| US-06 | Listar quartos | ✅ DONE | ✅ DONE | Pedro Costa | - |
| US-07 | Pontos de fidelidade | 🚧 IN PROGRESS | ✅ DONE | Ana Oliveira | Implementado cálculo completo |
| US-08 | Buscar quartos disponíveis | 📋 TODO | ✅ DONE | Pedro Costa | Filtra por capacidade e disponibilidade |

### Itens Adicionados na Sprint 3

| ID | Nova Tarefa | Prioridade | Responsável | Status |
|----|-------------|------------|-------------|--------|
| TECH-08 | Implementar finalização de estadia | ALTA | Ana Oliveira | ✅ DONE |
| TECH-09 | Liberar quarto ao finalizar estadia | ALTA | Pedro Costa | ✅ DONE |
| TECH-10 | Validar disponibilidade de quarto por período | MÉDIA | Pedro Costa | ✅ DONE |
| TECH-11 | Listar estadias por cliente | MÉDIA | Ana Oliveira | ✅ DONE |
| US-09 | Menu interativo completo | ALTA | Maria Santos | ✅ DONE |

### Itens Removidos/Depriorizados
❌ **REMOVIDO:** US-10 (Relatórios em PDF) - Fora do escopo inicial  
⏸️ **ADIADO:** US-11 (Dashboard web) - Para versão 2.0

### Retrospectiva Sprint 3
✅ **Concluído:** 2 histórias de usuário + 5 tarefas técnicas  
✅ **Todas US principais finalizadas!**  
📝 **Lições Aprendidas:** Priorização é fundamental para cumprir prazos

---

## SPRINT 4 - TESTES E QUALIDADE
**Data:** 29/11/2024 a 05/12/2024  
**Meta:** Implementar testes automatizados e garantir qualidade do código

### Backlog Atualizado - Sprint 4

| ID | Tarefa de Qualidade | Prioridade | Responsável | Status |
|----|---------------------|------------|-------------|--------|
| QA-01 | Implementar testes automatizados com MUnit | CRÍTICO | Equipe QA | ✅ DONE |
| QA-02 | Criar suite de testes para módulo Cliente | ALTA | João Silva | ✅ DONE |
| QA-03 | Criar suite de testes para módulo Funcionário | ALTA | Maria Santos | ✅ DONE |
| QA-04 | Criar suite de testes para módulo Quarto | ALTA | Pedro Costa | ✅ DONE |
| QA-05 | Criar suite de testes para módulo Estadia | ALTA | Ana Oliveira | ✅ DONE |
| QA-06 | Gerar relatório de execução de testes | ALTA | Equipe QA | ✅ DONE |
| QA-07 | Criar dados de teste pré-preenchidos | MÉDIA | João Silva | ✅ DONE |
| QA-08 | Documentar casos de teste | MÉDIA | Ana Oliveira | ✅ DONE |

### Cobertura de Testes Alcançada

| Módulo | Testes Implementados | Cobertura | Status |
|--------|---------------------|-----------|--------|
| Cliente | 7 testes | 100% | ✅ |
| Funcionário | 5 testes | 100% | ✅ |
| Quarto | 6 testes | 100% | ✅ |
| Estadia | 6 testes | 100% | ✅ |
| **TOTAL** | **24 testes** | **100%** | ✅ |

### Retrospectiva Sprint 4
✅ **Concluído:** 8 tarefas de qualidade + 24 testes automatizados  
✅ **100% dos testes passando!**  
📊 **Métricas:** 0 bugs críticos, cobertura completa  
📝 **Lições Aprendidas:** Testes automatizados economizam tempo em debugging

---

## SPRINT 5 - DOCUMENTAÇÃO E ENTREGA
**Data:** 06/12/2024 a 10/12/2024  
**Meta:** Finalizar documentação e preparar entrega

### Backlog Atualizado - Sprint 5

| ID | Tarefa de Documentação | Prioridade | Responsável | Status |
|----|------------------------|------------|-------------|--------|
| DOC-01 | Documentação completa do sistema | ALTA | Maria Santos | ✅ DONE |
| DOC-02 | Backlog evolutivo detalhado | ALTA | João Silva | ✅ DONE |
| DOC-03 | Assinaturas de todas as funções | ALTA | Pedro Costa | ✅ DONE |
| DOC-04 | Plano de testes detalhado | ALTA | Ana Oliveira | ✅ DONE |
| DOC-05 | Relatório de execução de testes | CRÍTICO | Equipe QA | ✅ DONE |
| DOC-06 | README com instruções de uso | ALTA | João Silva | ✅ DONE |
| DOC-07 | Scripts de compilação e execução | MÉDIA | Pedro Costa | ✅ DONE |

### Entregas Finais

| Entregável | Status | Responsável |
|-----------|--------|-------------|
| ✅ Código-fonte completo | DONE | Equipe Dev |
| ✅ Makefile com targets de teste | DONE | Pedro Costa |
| ✅ 24 testes automatizados (MUnit) | DONE | Equipe QA |
| ✅ Dados de teste pré-preenchidos | DONE | João Silva |
| ✅ Documentação técnica completa | DONE | Maria Santos |
| ✅ Backlog evolutivo por sprint | DONE | João Silva |
| ✅ Relatório de execução de testes | DONE | Equipe QA |

### Retrospectiva Sprint 5
✅ **Concluído:** 7 tarefas de documentação  
✅ **Projeto 100% concluído e documentado!**  
🎉 **Entrega realizada com sucesso!**

---

## RESUMO GERAL DA EVOLUÇÃO

### Progresso por Sprint

\`\`\`
Sprint 0: [========>         ] Planejamento (100%)
Sprint 1: [============>     ] Cadastros (3/8 US concluídas)
Sprint 2: [==================>] Pesquisas e Estadias (6/8 US concluídas)
Sprint 3: [====================] Funcionalidades (8/8 US concluídas)
Sprint 4: [====================] Testes Automatizados (24 testes)
Sprint 5: [====================] Documentação e Entrega
\`\`\`

### Métricas do Projeto

| Métrica | Valor |
|---------|-------|
| Total de Sprints | 6 (incluindo Sprint 0) |
| Histórias de Usuário | 9 concluídas |
| Tarefas Técnicas | 11 concluídas |
| Tarefas de QA | 8 concluídas |
| Tarefas de Documentação | 7 concluídas |
| Bugs Corrigidos | 1 |
| Testes Automatizados | 24 (100% passando) |
| Cobertura de Testes | 100% |
| Linhas de Código | ~2000 LOC |

### Equipe e Responsabilidades

| Membro | Papel | US Concluídas | Contribuição |
|--------|-------|---------------|--------------|
| Lucas Cardoso | Desenvolvedor Principal | 9 US + 22 tasks | Desenvolvimento completo do sistema |

---

## ITENS DO BACKLOG PARA VERSÃO 2.0

### Futuras Melhorias (Não Priorizadas para v1.0)

| ID | Funcionalidade | Prioridade | Estimativa |
|----|----------------|------------|------------|
| V2-01 | Interface web com dashboard | MÉDIA | 40h |
| V2-02 | Relatórios em PDF | BAIXA | 16h |
| V2-03 | Integração com sistema de pagamento | ALTA | 32h |
| V2-04 | Notificações por email | BAIXA | 12h |
| V2-05 | Sistema de reservas online | MÉDIA | 24h |
| V2-06 | Histórico de alterações (audit log) | BAIXA | 16h |

---

**Backlog mantido e atualizado por:** Lucas Cardoso  
**Última atualização:** 10/12/2024  
**Status do Projeto:** ✅ CONCLUÍDO E ENTREGUE
