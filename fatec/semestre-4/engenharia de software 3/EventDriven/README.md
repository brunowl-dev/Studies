# Atividade prática: arquitetura event-driven com Java, RabbitMQ e GitHub Codespaces

Este repositório contém uma atividade prática para alunos de graduação explorarem os fundamentos de arquitetura orientada a eventos em um cenário simples de pedidos. A aplicação usa Java 21, Spring Boot, Spring AMQP, RabbitMQ e GitHub Codespaces.

A atividade foi planejada para ser concluída em até **120 minutos**. O foco é executar o sistema, observar o fluxo de eventos, localizar os principais componentes no código e fazer uma pequena alteração controlada em um consumidor.

## Objetivos de aprendizagem

Ao final da atividade, espera-se que o aluno consiga:

- executar uma aplicação Spring Boot integrada ao RabbitMQ;
- publicar um evento a partir de uma requisição HTTP;
- identificar produtor, evento, exchange, filas, bindings e consumidores;
- explicar por que os consumidores são desacoplados do produtor;
- alterar um consumidor simples e demonstrar o efeito nos logs.

## Entregáveis

Cada aluno ou dupla deve entregar um arquivo curto, em PDF ou Markdown, contendo:

1. nome dos integrantes;
2. print ou trecho de `logs/event-driven.log` mostrando a aplicação iniciada;
3. print ou trecho da resposta HTTP de `POST /pedidos`;
4. print ou trecho de `logs/event-driven.log` mostrando os três consumidores processando o mesmo pedido;
5. print ou anotação da interface RabbitMQ mostrando a exchange `pedidos.exchange` e as filas `estoque.queue`, `pagamento.queue` e `notificacao.queue`;
6. nome do arquivo e método onde o evento `EventoPedidoCriado` é publicado;
7. nome dos três consumidores que recebem o evento;
8. evidência da alteração feita no `ConsumidorEstoque` e do teste com `quantidade > 5`;
9. resposta curta: por que o `ControladorPedido` não precisa conhecer os consumidores?

## Critérios de avaliação

- execução da aplicação e envio correto do pedido: 2 pontos;
- identificação correta dos componentes event-driven: 2 pontos;
- evidências de RabbitMQ e logs dos consumidores: 2 pontos;
- alteração funcional no `ConsumidorEstoque`: 2 pontos;
- explicação do desacoplamento entre produtor e consumidores: 2 pontos.

## Fluxo da aplicação

```text
POST /pedidos
  |
  v
ControladorPedido
  |
  v
pedidos.exchange
  |
  +--> estoque.queue      -> ConsumidorEstoque
  +--> pagamento.queue    -> ConsumidorPagamento
  +--> notificacao.queue  -> ConsumidorNotificacao
```

O `ControladorPedido` recebe a requisição HTTP, cria um `EventoPedidoCriado` e publica esse evento na exchange `pedidos.exchange`. Como a exchange é do tipo `fanout`, o mesmo evento é copiado para as três filas ligadas a ela.

## Conceitos essenciais

### Evento

Um evento representa algo que já aconteceu no sistema. Nesta atividade, `EventoPedidoCriado` significa que um pedido foi criado.

### Produtor

O produtor publica o evento. Aqui, o produtor é o `ControladorPedido`.

### Consumidores

Os consumidores reagem ao evento recebido:

- `ConsumidorEstoque` simula reserva de estoque;
- `ConsumidorPagamento` simula processamento de pagamento;
- `ConsumidorNotificacao` simula envio de notificação.

### Exchange, filas e bindings

A exchange `pedidos.exchange` recebe o evento. As filas `estoque.queue`, `pagamento.queue` e `notificacao.queue` armazenam cópias da mensagem até que seus consumidores processem o evento. Os bindings conectam a exchange às filas.

### Desacoplamento

O `ControladorPedido` não chama diretamente estoque, pagamento ou notificação. Ele apenas publica o evento. Isso permite adicionar ou alterar consumidores sem mudar o produtor.

## Ambiente

O ambiente usa dois containers:

- `app`: container de desenvolvimento com Java 21 e Maven;
- `rabbitmq`: container com RabbitMQ e interface web de administração.

Portas usadas:

- `8080`: aplicação Spring Boot;
- `5672`: comunicação AMQP;
- `15672`: RabbitMQ Management.

No RabbitMQ Management, use:

- usuário: `guest`
- senha: `guest`

## Execução básica

No terminal, execute:

```bash
mvn spring-boot:run
```

Depois, abra o arquivo `requests.http` e execute a requisição `POST /pedidos` usando a extensão REST Client do VS Code.

A aplicação também grava os logs em `logs/event-driven.log`. Abra esse arquivo no VS Code para acompanhar os eventos processados sem depender apenas da linha do terminal.

Também é possível testar com `curl`:

```bash
curl -X POST http://localhost:8080/pedidos \
  -H "Content-Type: application/json" \
  -d '{
    "idCliente": "C001",
    "idProduto": "P001",
    "quantidade": 2
  }'
```

