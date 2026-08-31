package br.edu.eventdriven.estoque;

import br.edu.eventdriven.configuracao.ConfiguracaoRabbitMQ;
import br.edu.eventdriven.pedido.EventoPedidoCriado;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.amqp.rabbit.annotation.RabbitListener;
import org.springframework.stereotype.Component;

@Component
public class ConsumidorEstoque {

    private static final Logger log = LoggerFactory.getLogger(ConsumidorEstoque.class);

    @RabbitListener(queues = ConfiguracaoRabbitMQ.FILA_ESTOQUE)
    public void processar(EventoPedidoCriado evento) {
        // TODO didático: rejeitar reservas quando quantidade > 5.
        if (evento.quantidade() <= 5)
        {
            log.info("Estoque: reservando {} unidade(s) do produto {} para o pedido {}",
                evento.quantidade(), evento.idProduto(), evento.idPedido());
        }
        else 
        {
            log.info("Estoque GRANDE: reservando {} unidade(s) do produto {} para o pedido {}",
                evento.quantidade(), evento.idProduto(), evento.idPedido());
        }
    }
}
