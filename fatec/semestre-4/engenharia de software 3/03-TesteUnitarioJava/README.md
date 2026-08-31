# 🧪 Laboratório: Testes Unitários e TDD com Java e JUnit

> **Disciplina:** Qualidade de Software  
> **Duração estimada:** 2h  
> **Pré-requisitos:** Conta no GitHub, noções básicas de Java

---

## 📋 Sumário

1. [Objetivos de Aprendizagem](#-objetivos-de-aprendizagem)
2. [Revisão Teórica — Testes Unitários](#-revisão-teórica--testes-unitários)
3. [Revisão Teórica — TDD](#-revisão-teórica--tdd)
4. [Preparação do Ambiente](#️-preparação-do-ambiente)
5. [Estrutura do Repositório](#-estrutura-do-repositório)
6. [Parte 1 — Exemplo Guiado: Construtor da Conta Bancária](#-parte-1--exemplo-guiado-construtor-da-conta-bancária)
7. [Parte 2 — Exercício: Crie os Demais Testes](#-parte-2--exercício-crie-os-demais-testes)
8. [Referência Rápida — JUnit 5](#-referência-rápida--junit-5)
9. [Entregáveis](#-entregáveis)

---

## 🎯 Objetivos de Aprendizagem

Ao final desta atividade, você será capaz de:

- Explicar o que são testes unitários e por que são importantes para a qualidade de software.
- Aplicar o ciclo **Red → Green → Refactor** da metodologia TDD.
- Escrever testes unitários em Java utilizando o framework **JUnit 5** (Jupiter).
- Usar as anotações `@Test` e `@ParameterizedTest` para diferentes cenários de teste.
- Executar testes de forma interativa dentro do VS Code.
- Organizar um projeto de testes seguindo as convenções do ecossistema Java/Maven.

---

## 📖 Revisão Teórica — Testes Unitários

### O que é um Teste Unitário?

Um **teste unitário** é um trecho de código que verifica o comportamento de uma **unidade isolada** do sistema — geralmente um método ou função. O objetivo é garantir que cada parte do código funcione corretamente de forma independente.

### Características de um bom teste unitário

| Característica | Descrição |
|---|---|
| **Rápido** | Executa em milissegundos |
| **Isolado** | Não depende de banco de dados, rede ou outros testes |
| **Repetível** | Produz o mesmo resultado toda vez que é executado |
| **Auto-verificável** | O resultado é "passou" ou "falhou" — sem inspeção manual |
| **Oportuno** | Escrito no momento certo (idealmente antes do código, no TDD) |

> Essas características formam o acrônimo **F.I.R.S.T** (Fast, Isolated, Repeatable, Self-validating, Timely).

### O padrão AAA (Arrange-Act-Assert)

Todo teste unitário segue uma estrutura de três etapas:

```
Arrange  →  Preparar os dados e objetos necessários
Act      →  Executar a ação que será testada
Assert   →  Verificar se o resultado é o esperado
```

Exemplo concreto em Java com JUnit 5:

```java
@Test
void construtor_DadosValidos_CriaContaCorretamente() {
    // Arrange & Act
    var conta = new Conta("Maria", 100);

    // Assert
    assertEquals("Maria", conta.getTitular());
    assertEquals(100, conta.getSaldo());
    assertTrue(conta.isAtiva());
}
```

### Por que escrever testes unitários?

- **Detecção precoce de bugs:** encontra erros antes que cheguem à produção.
- **Documentação viva:** os testes descrevem o comportamento esperado do código.
- **Refatoração segura:** é possível alterar o código com confiança de que nada quebrou.
- **Redução de custo:** quanto mais cedo um defeito é encontrado, mais barato é corrigi-lo.

### Convenções de nomenclatura

Usaremos o padrão `metodo_Cenario_ResultadoEsperado`:

```
construtor_DadosValidos_CriaContaCorretamente
depositar_ValorNegativo_LancaIllegalArgumentException
sacar_SaldoInsuficiente_LancaIllegalStateException
```

Isso torna os relatórios de teste autoexplicativos.

---

## 🔄 Revisão Teórica — TDD

### O que é TDD?

**Test-Driven Development** (Desenvolvimento Guiado por Testes) é uma metodologia onde os testes são escritos **antes** do código de produção. Foi popularizada por Kent Beck como parte das práticas de Extreme Programming (XP).

### O Ciclo Red → Green → Refactor

```
┌──────────────────────────────────────┐
│                                      │
│   🔴 RED                             │
│   Escreva um teste que FALHE         │
│                                      │
│          │                           │
│          ▼                           │
│                                      │
│   🟢 GREEN                           │
│   Escreva o código MÍNIMO para       │
│   o teste PASSAR                     │
│                                      │
│          │                           │
│          ▼                           │
│                                      │
│   🔵 REFACTOR                        │
│   Melhore o código mantendo          │
│   todos os testes passando           │
│                                      │
│          │                           │
│          └──────── ↩ Repita ─────────┘
│
└──────────────────────────────────────┘
```

Detalhando cada etapa:

| Etapa | O que fazer | Tempo |
|---|---|---|
| 🔴 **Red** | Escrever um teste para um comportamento que ainda não existe. O teste deve **falhar**. | 1–3 min |
| 🟢 **Green** | Escrever o código **mínimo** necessário para que o teste passe. Não otimize ainda. | 1–5 min |
| 🔵 **Refactor** | Melhorar a estrutura do código (eliminar duplicação, renomear variáveis, simplificar lógica) sem alterar o comportamento. Todos os testes devem continuar passando. | 1–5 min |

### Benefícios do TDD

- **Design emergente:** o código nasce com responsabilidades claras e interfaces bem definidas.
- **Cobertura de testes alta por padrão:** se todo código nasce de um teste, a cobertura é naturalmente alta.
- **Feedback imediato:** erros são detectados em segundos, não em dias.
- **Confiança ao mudar código:** a suíte de testes funciona como uma rede de segurança.

### TDD NÃO é:

- ❌ Escrever o código e depois os testes (isso é "test-after").
- ❌ Escrever todos os testes de uma vez e depois todo o código.
- ❌ Uma garantia de que o software está livre de bugs (mas reduz muito o risco).

---

## ⚙️ Preparação do Ambiente

### Passo 1 — Fork do repositório

1. Acesse o repositório original no GitHub.
2. Clique no botão **"Fork"** (canto superior direito).
3. Selecione sua conta pessoal como destino.

### Passo 2 — Abrir no GitHub Codespaces

1. No seu fork, clique no botão verde **"<> Code"**.
2. Selecione a aba **"Codespaces"**.
3. Clique em **"Create codespace on main"**.
4. Aguarde o ambiente ser carregado (2–3 minutos na primeira vez).

> 💡 O Codespace já vem com o **Java 21 (JDK)** e todas as extensões do VS Code pré-configuradas, incluindo o **Test Runner for Java** que habilita a view **Testing**.

> ⏱️ Depois que o Codespace abrir, a importação do projeto Java pode levar mais **1 a 3 minutos**. A view **Testing** normalmente só aparece preenchida depois que essa importação termina.

### Passo 3 — Verificar o ambiente

Abra o terminal integrado (`` Ctrl + ` ``) e execute:

```bash
java --version
```

Deve exibir a versão 21.x. Em seguida, compile o projeto:

```bash
./mvnw compile
```

> 💡 O projeto versiona o **Maven Wrapper** no próprio repositório (`mvnw`, `mvnw.cmd` e `.mvn/wrapper`). Isso evita depender de uma instalação prévia do Maven no Codespaces. Se o shell informar falta de permissão, execute `chmod +x mvnw` uma vez.

### Passo 4 — Conhecer o Test Explorer

A extensão **Test Runner for Java** permite executar testes de forma visual:

1. Clique no ícone de tubo de ensaio (🧪) na barra lateral esquerda do VS Code.
2. Você verá a árvore de testes organizados por pacote e classe.
3. Clique no botão ▶️ ao lado de um teste para executá-lo individualmente.
4. Use o botão ▶️ no topo para executar todos os testes.

Se a view **Testing** não aparecer automaticamente no Codespaces:

1. Aguarde a importação do projeto Java terminar. Em um Codespace recém-criado, isso pode levar alguns minutos mesmo após o terminal já estar disponível.
2. Verifique se o workspace abriu em modo **Standard** para Java.
3. Abra a Paleta de Comandos e execute **Java: Import Java Projects in Workspace**.
4. Se ainda não aparecer, execute **Java: Clean Java Language Server Workspace** e recarregue a janela.

### Checklist rápido (quando o Test Explorer sumir)

Se a aba **Testing** continuar vazia no Codespaces, siga esta sequência curta:

1. Execute **Developer: Reload Window**.
2. Execute **Java: Import Java Projects in Workspace**.
3. Execute **Java: Clean Java Language Server Workspace** e recarregue.
4. Confirme no terminal: `./mvnw test`.
5. Se persistir, faça **Codespaces: Rebuild Container**.

> O workspace já está configurado para abrir em modo **Standard** e preferir o Maven Wrapper. Isso é necessário porque o modo **LightWeight** não resolve dependências Maven e pode impedir que a árvore de testes seja exibida.

### Troubleshooting visual da view Testing

Use estes sinais visuais para verificar se o ambiente Java terminou de carregar:

1. **Barra de status do VS Code**: se o Java ainda estiver inicializando ou importando dependências, aguarde até a atividade terminar.
2. **Modo do workspace Java**: confirme que o ambiente não ficou em **LightWeight**. O projeto deve abrir em **Standard**.
3. **Explorer / Java Projects**: o `pom.xml` deve ser reconhecido como projeto Maven importado, não apenas como um arquivo solto.
4. **Classe de teste**: ao abrir `ContaTest.java`, os ícones de executar/debug do Java devem aparecer acima da classe e dos métodos de teste.
5. **Activity Bar**: a aba **Testing** pode existir antes da descoberta dos testes, mas a árvore só será populada depois da importação do projeto.

Você também pode executar testes pelo terminal:

```bash
# Executar todos os testes
./mvnw test

# Executar com mais detalhes
./mvnw test -Dsurefire.printSummary=true

# Filtrar por nome de teste
./mvnw test -Dtest="ContaTest#construtor_DadosValidos_CriaContaCorretamente"

# Filtrar por método (padrão wildcard)
./mvnw test -Dtest="ContaTest#depositar*"
```

---

## 📁 Estrutura do Repositório

```
tdd-junit-java/
├── .devcontainer/
│   └── devcontainer.json              ← Configuração do Codespaces
├── .mvn/wrapper/
│   └── maven-wrapper.properties       ← Configuração do Maven Wrapper
├── mvnw                               ← Script do Maven Wrapper para Linux/macOS
├── mvnw.cmd                           ← Script do Maven Wrapper para Windows
├── .vscode/
│   └── extensions.json                ← Extensões recomendadas
├── src/
│   ├── main/java/contabancaria/
│   │   └── Conta.java                ← Classe de produção (construtor implementado)
│   └── test/java/contabancaria/
│       └── ContaTest.java             ← Testes (exemplo do construtor + você escreverá o restante)
├── pom.xml                            ← Configuração Maven (dependências e build)
├── .gitignore
└── README.md                          ← Este roteiro
```

---

## 🟢 Parte 1 — Exemplo Guiado: Construtor da Conta Bancária

> **Objetivo:** Entender a estrutura de um teste unitário com JUnit 5 e o ciclo TDD, usando o construtor da classe `Conta` como exemplo completo.

### 1.1 Analisar o código de produção

Abra o arquivo `src/main/java/contabancaria/Conta.java` e observe o construtor da classe `Conta`. Ele já está implementado com as seguintes regras:

- O titular não pode ser nulo ou vazio (lança `IllegalArgumentException`).
- O saldo inicial não pode ser negativo (lança `IllegalArgumentException`).
- A conta é criada como ativa.

Os demais métodos (`depositar`, `sacar`, `transferir`, `encerrar`) ainda **não estão implementados** — lançam `UnsupportedOperationException`. É você quem vai implementá-los usando TDD na Parte 2.

### 1.2 Analisar os testes do construtor

Abra `src/test/java/contabancaria/ContaTest.java` e analise os testes prontos para o Construtor:

- `construtor_DadosValidos_CriaContaCorretamente` — teste básico com `@Test` que verifica titular, saldo e status ativo.
- `construtor_SemSaldoInicial_CriaContaComSaldoZero` — testa o valor padrão do saldo.
- `construtor_TitularNulo_LancaIllegalArgumentException` — testa cenário de exceção.
- `construtor_TitularVazio_LancaIllegalArgumentException` — outro cenário de exceção.
- `construtor_SaldoNegativo_LancaIllegalArgumentException` — valida regra de negócio.
- `construtor_VariosValoresValidos_CriaContaCorretamente` — teste parametrizado com `@ParameterizedTest` e `@CsvSource`.

### 1.3 Executar os testes do construtor

No terminal, execute:

```bash
./mvnw test -Dtest="ContaTest#construtor*"
```

Ou pelo Test Explorer, expanda **ContaTest** e clique ▶️ nos testes de `construtor`.

✅ Todos os testes do construtor devem passar (verde).

### 1.4 Pontos a observar

Analise atentamente os testes do construtor e observe:

- **Padrão AAA:** cada teste segue a estrutura Arrange → Act → Assert.
- `@Test` é usado para testes com valores fixos (sem parâmetros).
- `@ParameterizedTest` + `@CsvSource` permite executar o mesmo teste com valores diferentes.
- `assertThrows(Tipo.class, () -> ...)` verifica que uma exceção específica é lançada.
- **Nomenclatura:** os nomes dos testes seguem `metodo_Cenario_ResultadoEsperado`.
- **Cobertura:** há testes para o caminho feliz, cenários de exceção e casos de borda.

### 1.5 Entendendo o ciclo TDD aplicado ao construtor

Vamos recapitular como o construtor foi implementado seguindo TDD:

#### 🔴 RED — O teste foi escrito primeiro

```java
@Test
void construtor_DadosValidos_CriaContaCorretamente() {
    var conta = new Conta("Maria", 100);

    assertEquals("Maria", conta.getTitular());
    assertEquals(100, conta.getSaldo());
    assertTrue(conta.isAtiva());
}
```

Com o construtor lançando `UnsupportedOperationException`, este teste falhava.

#### 🟢 GREEN — O código mínimo foi implementado

```java
public Conta(String titular, double saldoInicial) {
    if (titular == null || titular.isBlank())
        throw new IllegalArgumentException("O titular não pode ser nulo ou vazio.");
    if (saldoInicial < 0)
        throw new IllegalArgumentException("O saldo inicial não pode ser negativo.");

    this.titular = titular;
    this.saldo = saldoInicial;
    this.ativa = true;
}
```

Após implementar, o teste passou.

#### 🔵 REFACTOR — O código já está limpo

Neste caso, não há necessidade de refatoração. Em métodos mais complexos, esta é a hora de eliminar duplicação e melhorar nomes.

---

## 🏦 Parte 2 — Exercício: Crie os Demais Testes

> **Objetivo:** Praticar TDD do zero, escrevendo testes e implementando os métodos restantes da classe `Conta`.

Agora é a sua vez! Usando como modelo os testes do construtor, você deve aplicar o ciclo TDD para cada um dos métodos abaixo.

### Requisitos

Abra o arquivo `src/main/java/contabancaria/Conta.java` e leia a documentação de cada método. Você encontrará:

| Método | Regras de Validação |
|---|---|
| `depositar` | Valor > 0, conta ativa |
| `sacar` | Valor > 0, conta ativa, saldo suficiente |
| `transferir` | Ambas ativas, valor > 0, saldo suficiente |
| `encerrar` | Conta ativa, saldo = 0 |

### Instruções

1. Abra `src/test/java/contabancaria/ContaTest.java`.
2. Leia as sugestões de testes nos comentários de cada seção.
3. Para cada método, siga o ciclo TDD:
   - 🔴 Escreva um teste → execute → veja falhar.
   - 🟢 Implemente o código mínimo em `Conta.java` → execute → veja passar.
   - 🔵 Refatore se necessário.
   - Repita para o próximo cenário de teste.

### Exemplo de como começar — Teste do depositar

Siga o mesmo padrão dos testes do construtor:

```java
@Test
void depositar_ValorValido_AtualizaSaldo() {
    // Arrange
    var conta = new Conta("Maria", 100);

    // Act
    conta.depositar(50);

    // Assert
    assertEquals(150, conta.getSaldo());
}
```

1. Escreva este teste e execute → ele vai **falhar** (🔴) porque `depositar` lança `UnsupportedOperationException`.
2. Vá até `Conta.java` e implemente o código mínimo de `depositar` → execute → veja **passar** (🟢).
3. Refatore se necessário (🔵).
4. Escreva o próximo teste (ex: `depositar_ValorZero_LancaIllegalArgumentException`) e repita o ciclo.

### Dicas

Para testar exceções, use `assertThrows`:

```java
@Test
void depositar_ValorNegativo_LancaIllegalArgumentException() {
    var conta = new Conta("Maria", 100);
    assertThrows(IllegalArgumentException.class, () -> conta.depositar(-10));
}
```

Para testar conta inativa, você precisa primeiro encerrar a conta (o que requer implementar `encerrar` antes). Planeje a ordem de implementação!

Para testar `transferir`, crie duas contas e verifique os saldos de ambas:

```java
@Test
void transferir_ValorValido_AtualizaSaldoDeAmbasContas() {
    var origem = new Conta("Maria", 200);
    var destino = new Conta("João", 100);

    origem.transferir(destino, 50);

    assertEquals(150, origem.getSaldo());
    assertEquals(150, destino.getSaldo());
}
```

### Executar testes

```bash
# Todos os testes
./mvnw test

# Filtrar por método
./mvnw test -Dtest="ContaTest#depositar*"
./mvnw test -Dtest="ContaTest#sacar*"
```

> ⚠️ **Mínimo exigido:** Crie pelo menos **15 testes** cobrindo todos os métodos da classe `Conta`.

---

## 📘 Referência Rápida — JUnit 5

### Anotações de teste

| Anotação | Descrição |
|---|---|
| `@Test` | Teste com valores fixos (sem parâmetros) |
| `@ParameterizedTest` | Teste parametrizado (executado N vezes) |
| `@CsvSource({...})` | Fornece dados inline para `@ParameterizedTest` |
| `@ValueSource(ints = {...})` | Fornece valores simples de um tipo |
| `@DisplayName("...")` | Define nome legível para o teste no relatório |
| `@BeforeEach` | Método executado antes de cada teste |
| `@AfterEach` | Método executado depois de cada teste |

### Assertions comuns

```java
// Igualdade
assertEquals(esperado, resultado);

// Igualdade com tolerância (para doubles)
assertEquals(esperado, resultado, 0.001);

// Booleanos
assertTrue(condicao);
assertFalse(condicao);

// Nulos
assertNull(objeto);
assertNotNull(objeto);

// Exceções
assertThrows(TipoExcecao.class, () -> metodoQueLanca());

// Strings
assertTrue(resultado.contains("texto"));
assertTrue(resultado.startsWith("prefixo"));

// Coleções
assertTrue(lista.isEmpty());
assertTrue(lista.contains(item));
assertEquals(tamanhoEsperado, lista.size());
```

### Executando testes no terminal

```bash
# Todos os testes
./mvnw test

# Filtrar por nome de teste
./mvnw test -Dtest="ContaTest#construtor_DadosValidos_CriaContaCorretamente"

# Filtrar por classe
./mvnw test -Dtest="ContaTest"

# Com detalhes
./mvnw test -Dsurefire.printSummary=true

# Com cobertura (requer plugin JaCoCo no pom.xml)
./mvnw test jacoco:report
```

---

## 📦 Entregáveis

Para comprovar a realização da atividade, você deve entregar as seguintes evidências no seu fork do repositório:

### ✅ Checklist obrigatório

| # | Item | Critério | Local |
|---|---|---|---|
| 1 | Testes da Conta Bancária | Mínimo de 15 testes cobrindo todos os métodos | `src/test/java/contabancaria/ContaTest.java` |
| 2 | Código da Conta Bancária | Classe Conta.java totalmente implementada (sem `UnsupportedOperationException`) | `src/main/java/contabancaria/Conta.java` |
| 3 | Todos os testes passando | Screenshot ou saída do terminal mostrando `./mvnw test` com todos os testes passando | Incluir no commit |
| 4 | Histórico de commits | Commits incrementais mostrando o ciclo TDD (ex: "red: teste depositar", "green: implementa depositar") | Histórico do Git |

### 📸 Screenshot dos testes

Após concluir, execute e capture a saída:

```bash
./mvnw test 2>&1 | tee resultado-testes.txt
```

Faça o commit do arquivo `resultado-testes.txt` junto com seu código.

### 🔀 Padrão de commits (recomendado)

Use prefixos para documentar o ciclo TDD nos commits:

```
red:      teste para depositar - valor válido
green:    implementa depositar
refactor: simplifica validação do depositar

red:      teste para sacar - saldo insuficiente
green:    implementa sacar com validação
refactor: extrai validação para método privado
```

### 📤 Como entregar

1. Faça commit de todas as alterações:
   ```bash
   git add .
   git commit -m "Atividade TDD completa"
   git push origin main
   ```
2. Confirme que o código está no seu fork no GitHub.
3. Envie o link do seu repositório (fork) no ambiente virtual da disciplina.

---

## 📚 Referências

- [JUnit 5 — Guia do Usuário (Oficial)](https://junit.org/junit5/docs/current/user-guide/)
- [Maven Surefire Plugin](https://maven.apache.org/surefire/maven-surefire-plugin/)
- [TDD — Martin Fowler](https://martinfowler.com/bliki/TestDrivenDevelopment.html)
- [Padrão AAA — Arrange, Act, Assert](https://automationpanda.com/2020/07/07/arrange-act-assert-a-pattern-for-writing-good-tests/)

---

> Bom trabalho! Lembre-se: no TDD, o teste sempre vem primeiro. 🧪🔴🟢🔵
