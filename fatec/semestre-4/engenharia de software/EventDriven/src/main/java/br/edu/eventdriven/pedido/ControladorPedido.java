package br.edu.eventdriven.pedido;

import java.time.Instant;
import java.util.Map;
import java.util.UUID;

import org.springframework.amqp.rabbit.core.RabbitTemplate;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import br.edu.eventdriven.configuracao.ConfiguracaoRabbitMQ;

@RestController
@RequestMapping({"/pedidos"})
public class ControladorPedido {

    private final RabbitTemplate templateRabbit;

    public ControladorPedido(RabbitTemplate templateRabbit) {
        this.templateRabbit = templateRabbit;
    }

    @PostMapping
    public ResponseEntity<Map<String, String>> criarPedido(@RequestBody SolicitacaoPedido solicitacao) {
        String idPedido = UUID.randomUUID().toString();
        //PedidoCriado instanciado
        EventoPedidoCriado evento = new EventoPedidoCriado(
                idPedido,
                solicitacao.idCliente(),
                solicitacao.idProduto(),
                solicitacao.quantidade(),
                Instant.now()
        );

        //Evento sendo publicado no RabbitMQ
        templateRabbit.convertAndSend(ConfiguracaoRabbitMQ.EXCHANGE_PEDIDOS, "", evento);

        // TODO didático: publicar outros tipos de evento quando o fluxo crescer.
        return ResponseEntity.accepted().body(Map.of(
                "idPedido", idPedido,
                "orderId", idPedido,
                "status", "EVENTO_PUBLICADO",
                "message", "EventoPedidoCriado publicado com sucesso",
                "mensagem", "EventoPedidoCriado publicado com sucesso"
        ));
    }
}
