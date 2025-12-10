# Lista de Assinaturas das Funções

## Estruturas de Dados Principais

### Cliente
\`\`\`c
typedef struct {
    int codigo;
    char nome[100];
    char endereco[200];
    char telefone[20];
    int ativo; // 1 = ativo, 0 = inativo
} Cliente;
\`\`\`

### Funcionario
\`\`\`c
typedef struct {
    int codigo;
    char nome[100];
    char telefone[20];
    char cargo[50];
    float salario;
    int ativo; // 1 = ativo, 0 = inativo
} Funcionario;
\`\`\`

### Quarto
\`\`\`c
typedef struct {
    int numero;
    int quantidade_hospedes;
    float valor_diaria;
    StatusQuarto status; // OCUPADO ou DESOCUPADO
    int ativo; // 1 = ativo, 0 = inativo
} Quarto;
\`\`\`

### Estadia
\`\`\`c
typedef struct {
    int codigo;
    char data_entrada[11];  // DD/MM/AAAA
    char data_saida[11];    // DD/MM/AAAA
    int quantidade_diarias;
    int codigo_cliente;
    int numero_quarto;
    int finalizada; // 0 = ativa, 1 = finalizada
    int ativo; // 1 = ativo, 0 = inativo
} Estadia;
\`\`\`

---

## Módulo de Clientes (cliente.h/.c)

### 1. cadastrar_cliente
\`\`\`c
int cadastrar_cliente(int codigo, const char *nome, 
                     const char *endereco, const char *telefone);
\`\`\`
**Propósito**: Cadastra um novo cliente no sistema com validação de duplicidade.

**Parâmetros de Entrada**:
- `codigo`: Código único do cliente (se 0, gera automaticamente)
- `nome`: Nome completo do cliente (obrigatório)
- `endereco`: Endereço do cliente
- `telefone`: Telefone de contato

**Parâmetro de Saída**:
- Retorna o código do cliente cadastrado
- Retorna -1 em caso de erro

**Validações**:
- Nome não pode ser vazio
- Código não pode estar duplicado
- Gera código automaticamente se não fornecido

---

### 2. pesquisar_cliente_por_codigo
\`\`\`c
int pesquisar_cliente_por_codigo(int codigo, Cliente *cliente);
\`\`\`
**Propósito**: Busca um cliente específico pelo código único.

**Parâmetros de Entrada**:
- `codigo`: Código do cliente a ser pesquisado

**Parâmetros de Saída**:
- `cliente`: Ponteiro para estrutura que receberá os dados
- Retorna 1 se encontrado, 0 caso contrário

---

### 3. pesquisar_cliente_por_nome
\`\`\`c
void pesquisar_cliente_por_nome(const char *nome);
\`\`\`
**Propósito**: Busca clientes por nome ou parte do nome (busca parcial).

**Parâmetros de Entrada**:
- `nome`: Nome ou parte do nome a ser pesquisado

**Comportamento**:
- Exibe todos os clientes que contêm o texto pesquisado
- Busca case-sensitive
- Exibe mensagem se nenhum cliente for encontrado

---

### 4. listar_clientes
\`\`\`c
void listar_clientes();
\`\`\`
**Propósito**: Lista todos os clientes cadastrados no sistema.

**Comportamento**:
- Exibe informações completas de cada cliente ativo
- Mostra total de clientes ao final
- Mensagem específica se não houver clientes

---

### 5. gerar_proximo_codigo_cliente
\`\`\`c
int gerar_proximo_codigo_cliente();
\`\`\`
**Propósito**: Gera o próximo código disponível para cadastro.

**Parâmetro de Saída**:
- Retorna o próximo código sequencial disponível

**Comportamento**:
- Analisa todos os códigos existentes
- Retorna (maior_codigo + 1)
- Retorna 1 se não houver clientes cadastrados

---

### 6. exibir_cliente
\`\`\`c
void exibir_cliente(const Cliente *cliente);
\`\`\`
**Propósito**: Exibe informações formatadas de um cliente.

**Parâmetros de Entrada**:
- `cliente`: Ponteiro para a estrutura do cliente

**Comportamento**:
- Formata e exibe todos os campos do cliente
- Usado por outras funções de pesquisa e listagem

---

## Módulo de Funcionários (funcionario.h/.c)

### 1. cadastrar_funcionario
\`\`\`c
int cadastrar_funcionario(int codigo, const char *nome, const char *telefone,
                         const char *cargo, float salario);
\`\`\`
**Propósito**: Cadastra um novo funcionário no sistema.

**Parâmetros de Entrada**:
- `codigo`: Código único do funcionário (se 0, gera automaticamente)
- `nome`: Nome completo do funcionário (obrigatório)
- `telefone`: Telefone de contato
- `cargo`: Cargo/função do funcionário
- `salario`: Salário mensal (deve ser > 0)

**Parâmetro de Saída**:
- Retorna o código do funcionário cadastrado
- Retorna -1 em caso de erro

**Validações**:
- Nome não pode ser vazio
- Salário deve ser maior que zero
- Código não pode estar duplicado

---

### 2. pesquisar_funcionario_por_codigo
\`\`\`c
int pesquisar_funcionario_por_codigo(int codigo, Funcionario *funcionario);
\`\`\`
**Propósito**: Busca um funcionário específico pelo código.

**Parâmetros de Entrada**:
- `codigo`: Código do funcionário a ser pesquisado

**Parâmetros de Saída**:
- `funcionario`: Ponteiro para estrutura que receberá os dados
- Retorna 1 se encontrado, 0 caso contrário

---

### 3. pesquisar_funcionario_por_nome
\`\`\`c
void pesquisar_funcionario_por_nome(const char *nome);
\`\`\`
**Propósito**: Busca funcionários por nome ou parte do nome.

**Parâmetros de Entrada**:
- `nome`: Nome ou parte do nome a ser pesquisado

**Comportamento**:
- Exibe todos os funcionários que contêm o texto pesquisado
- Inclui informações de cargo e salário

---

### 4. listar_funcionarios
\`\`\`c
void listar_funcionarios();
\`\`\`
**Propósito**: Lista todos os funcionários cadastrados.

**Comportamento**:
- Exibe informações completas de cada funcionário ativo
- Mostra total de funcionários ao final

---

## Módulo de Quartos (quarto.h/.c)

### 1. cadastrar_quarto
\`\`\`c
int cadastrar_quarto(int numero, int quantidade_hospedes, float valor_diaria);
\`\`\`
**Propósito**: Cadastra um novo quarto no sistema.

**Parâmetros de Entrada**:
- `numero`: Número único do quarto (obrigatório e > 0)
- `quantidade_hospedes`: Capacidade máxima de hóspedes (> 0)
- `valor_diaria`: Valor cobrado por diária (> 0)

**Parâmetro de Saída**:
- Retorna o número do quarto cadastrado
- Retorna -1 em caso de erro

**Validações**:
- Número deve ser único
- Todos os valores devem ser maiores que zero
- Status inicial é DESOCUPADO

---

### 2. pesquisar_quarto_por_numero
\`\`\`c
int pesquisar_quarto_por_numero(int numero, Quarto *quarto);
\`\`\`
**Propósito**: Busca um quarto específico pelo número.

**Parâmetros de Entrada**:
- `numero`: Número do quarto a ser pesquisado

**Parâmetros de Saída**:
- `quarto`: Ponteiro para estrutura que receberá os dados
- Retorna 1 se encontrado, 0 caso contrário

---

### 3. buscar_quarto_disponivel
\`\`\`c
int buscar_quarto_disponivel(int quantidade_hospedes, const char *data_entrada,
                             const char *data_saida);
\`\`\`
**Propósito**: Busca um quarto disponível que atenda aos requisitos.

**Parâmetros de Entrada**:
- `quantidade_hospedes`: Capacidade necessária
- `data_entrada`: Data de check-in (DD/MM/AAAA)
- `data_saida`: Data de check-out (DD/MM/AAAA)

**Parâmetro de Saída**:
- Retorna o número do primeiro quarto disponível
- Retorna -1 se não encontrar quarto disponível

**Critérios de Busca**:
- Capacidade >= quantidade solicitada
- Status DESOCUPADO
- Sem conflito de datas com outras estadias

---

### 4. atualizar_status_quarto
\`\`\`c
int atualizar_status_quarto(int numero, StatusQuarto status);
\`\`\`
**Propósito**: Atualiza o status de um quarto (ocupado/desocupado).

**Parâmetros de Entrada**:
- `numero`: Número do quarto
- `status`: Novo status (OCUPADO ou DESOCUPADO)

**Parâmetro de Saída**:
- Retorna 1 se atualizado com sucesso
- Retorna 0 se quarto não encontrado

---

## Módulo de Estadias (estadia.h/.c)

### 1. cadastrar_estadia
\`\`\`c
int cadastrar_estadia(int codigo_cliente, int quantidade_hospedes,
                     const char *data_entrada, const char *data_saida);
\`\`\`
**Propósito**: Cadastra uma nova estadia no sistema com alocação automática de quarto.

**Parâmetros de Entrada**:
- `codigo_cliente`: Código do cliente (deve existir)
- `quantidade_hospedes`: Número de hóspedes (> 0)
- `data_entrada`: Data de check-in (DD/MM/AAAA)
- `data_saida`: Data de check-out (DD/MM/AAAA)

**Parâmetro de Saída**:
- Retorna o código da estadia cadastrada
- Retorna -1 em caso de erro

**Validações e Comportamento**:
- Verifica se cliente existe
- Valida formato e lógica das datas
- Busca quarto disponível automaticamente
- Calcula quantidade de diárias
- Atualiza status do quarto para OCUPADO
- Gera código único para a estadia

---

### 2. dar_baixa_estadia
\`\`\`c
float dar_baixa_estadia(int codigo_estadia);
\`\`\`
**Propósito**: Finaliza uma estadia e calcula o valor total a ser pago.

**Parâmetros de Entrada**:
- `codigo_estadia`: Código da estadia a ser finalizada

**Parâmetro de Saída**:
- Retorna o valor total da estadia (quantidade_diarias * valor_diaria)
- Retorna -1 em caso de erro

**Comportamento**:
- Verifica se a estadia existe e está ativa
- Calcula valor total baseado no quarto e diárias
- Marca estadia como finalizada
- Atualiza status do quarto para DESOCUPADO
- Exibe resumo completo da cobrança

---

### 3. listar_estadias_cliente
\`\`\`c
void listar_estadias_cliente(int codigo_cliente);
\`\`\`
**Propósito**: Lista todas as estadias (ativas e finalizadas) de um cliente.

**Parâmetros de Entrada**:
- `codigo_cliente`: Código do cliente

**Comportamento**:
- Verifica se o cliente existe
- Exibe todas as estadias do cliente
- Mostra status (ativa/finalizada)
- Exibe total de estadias ao final

---

### 4. calcular_pontos_fidelidade
\`\`\`c
int calcular_pontos_fidelidade(int codigo_cliente);
\`\`\`
**Propósito**: Calcula total de pontos de fidelidade de um cliente.

**Parâmetros de Entrada**:
- `codigo_cliente`: Código do cliente

**Parâmetro de Saída**:
- Retorna o total de pontos (total_diarias * 10)
- Retorna -1 se cliente não encontrado

**Regra de Negócio**:
- Cliente ganha 10 pontos por diária
- Contabiliza todas as estadias (ativas e finalizadas)
- Exibe relatório detalhado

---

### 5. verificar_disponibilidade_quarto
\`\`\`c
int verificar_disponibilidade_quarto(int numero_quarto, const char *data_entrada,
                                    const char *data_saida);
\`\`\`
**Propósito**: Verifica se um quarto está disponível em um período específico.

**Parâmetros de Entrada**:
- `numero_quarto`: Número do quarto a verificar
- `data_entrada`: Data inicial do período
- `data_saida`: Data final do período

**Parâmetro de Saída**:
- Retorna 1 se disponível
- Retorna 0 se há conflito com outras estadias

**Comportamento**:
- Verifica sobreposição de datas com estadias ativas
- Considera apenas estadias não finalizadas

---

## Módulo de Utilitários (utils.h/.c)

### 1. validar_data
\`\`\`c
int validar_data(const char *data);
\`\`\`
**Propósito**: Valida formato e consistência de uma data.

**Parâmetros de Entrada**:
- `data`: String com data no formato DD/MM/AAAA

**Parâmetro de Saída**:
- Retorna 1 se data válida
- Retorna 0 se data inválida

**Validações**:
- Formato correto (DD/MM/AAAA)
- Caracteres numéricos
- Mês entre 1 e 12
- Dia válido para o mês
- Considera anos bissextos

---

### 2. calcular_diarias
\`\`\`c
int calcular_diarias(const char *data_entrada, const char *data_saida);
\`\`\`
**Propósito**: Calcula quantidade de diárias entre duas datas.

**Parâmetros de Entrada**:
- `data_entrada`: Data inicial (DD/MM/AAAA)
- `data_saida`: Data final (DD/MM/AAAA)

**Parâmetro de Saída**:
- Retorna quantidade de dias entre as datas

---

### 3. comparar_datas
\`\`\`c
int comparar_datas(const char *data1, const char *data2);
\`\`\`
**Propósito**: Compara duas datas cronologicamente.

**Parâmetros de Entrada**:
- `data1`: Primeira data (DD/MM/AAAA)
- `data2`: Segunda data (DD/MM/AAAA)

**Parâmetro de Saída**:
- Retorna < 0 se data1 é anterior a data2
- Retorna 0 se datas são iguais
- Retorna > 0 se data1 é posterior a data2

---

### 4. verificar_sobreposicao_datas
\`\`\`c
int verificar_sobreposicao_datas(const char *entrada1, const char *saida1,
                                 const char *entrada2, const char *saida2);
\`\`\`
**Propósito**: Verifica se dois períodos de datas se sobrepõem.

**Parâmetros de Entrada**:
- `entrada1`, `saida1`: Primeiro período
- `entrada2`, `saida2`: Segundo período

**Parâmetro de Saída**:
- Retorna 1 se há sobreposição
- Retorna 0 se os períodos não se sobrepõem

**Lógica**:
- Dois períodos NÃO se sobrepõem se:
  - Um termina antes do outro começar

---

### 5. criar_diretorio_data
\`\`\`c
void criar_diretorio_data();
\`\`\`
**Propósito**: Cria o diretório "data/" se não existir.

**Comportamento**:
- Verifica existência do diretório
- Cria se necessário
- Compatível com Windows e Linux/Unix

---

### 6. limpar_buffer
\`\`\`c
void limpar_buffer();
\`\`\`
**Propósito**: Limpa o buffer de entrada do teclado.

**Uso**:
- Previne comportamentos indesejados em entradas consecutivas
- Usado antes de leituras com fgets() após scanf()

---

### 7. pausar
\`\`\`c
void pausar();
\`\`\`
**Propósito**: Pausa a execução e aguarda tecla do usuário.

**Uso**:
- Permite visualização de resultados antes de limpar tela
- Melhora experiência do usuário no menu

---

*Esta documentação contém todas as assinaturas de funções utilizadas no sistema, com descrição detalhada de propósito, parâmetros e comportamento.*
