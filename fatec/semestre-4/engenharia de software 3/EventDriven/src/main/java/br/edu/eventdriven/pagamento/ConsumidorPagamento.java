package br.edu.eventdriven.pagamento;

import br.edu.eventdriven.configuracao.ConfiguracaoRabbitMQ;
import br.edu.eventdriven.pedido.EventoPedidoCriado;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.amqp.rabbit.annotation.RabbitListener;
import org.springframework.stereotype.Component;

@Component
public class ConsumidorPagamento {

    private static final Logger log = LoggerFactory.getLogger(ConsumidorPagamento.class);

    @RabbitListener(queues = ConfiguracaoRabbitMQ.FILA_PAGAMENTO)
    public void processar(EventoPedidoCriado evento) {
        log.info("Pagamento: processando cobrança do pedido {} para o cliente {}",
                evento.idPedido(), evento.idCliente());

        // TODO didático: criar e publicar um EventoPagamentoAprovado após aprovar o pagamento.
    }
}
