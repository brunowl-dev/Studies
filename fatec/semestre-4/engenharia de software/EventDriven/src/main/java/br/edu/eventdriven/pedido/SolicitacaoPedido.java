package br.edu.eventdriven.pedido;

import com.fasterxml.jackson.annotation.JsonAlias;

public record SolicitacaoPedido(
        @JsonAlias("customerId")
        String idCliente,
        @JsonAlias("productId")
        String idProduto,
        @JsonAlias("quantity")
        int quantidade
) {
}
