package br.edu.eventdriven.notificacao;

import br.edu.eventdriven.configuracao.ConfiguracaoRabbitMQ;
import br.edu.eventdriven.pedido.EventoPedidoCriado;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.amqp.rabbit.annotation.RabbitListener;
import org.springframework.stereotype.Component;

@Component
public class ConsumidorNotificacao {

    private static final Logger log = LoggerFactory.getLogger(ConsumidorNotificacao.class);

    @RabbitListener(queues = ConfiguracaoRabbitMQ.FILA_NOTIFICACAO)
    public void processar(EventoPedidoCriado evento) {
        log.info("Notificação: enviando confirmação do pedido {} para o cliente {}",
                evento.idPedido(), evento.idCliente());

        // TODO didático: criar um novo consumidor para outro canal de notificação.
    }
}
