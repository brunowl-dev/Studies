# 📌 Atividade Prática: Integração Contínua (CI) e Entrega Contínua (CD) com GitHub Pages

## 🎯 **Objetivo**
Esta atividade tem como objetivo proporcionar experiência prática com os conceitos de **Integração Contínua (CI)** e **Entrega Contínua (CD)**, utilizando **GitHub** como ferramenta de versionamento e **GitHub Pages** como ambiente de hospedagem.

> **IMPORTANTE:** Para esta atividade, será necessário pelo menos **um outro colaborador**. Todos os integrantes do grupo devem **realizar e documentar a execução das tarefas**.

## 📂 **Estrutura do Repositório**

Este repositório contém os arquivos base necessários para iniciar a atividade:

| Arquivo | Descrição |
|---|---|
| `index.html` | Página HTML inicial do projeto (será personalizada por você) |
| `contribuicao.html` | Trecho HTML de referência para a contribuição do colaborador |
| `README.md` | Este roteiro de atividade |

> **Você NÃO precisa copiar código de blocos de texto** para os arquivos HTML. Basta fazer um **fork** e trabalhar a partir dele.
>
> ⚠️ **O arquivo de workflow do GitHub Actions NÃO está incluído no repositório.** Você irá **criá-lo** durante a atividade, como parte do processo de aprendizagem de CI/CD.

---

## 📚 **Conceitos Fundamentais**

### 🔸 **Fork**
Um **fork** é uma cópia completa de um repositório para a sua própria conta no GitHub. Diferente de um clone (que é local), o fork cria um repositório independente no GitHub ligado ao repositório original. Isso permite que você experimente livremente sem afetar o projeto original.

**Analogia:** É como tirar uma fotocópia de um documento — você pode rabiscar e modificar à vontade sem alterar o original.

### 🔸 **Branch**
Um **branch** (ramificação) é uma linha independente de desenvolvimento no Git. Permite que você trabalhe em novas funcionalidades ou correções sem afetar o código principal (geralmente no branch `main` ou `master`). Cada branch mantém seu próprio histórico de commits até ser mesclado (merge) com outro branch.

**Analogia:** Imagine um branch como uma cópia temporária do seu projeto onde você pode experimentar mudanças sem "estragar" a versão principal.

### 🔸 **Pull Request (PR)**
Um **Pull Request** é uma proposta de mudança submetida ao repositório. É o mecanismo pelo qual você solicita que suas alterações em um branch sejam revisadas e incorporadas (merged) em outro branch. O PR permite:
- Revisão de código por outros desenvolvedores
- Discussão sobre as mudanças propostas
- Execução automática de testes (CI)
- Aprovação antes do merge

**Analogia:** É como enviar um rascunho para revisão antes de publicar a versão final de um documento.

