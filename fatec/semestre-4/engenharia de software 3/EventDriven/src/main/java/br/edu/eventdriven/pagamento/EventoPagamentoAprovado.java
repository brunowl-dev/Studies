package br.edu.eventdriven.pagamento;

import java.time.Instant;

public record EventoPagamentoAprovado(
        String idPedido,
        String idCliente,
        Instant aprovadoEm
) {
}