Resposta esperada:

```json
{
  "idPedido": "uuid-gerado",
  "orderId": "uuid-gerado",
  "status": "EVENTO_PUBLICADO",
  "message": "EventoPedidoCriado publicado com sucesso",
  "mensagem": "EventoPedidoCriado publicado com sucesso"
}
```

## Roteiro de aula

### Tarefa 1 - Preparar e executar o projeto

**Tempo sugerido:** 15 minutos

Passos:

1. abrir o Codespace ou o projeto no VS Code;
2. executar `mvn spring-boot:run`;
3. confirmar que a aplicação iniciou sem erro.

Entregável: print ou trecho de `logs/event-driven.log` mostrando a aplicação em execução.

### Tarefa 2 - Enviar um pedido

**Tempo sugerido:** 15 minutos

Passos:

1. abrir `requests.http`;
2. executar a requisição `POST /pedidos`;
3. conferir se a resposta contém `status: "EVENTO_PUBLICADO"`;
4. copiar o `idPedido` retornado.

Entregável: print ou trecho da resposta HTTP com o `idPedido`.

### Tarefa 3 - Observar os consumidores

**Tempo sugerido:** 20 minutos

Passos:

1. abrir `logs/event-driven.log` no VS Code;
2. procurar o `idPedido` retornado na Tarefa 2;
3. localizar as mensagens de estoque, pagamento e notificação;
4. verificar se os três logs usam o mesmo `idPedido`.

Entregável: trecho de `logs/event-driven.log` mostrando `ConsumidorEstoque`, `ConsumidorPagamento` e `ConsumidorNotificacao` reagindo ao mesmo pedido.

### Tarefa 4 - Verificar o RabbitMQ

**Tempo sugerido:** 20 minutos

Passos:

1. abrir a porta `15672` no navegador;
2. acessar com usuário `guest` e senha `guest`;
3. localizar a exchange `pedidos.exchange`;
4. localizar as filas `estoque.queue`, `pagamento.queue` e `notificacao.queue`;
5. observar os bindings entre a exchange e as filas.

Entregável: print ou anotação mostrando a exchange, as filas e os bindings.

### Tarefa 5 - Localizar os componentes no código

**Tempo sugerido:** 20 minutos

Passos:

1. localizar a classe `ControladorPedido`;
2. identificar onde o `EventoPedidoCriado` é instanciado;
3. identificar onde o evento é publicado no RabbitMQ;
4. localizar as classes `ConsumidorEstoque`, `ConsumidorPagamento` e `ConsumidorNotificacao`;
5. localizar a configuração da exchange e das filas em `ConfiguracaoRabbitMQ`.

Entregável: lista com os nomes das classes e uma frase explicando a função de cada uma.

### Tarefa 6 - Alterar um consumidor

**Tempo sugerido:** 25 minutos

Passos:

1. abrir `ConsumidorEstoque`;
2. alterar o método `processar` para imprimir um log diferente quando `evento.quantidade() > 5`;
3. reiniciar a aplicação se necessário;
4. enviar um pedido com `quantidade: 6`;
5. verificar o novo log em `logs/event-driven.log`.

Exemplo de comportamento esperado: para quantidade maior que 5, o consumidor deve registrar que a reserva de estoque foi rejeitada ou precisa de análise manual.

Entregável: trecho do código alterado e trecho de `logs/event-driven.log` gerado com `quantidade > 5`.

### Tarefa 7 - Responder à pergunta final

**Tempo sugerido:** 5 minutos

Pergunta: por que o `ControladorPedido` não precisa conhecer diretamente `ConsumidorEstoque`, `ConsumidorPagamento` e `ConsumidorNotificacao`?

Entregável: resposta de 3 a 5 linhas.

## Checklist de conclusão

Antes de entregar, confirme:

- a aplicação iniciou corretamente;
- um pedido foi enviado para `POST /pedidos`;
- os três consumidores processaram o evento;
- a exchange e as filas foram encontradas no RabbitMQ;
- o `ConsumidorEstoque` foi alterado e testado com `quantidade > 5`;
- a pergunta final foi respondida.

## Desafios opcionais

Use apenas se a turma concluir as tarefas principais antes do fim da aula.

### Desafio 1 - Criar uma fila de auditoria

- criar `auditoria.queue`;
- criar `ConsumidorAuditoria`;
- ligar a fila à exchange `pedidos.exchange`;
- registrar todo `EventoPedidoCriado` recebido.

### Desafio 2 - Discutir evolução do fluxo

Sem implementar, responda:

- quando faria sentido publicar um `EventoPagamentoAprovado`?
- uma exchange `fanout` ainda seria suficiente?
- quando uma exchange `topic` seria mais adequada?

## Observações didáticas

As tarefas obrigatórias evitam alterações grandes na configuração do RabbitMQ e no fluxo de pagamento para manter a atividade viável em 120 minutos. Os desafios opcionais podem ser usados em uma segunda aula ou como exercício extra.