### 📖 **Leituras Complementares sobre Git**
- [Pro Git Book - Branches](https://git-scm.com/book/pt-br/v2/Branches-no-Git-Branches-em-poucas-palavras)
- [GitHub Flow - Guia Prático](https://docs.github.com/pt/get-started/quickstart/github-flow)
- [Atlassian - Pull Requests](https://www.atlassian.com/br/git/tutorials/making-a-pull-request)

---

## 🤖 **GitHub Actions — O Motor do CI/CD**

### 🔸 **O que é o GitHub Actions?**
O **GitHub Actions** é a plataforma de automação integrada ao GitHub. Ele permite que você defina **workflows** (fluxos de trabalho) que são executados automaticamente em resposta a eventos no repositório — como um push, a abertura de um Pull Request ou um agendamento periódico.

No contexto de CI/CD:
- **CI (Integração Contínua):** a cada push, o workflow pode executar testes automatizados para garantir que o código não quebrou nada.
- **CD (Entrega/Deploy Contínuo):** após a integração, o workflow publica automaticamente o resultado no ambiente de produção — neste caso, o **GitHub Pages**.

Os workflows são descritos em arquivos **YAML** (`.yml`) armazenados na pasta `.github/workflows/` do repositório.

---

### 🔸 **Anatomia do Workflow que você irá criar**

Durante a FASE 3 você criará o arquivo `.github/workflows/deploy.yml`. Abaixo está o conteúdo completo seguido de uma explicação linha a linha:

```yaml
name: Deploy to GitHub Pages          # (1) Nome do workflow exibido na aba Actions

on:                                   # (2) Eventos que disparam o workflow
  push:
    branches: ["main"]                #     – push no branch main
  pull_request:
    branches: ["main"]                #     – abertura de PR apontando para main
  workflow_dispatch:                  #     – execução manual pelo botão na aba Actions

permissions:                          # (3) Permissões concedidas ao workflow
  contents: read                      #     leitura do código-fonte
  pages: write                        #     escrita no GitHub Pages
  id-token: write                     #     necessário para autenticação OIDC no deploy

concurrency:                          # (4) Controle de concorrência
  group: "pages"                      #     agrupa execuções sob o nome "pages"
  cancel-in-progress: false           #     não cancela um deploy em andamento

jobs:                                 # (5) Trabalhos (jobs) do workflow

  build:                              # (5a) Job 1: construção do artefato
    runs-on: ubuntu-latest            #     máquina virtual utilizada
    steps:
      - name: Checkout                #     passo 1 – baixa o código do repositório
        uses: actions/checkout@v4

      - name: Setup Pages             #     passo 2 – configura as opções do GitHub Pages
        uses: actions/configure-pages@v5

      - name: Upload artifact         #     passo 3 – empacota os arquivos para deploy
        uses: actions/upload-pages-artifact@v3
        with:
          path: '.'                   #     publica tudo que está na raiz do repositório

  deploy:                             # (5b) Job 2: publicação no GitHub Pages
    if: github.ref == 'refs/heads/main' && github.event_name == 'push'
                                      #     só executa em push no main (não em PRs)
    environment:
      name: github-pages
      url: ${{ steps.deployment.outputs.page_url }}   # URL gerada automaticamente
    runs-on: ubuntu-latest
    needs: build                      #     aguarda o job "build" concluir com sucesso
    steps:
      - name: Deploy to GitHub Pages
        id: deployment
        uses: actions/deploy-pages@v4 #     ação oficial que publica o artefato
```

### 🔸 **Resumo dos conceitos-chave do YAML**

| Chave | O que faz |
|---|---|
| `name` | Nome exibido na interface do GitHub Actions |
| `on` | Define **quando** o workflow é disparado (eventos) |
| `permissions` | Controla o que o workflow pode fazer no repositório |
| `concurrency` | Evita múltiplos deploys simultâneos do mesmo grupo |
| `jobs` | Lista os trabalhos a executar (podem rodar em paralelo ou em sequência) |
| `runs-on` | Sistema operacional da máquina virtual que executa o job |
| `steps` | Lista de passos sequenciais dentro de um job |
| `uses` | Referencia uma **Action** reutilizável publicada no GitHub Marketplace |
| `needs` | Define dependência entre jobs (o deploy só roda se o build ok) |

> 💡 **Dica:** YAML é sensível à **indentação**. Use sempre 2 espaços (nunca Tab) para cada nível. Um erro de indentação é a causa mais comum de workflows que falham ao serem validados.

---

## 🛠 **Passo a Passo Detalhado**

### 🔹 **FASE 0: Configuração do Git (ESSENCIAL)**

#### **0.1 Configuração de Identidade do Git**
Antes de começar a trabalhar com Git, você **DEVE** configurar sua identidade. O Git precisa saber quem está fazendo os commits.

```bash
# Configuração LOCAL (apenas para este repositório)
git config user.name "Seu Nome Completo"
git config user.email "seu.email@exemplo.com"

# OU Configuração GLOBAL (para todos os repositórios no seu computador)
git config --global user.name "Seu Nome Completo"
git config --global user.email "seu.email@exemplo.com"
```

#### **⚠️ Diferença entre configuração LOCAL vs GLOBAL:**
- **Sem --global:** A configuração vale apenas para o repositório atual. Útil quando você trabalha com diferentes identidades (pessoal vs trabalho).
- **Com --global:** A configuração vale para TODOS os repositórios Git no seu computador. Mais prático para uso pessoal.

#### **0.2 Verificando suas configurações**
```bash
# Ver configurações atuais
git config --list

# Ver apenas nome e email
git config user.name
git config user.email
```

### ✅ **PONTO DE VERIFICAÇÃO #1**
> **Antes de prosseguir, confirme:**
> - [ ] Configurou user.name e user.email no Git
> - [ ] Testou com `git config user.name` e viu seu nome correto
> - [ ] Tem uma conta ativa no GitHub

---

### 🔹 **FASE 1: Fork e Configuração Inicial**

#### **1.1 Fazendo o Fork do Repositório**
1. Faça login na sua conta do **GitHub** (github.com)
2. Acesse o repositório original deste projeto (URL fornecida pelo professor)
3. Clique no botão **"Fork"** (canto superior direito)
4. Na tela de criação do fork:
   - **Owner:** Sua conta pessoal
   - **Repository name:** Pode manter o nome original ou renomear
   - Mantenha marcada a opção **"Copy the `main` branch only"**
5. Clique em **"Create fork"**

> O fork criará uma cópia completa do repositório na sua conta, incluindo o arquivo `index.html`, o workflow de deploy e este roteiro.

#### **1.2 Configuração de Colaboradores**
1. No **seu fork**, vá em **Settings** → **Collaborators** → **Add people**
2. Digite o username ou email do(s) colaborador(es)
3. O colaborador receberá um convite por email que deve aceitar

### ✅ **PONTO DE VERIFICAÇÃO #2**
> **Confirme que:**
> - [ ] O fork do repositório foi criado na sua conta com sucesso
> - [ ] Está configurado como público
> - [ ] O(s) colaborador(es) receberam e aceitaram o convite
> - [ ] O repositório contém os arquivos: `index.html`, `contribuicao.html`, `README.md`
> - [ ] O repositório **não contém** a pasta `.github/workflows/` (ela será criada por você na FASE 3)
> - [ ] Você copiou a URL do seu fork (formato: `https://github.com/seu-usuario/nome-do-repo.git`)

---

### 🔹 **FASE 2: Clonando e Personalizando o Projeto**

#### **2.1 Clonando o Repositório (Fork)**
```bash
# Clone o seu fork (substitua pela URL do SEU fork)
git clone https://github.com/seu-usuario/nome-do-repo.git

# Entre na pasta do projeto
cd nome-do-repo
```

#### **2.2 Personalizando a Página Inicial**
O arquivo `index.html` já existe no repositório. Abra-o no seu editor de texto e personalize:

1. Substitua `[Seu nome aqui]` pelo seu nome real
2. Substitua `[Nome do colaborador]` pelo nome do seu colaborador

#### **2.3 Enviando as Alterações para o GitHub**
```bash
# Adicione as mudanças ao stage
git add index.html

# Faça o commit com mensagem descritiva
git commit -m "feat: personaliza página inicial com nomes da equipe"

# Envie para o GitHub
git push origin main
```

### ✅ **PONTO DE VERIFICAÇÃO #3**
> **Verifique:**
> - [ ] O comando `git status` mostra "working tree clean"
> - [ ] No GitHub, o arquivo `index.html` mostra os nomes atualizados
> - [ ] O commit aparece no histórico com seu nome configurado corretamente

---

### 🔹 **FASE 3: Criação do Workflow e Configuração do GitHub Pages**

Nesta fase você irá ativar o GitHub Pages **antes** de criar o arquivo de workflow do GitHub Actions. Esta ordem é importante: se o Pages não estiver ativado quando o primeiro push do workflow ocorrer, o job de deploy falhará imediatamente.

#### **3.1 Ativando o GitHub Pages**
1. No seu fork no GitHub, vá em **Settings** → **Pages** (menu lateral esquerdo)
2. Em **"Source"**, selecione **"GitHub Actions"**
3. Salve as configurações

> **Nota:** O GitHub Pages precisa estar configurado antes do push do workflow. Assim, quando o Actions executar o deploy pela primeira vez, o ambiente já estará pronto para receber a publicação.

#### **3.2 Criando a estrutura de pastas do workflow**
O GitHub Actions exige que os arquivos de workflow fiquem em `.github/workflows/`. Crie essa estrutura na raiz do repositório clonado:

```bash
# No terminal, dentro da pasta do projeto
# Linux/macOS
mkdir -p .github/workflows

# Windows (PowerShell)
New-Item -ItemType Directory -Force -Path .github\workflows

# Windows (Prompt de Comando — cmd)
mkdir .github\workflows
```

#### **3.3 Criando o arquivo de workflow**
Crie o arquivo `.github/workflows/deploy.yml` no seu editor de texto com o seguinte conteúdo:

```yaml
name: Deploy to GitHub Pages

on:
  push:
    branches: ["main"]
  pull_request:
    branches: ["main"]
  workflow_dispatch:

permissions:
  contents: read
  pages: write
  id-token: write

concurrency:
  group: "pages"
  cancel-in-progress: false

jobs:
  build:
    runs-on: ubuntu-latest
    steps:
      - name: Checkout
        uses: actions/checkout@v4

      - name: Setup Pages
        uses: actions/configure-pages@v5

      - name: Upload artifact
        uses: actions/upload-pages-artifact@v3
        with:
          path: '.'

  deploy:
    if: github.ref == 'refs/heads/main' && github.event_name == 'push'
    environment:
      name: github-pages
      url: ${{ steps.deployment.outputs.page_url }}
    runs-on: ubuntu-latest
    needs: build
    steps:
      - name: Deploy to GitHub Pages
        id: deployment
        uses: actions/deploy-pages@v4
```

> ⚠️ **Atenção à indentação!** YAML usa espaços (não Tab). Copie o conteúdo exatamente como está. Um erro de indentação impedirá o workflow de executar.

> 💡 Releia a seção **"GitHub Actions — O Motor do CI/CD"** acima caso queira entender o que cada bloco do arquivo faz antes de prosseguir.

#### **3.4 Fazendo commit e push do workflow**
```bash
# Adicione o arquivo ao stage
git add .github/workflows/deploy.yml

# Commit com mensagem descritiva
git commit -m "ci: adiciona workflow de deploy automatico no GitHub Pages"

# Push para o GitHub
git push origin main
```

#### **3.5 Verificando o Primeiro Deploy**
O push realizado no passo 3.4 já disparou o workflow automaticamente.

1. Vá na aba **"Actions"** do seu repositório
2. Você verá o workflow **"Deploy to GitHub Pages"** em execução ou já concluído
3. Clique no workflow para inspecionar os detalhes de cada step
4. Aguarde a conclusão (1–3 minutos)
5. Vá em **Settings** → **Pages** — a URL do site aparecerá no formato:
   `https://seu-usuario.github.io/nome-do-repo/`
6. Abra a URL em um navegador e confirme que o site está no ar

### ✅ **PONTO DE VERIFICAÇÃO #4**
> **Confirme que:**
> - [ ] O arquivo `.github/workflows/deploy.yml` foi criado por você e está no repositório
> - [ ] O GitHub Pages está ativado com source **"GitHub Actions"**
> - [ ] O workflow de deploy executou com sucesso (check verde ✅ na aba Actions)
> - [ ] O site está acessível pela URL do GitHub Pages
> - [ ] A página HTML está sendo exibida corretamente no navegador

---

### 🔹 **FASE 4: Fluxo de Trabalho com Branches**

#### **4.1 Criando o Branch de Desenvolvimento**
```bash
# Certifique-se de estar no branch main atualizado
git checkout main
git pull origin main

# Crie e mude para o branch develop
git checkout -b develop

# Envie o branch para o GitHub
git push -u origin develop
```

#### **4.2 Configuração do Colaborador**
O colaborador deve executar:
```bash
# Clone o fork (se ainda não tiver) — use a URL do fork do colega
git clone https://github.com/usuario-principal/nome-do-repo.git
cd nome-do-repo

# Configure sua identidade (se ainda não configurou)
git config user.name "Nome do Colaborador"
git config user.email "email@colaborador.com"

# Baixe informações sobre branches remotos
git fetch origin

# Mude para o branch develop
git checkout develop
```

### ✅ **PONTO DE VERIFICAÇÃO #5**
> **Ambos devem verificar:**
> - [ ] O comando `git branch` mostra que estão no branch `develop`
> - [ ] No GitHub, o branch `develop` aparece na lista de branches
> - [ ] Ambos conseguem fazer `git pull origin develop` sem erros

---

### 🔹 **FASE 5: Implementação de Mudanças Colaborativas**

#### **5.1 Modificações pelo Colaborador**
O colaborador deve modificar o `index.html`, adicionando o conteúdo do arquivo `contribuicao.html` (que já está no repositório) **antes** do fechamento `</body>`.

**Passos:**
1. Abra o arquivo `contribuicao.html` que já está no repositório
2. Copie o conteúdo HTML dele
3. Abra o arquivo `index.html`
4. Cole o conteúdo copiado **antes** da tag `</body>`
5. Personalize substituindo `[Nome do Colaborador]` pelo nome real

> **Dica:** O arquivo `contribuicao.html` serve apenas como referência/modelo. O conteúdo dele deve ser inserido dentro do `index.html`.

#### **5.2 Commit e Push das Alterações**
```bash
# Verifique as mudanças
git status
git diff

# Adicione e faça commit
git add index.html
git commit -m "feat: adiciona seções de alterações recentes e tecnologias

- Lista as implementações realizadas
- Documenta tecnologias utilizadas no projeto
- Adiciona timestamp de última atualização"

# Envie para o GitHub
git push origin develop
```

### ✅ **PONTO DE VERIFICAÇÃO #6**
> **O colaborador deve confirmar:**
> - [ ] As alterações foram commitadas com sucesso
> - [ ] O push foi realizado sem erros
> - [ ] No GitHub, o branch `develop` mostra as novas alterações

---

### 🔹 **FASE 6: Processo de Pull Request e Merge**

#### **6.1 Criando o Pull Request**
1. No GitHub, vá para a página do repositório (fork)
2. Você verá uma notificação sobre o push recente no `develop`
3. Clique em **"Compare & pull request"**
4. Ou vá em **"Pull requests"** → **"New pull request"**

> **⚠️ Atenção:** Certifique-se de que o PR é para o **seu fork** (base: `seu-usuario/nome-do-repo` branch `main`) e **não** para o repositório original do professor.

#### **6.2 Configurando o PR**
- **Base repository:** seu-usuario/nome-do-repo (seu fork)
- **Base branch:** main
- **Compare branch:** develop
- **Título:** "Feature: Adiciona informações do projeto e equipe"
- **Descrição:**
```markdown
## 📋 Descrição
Implementa melhorias na página inicial do projeto, incluindo:
- Seção de alterações recentes
- Lista de tecnologias utilizadas
- Timestamps de atualização

## ✅ Checklist
- [x] Código testado localmente
- [x] HTML válido
- [x] Informações da equipe atualizadas
- [ ] Revisado por outro membro da equipe

## 🔗 Issue relacionada
N/A (primeira iteração)

## 📸 Screenshots
[Adicione screenshots se relevante]
```

#### **6.3 Revisão e Aprovação**
1. Peça para outro membro da equipe revisar
2. O revisor deve:
   - Analisar o código modificado
   - Deixar comentários se necessário
   - Aprovar o PR clicando em **"Review"** → **"Approve"**

#### **6.4 Fazendo o Merge**
1. Após aprovação, clique em **"Merge pull request"**
2. Escolha **"Create a merge commit"**
3. Clique em **"Confirm merge"**
4. Opcionalmente, delete o branch `develop` no GitHub (pode recriar depois)

### ✅ **PONTO DE VERIFICAÇÃO #7**
> **Verifique após o merge:**
> - [ ] O PR foi fechado com status "Merged"
> - [ ] As GitHub Actions iniciaram automaticamente
> - [ ] O workflow de CI/CD está em execução (ícone amarelo girando)
> - [ ] Após conclusão, o workflow mostra check verde ✅

---

### 🔹 **FASE 7: Verificação Final do Deploy**

#### **7.1 Monitorando o GitHub Actions**
1. Vá em **"Actions"** no repositório
2. Você verá o workflow em execução
3. Clique nele para ver os detalhes
4. Acompanhe cada step:
   - Checkout do código
   - Configuração do GitHub Pages
   - Upload do artefato
   - Deploy para GitHub Pages

#### **7.2 Verificando o Site Atualizado**
1. Aguarde o workflow completar (1-3 minutos)
2. Acesse novamente a URL do GitHub Pages: `https://seu-usuario.github.io/nome-do-repo/`
3. Use **Ctrl+F5** para forçar atualização do cache
4. Confirme que as novas seções aparecem

### ✅ **PONTO DE VERIFICAÇÃO #8 - FINAL**
> **Validação completa:**
> - [ ] O site no GitHub Pages mostra a versão atualizada
> - [ ] O histórico de commits mostra contribuições de todos
> - [ ] O GitHub Actions mostra histórico de builds bem-sucedidos
> - [ ] Todos os membros da equipe participaram ativamente

---

## 📊 **Troubleshooting - Problemas Comuns**

### 🔧 **Problema 1: Erro de permissão no push**
**Sintoma:** `error: failed to push some refs`

**Solução:**
```bash
# Atualize seu branch local primeiro
git pull origin develop
# Resolva conflitos se houver
git push origin develop
```

### 🔧 **Problema 2: GitHub Actions falhando**
**Sintoma:** Workflow com X vermelho

**Verificar:**
1. Clique no workflow falho
2. Leia os logs de erro
3. Causa comum: **indentação incorreta** no arquivo YAML (use espaços, nunca Tab)
4. Verifique se o arquivo está em `.github/workflows/deploy.yml` (caminho exato)
5. Verifique se em **Settings → Pages** o source está configurado como **"GitHub Actions"**
6. Confirme que `permissions: pages: write` está presente no arquivo

### 🔧 **Problema 3: Site não atualiza no GitHub Pages**
**Sintoma:** Mudanças não aparecem após deploy

**Soluções:**
1. Limpe o cache do navegador (Ctrl+Shift+Del)
2. Use modo anônimo/privado
3. Verifique se o deploy realmente completou na aba Actions
4. Aguarde alguns minutos — o GitHub Pages pode levar até 10 minutos para propagar

### 🔧 **Problema 4: GitHub Pages mostra erro 404**
**Sintoma:** Página não encontrada ao acessar a URL

**Soluções:**
1. Verifique se o GitHub Pages está ativado em **Settings → Pages**
2. Confirme que o source é **"GitHub Actions"**
3. Verifique se o arquivo `index.html` está na raiz do repositório
4. Aguarde o workflow concluir e tente novamente

### 🔧 **Problema 5: PR vai para o repositório original ao invés do fork**
**Sintoma:** O Pull Request é direcionado ao repositório do professor

**Solução:**
1. Na tela de criação do PR, altere o **"base repository"** para o seu fork
2. Confirme que tanto o base quanto o compare apontam para **seu fork**

---

## � **Evidências de Conclusão das Atividades**

Para comprovar a realização completa desta atividade, cada artefato abaixo é **obrigatório**. Eles demonstram o domínio de cada etapa praticada.

---

### **Evidência 1 — Repositório Fork público**
**O que demonstra:** Você criou um fork e configurou o projeto corretamente.

**Como capturar:**
- Acesse seu fork no GitHub
- A URL deve seguir o formato: `https://github.com/seu-usuario/nome-do-repo`
- Tire uma captura de tela da página principal do repositório mostrando:
  - Seu nome de usuário na URL
  - A indicação `forked from` na parte superior
  - Os arquivos na raiz (`index.html`, `contribuicao.html`, `.github/`)

**Artefato:** captura de tela + link do repositório

---

### **Evidência 2 — Arquivo de Workflow criado**
**O que demonstra:** Você criou manualmente o arquivo de CI/CD (não foi fornecido pronto).

**Como capturar:**
- No seu repositório, navegue até `.github/workflows/deploy.yml`
- Tire uma captura de tela mostrando o **conteúdo do arquivo** na interface do GitHub
- A captura deve exibir o caminho completo do arquivo e parte ou todo o código YAML

**Artefato:** captura de tela do arquivo `.github/workflows/deploy.yml` no GitHub

---

### **Evidência 3 — Workflow executado com sucesso**
**O que demonstra:** O pipeline de CI/CD foi ativado e concluiu sem erros.

**Como capturar:**
- Acesse: GitHub → Repositório → aba **Actions**
- Tire uma captura de tela mostrando:
  - Pelo menos **dois** workflows com status verde (✅ "success")
  - Um referente ao commit inicial do workflow e outro referente ao merge do PR
  - O nome do workflow **"Deploy to GitHub Pages"** deve estar visível

**Artefato:** captura de tela da aba Actions

---

### **Evidência 4 — Site publicado no GitHub Pages**
**O que demonstra:** O deploy automático funcionou e o site está acessível publicamente.

**Como capturar:**
- Acesse a URL do GitHub Pages: `https://seu-usuario.github.io/nome-do-repo/`
- Tire uma captura de tela mostrando:
  - O site carregado no navegador
  - A URL do GitHub Pages visível na barra de endereços
  - O conteúdo atualizado (com os nomes da equipe e as seções adicionadas)

**Artefato:** captura de tela do site no ar + link da URL

---

### **Evidência 5 — Histórico de commits com colaboração**
**O que demonstra:** Todos os membros da equipe realizaram commits no projeto.

**Como capturar:**
- Acesse: GitHub → Repositório → branch `develop` → **Commits**
- Tire uma captura de tela mostrando:
  - Commits de **pelo menos 2 colaboradores diferentes** (nomes/avatares diferentes)
  - Mensagens de commit descritivas

**Artefato:** captura de tela da lista de commits do branch `develop`

---

### **Evidência 6 — Pull Request realizado e mergeado**
**O que demonstra:** Você utilizou o processo de revisão de código antes de integrar as mudanças.

**Como capturar:**
- Acesse: GitHub → Repositório → aba **Pull Requests** → filtro "Closed"
- Abra o PR criado durante a atividade
- Tire uma captura de tela mostrando:
  - Status **"Merged"** (roxo)
  - Título do PR
  - Quem criou e quem aprovou/mergeou
  - O comentário de revisão (se houver)

**Artefato:** captura de tela do PR fechado com status "Merged"

---

### **Evidência 7 — Configuração do GitHub Pages**
**O que demonstra:** Você configurou corretamente a fonte de publicação como "GitHub Actions".

**Como capturar:**
- Acesse: GitHub → Repositório → **Settings** → **Pages**
- Tire uma captura de tela mostrando:
  - Source configurado como **"GitHub Actions"**
  - A URL do site publicado visível na tela

**Artefato:** captura de tela das configurações do GitHub Pages

---

## 📊 **Tabela Resumo das Evidências**

| # | Evidência | Fase relacionada | Obrigatória |
|---|---|---|---|
| 1 | Repositório fork público | FASE 1 | ✅ |
| 2 | Arquivo `deploy.yml` criado no repositório | FASE 3 | ✅ |
| 3 | Workflows com status verde na aba Actions | FASE 3 e 7 | ✅ |
| 4 | Site publicado no GitHub Pages (screenshot + URL) | FASE 3 | ✅ |
| 5 | Histórico de commits com múltiplos colaboradores | FASE 5 | ✅ |
| 6 | Pull Request mergeado | FASE 6 | ✅ |
| 7 | GitHub Pages configurado com source "GitHub Actions" | FASE 3 | ✅ |

---

## 📄 **Entrega da Atividade**

### **Instruções para Entrega via Teams**

Cada integrante do grupo deve enviar **via Microsoft Teams** um único documento compilando todas as evidências:

#### **Artefatos Obrigatórios:**

1. **Link do repositório (fork) no GitHub**
   - Formato: `https://github.com/seu-usuario/nome-do-repo`
   - O repositório deve estar público

2. **Link do site publicado no GitHub Pages**
   - Formato: `https://seu-usuario.github.io/nome-do-repo/`
   - O site deve estar acessível e funcionando

3. **Capturas de tela das 7 evidências listadas acima** (uma por seção)

### **Formato de Envio:**
- Compile os artefatos em um único arquivo `.pdf` ou `.docx`
- Organize as capturas na ordem das evidências (1 a 7)
- Envie através da tarefa criada no Teams até a data limite

---

## 🔗 **Referências e Material de Estudo**

### **Git e Versionamento**
- [Pro Git Book (Português)](https://git-scm.com/book/pt-br/v2) - Livro completo sobre Git
- [Git Cheat Sheet](https://training.github.com/downloads/pt_BR/github-git-cheat-sheet.pdf) - Resumo de comandos
- [Visualizing Git](https://git-school.github.io/visualizing-git/) - Ferramenta interativa
- [Learn Git Branching](https://learngitbranching.js.org/?locale=pt_BR) - Tutorial interativo

### **GitHub e Colaboração**
- [GitHub Flow](https://docs.github.com/pt/get-started/quickstart/github-flow) - Fluxo de trabalho
- [About Pull Requests](https://docs.github.com/pt/pull-requests/collaborating-with-pull-requests/proposing-changes-to-your-work-with-pull-requests/about-pull-requests)
- [GitHub Skills](https://skills.github.com/) - Cursos interativos gratuitos
- [Forking a Repository](https://docs.github.com/pt/pull-requests/collaborating-with-pull-requests/working-with-forks/fork-a-repo) - Guia sobre Forks

### **CI/CD e DevOps**
- [GitHub Actions Documentation](https://docs.github.com/pt/actions)
- [GitHub Pages Documentation](https://docs.github.com/pt/pages)
- [Martin Fowler - Continuous Integration](https://martinfowler.com/articles/continuousIntegration.html)
- [The Phoenix Project](https://www.amazon.com.br/dp/B078Y98RG8/) - Livro sobre DevOps (leitura complementar)

### **Boas Práticas**
- [Conventional Commits](https://www.conventionalcommits.org/pt-br/) - Padrão para mensagens de commit
- [Semantic Versioning](https://semver.org/lang/pt-BR/) - Versionamento semântico
- [The Twelve-Factor App](https://12factor.net/pt_br/) - Metodologia para apps modernas

---

## 💡 **Dicas Extras para Sucesso**

1. **Sempre faça pull antes de push** para evitar conflitos
2. **Commits frequentes e pequenos** são melhores que commits grandes
3. **Mensagens de commit descritivas** ajudam no histórico do projeto
4. **Teste localmente** antes de fazer push (basta abrir o `index.html` no navegador)
5. **Comunique-se** com sua equipe constantemente
6. **Documente** suas decisões e problemas encontrados
7. **Explore** os logs e ferramentas - não tenha medo de experimentar
8. **Verifique o base repository** ao criar PRs em forks — aponte para o seu fork, não o original

---

**Boa sorte e bom aprendizado! 🚀**

