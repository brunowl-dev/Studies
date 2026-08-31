package br.edu.eventdriven.pedido;

import java.time.Instant;

public record EventoPedidoCriado(
        String idPedido,
        String idCliente,
        String idProduto,
        int quantidade,
        Instant criadoEm
) {
}
