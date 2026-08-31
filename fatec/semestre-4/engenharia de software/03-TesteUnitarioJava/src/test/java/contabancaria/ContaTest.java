package contabancaria;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertThrows;
import static org.junit.jupiter.api.Assertions.assertTrue;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.CsvSource;

/**
 * Testes unitários para a classe Conta.
 *
 * PARTE 1 — Testes de exemplo (Construtor) já estão prontos.
 * Observe o padrão AAA e o uso de @Test e @ParameterizedTest.
 *
 * PARTE 2 — Você deve escrever os testes para os demais métodos
 * seguindo rigorosamente o ciclo TDD: Red → Green → Refactor.
 *
 * Para cada método da classe Conta, crie testes que cubram:
 * ✅ O cenário de sucesso (caminho feliz)
 * ❌ Cada regra de validação (cenários de exceção)
 * 🔄 Casos de borda (valores limites)
 */
class ContaTest {

    // =======================================================
    // PARTE 1 — EXEMPLO GUIADO: Testes do Construtor
    // Observe o padrão Arrange-Act-Assert (AAA)
    // =======================================================

    @Test
    void construtor_DadosValidos_CriaContaCorretamente() {
        // Arrange & Act
        var conta = new Conta("Maria", 100);

        // Assert
        assertEquals("Maria", conta.getTitular());
        assertEquals(100, conta.getSaldo());
        assertTrue(conta.isAtiva());
    }

    @Test
    void construtor_SemSaldoInicial_CriaContaComSaldoZero() {
        // Arrange & Act
        var conta = new Conta("João");

        // Assert
        assertEquals("João", conta.getTitular());
        assertEquals(0, conta.getSaldo());
        assertTrue(conta.isAtiva());
    }

    @Test
    void construtor_TitularNulo_LancaIllegalArgumentException() {
        // Assert — verifica que a exceção é lançada
        assertThrows(IllegalArgumentException.class, () -> new Conta(null));
    }

    @Test
    void construtor_TitularVazio_LancaIllegalArgumentException() {
        assertThrows(IllegalArgumentException.class, () -> new Conta(""));
    }

    @Test
    void construtor_SaldoNegativo_LancaIllegalArgumentException() {
        assertThrows(IllegalArgumentException.class, () -> new Conta("Maria", -50));
    }

    @ParameterizedTest
    @CsvSource({
            "Ana,    0",
            "Carlos, 1000",
            "Beatriz, 0.01"
    })
    void construtor_VariosValoresValidos_CriaContaCorretamente(String titular, double saldo) {
        // Act
        var conta = new Conta(titular, saldo);

        // Assert
        assertEquals(titular, conta.getTitular());
        assertEquals(saldo, conta.getSaldo(), 0.001);
        assertTrue(conta.isAtiva());
    }

    // =======================================================
    // PARTE 2 — ESCREVA OS TESTES ABAIXO (TDD)
    // Lembre-se: escreva o teste PRIMEIRO, veja FALHAR (Red),
    // depois implemente o código para PASSAR (Green),
    // e por fim faça Refactor se necessário.
    // =======================================================

    // =======================================================
    // Testes para depositar
    // Sugestão de testes:
    // - Depósito com valor válido atualiza o saldo - DONE
    // - Depósito com valor zero lança IllegalArgumentException - DONE
    // - Depósito com valor negativo lança IllegalArgumentException - DONE
    // - Depósito em conta inativa lança IllegalStateException - DONE
    // =======================================================
    @Test
    void depositar_ValorValido_AtualizaSaldo() {
        // - Depósito com valor válido atualiza o saldo
        var conta = new Conta("Bruno", 10);
        conta.depositar(10);

        assertEquals(20, conta.getSaldo());
    }

    @Test
    void depositar_Zero_IllegalArgumentException() {
        // - Depósito com valor zero lança IllegalArgumentException
        var conta = new Conta("Bruno");
        assertThrows(IllegalArgumentException.class, () -> conta.depositar(0));
    }

    @Test
    void depositar_ValorNegativo_IllegalArgumentException() {
        // - Depósito com valor negativo lança IllegalArgumentException
        var conta = new Conta("Bruno");
        assertThrows(IllegalArgumentException.class, () -> conta.depositar(-10));
    }

    @Test
    void depositar_ContaInativa_IllegalStateException() {
        // - Depósito em conta inativa lança IllegalStateException
        var conta = new Conta("Bruno");
        conta.encerrar();

        assertThrows(IllegalStateException.class, () -> conta.depositar(10));
    }

    // =======================================================
    // Testes para sacar
    // Sugestão de testes:
    // - Saque com valor válido atualiza o saldo - DONE
    // - Saque com valor maior que saldo lança IllegalStateException - DONE
    // - Saque com valor zero lança IllegalArgumentException - DONE
    // - Saque com valor negativo lança IllegalArgumentException - DONE
    // - Saque em conta inativa lança IllegalStateException - DONE
    // =======================================================
    @Test
    void saque_ValorValido_AtualizaSaldo() {
        // - Saque com valor válido atualiza o saldo
        var conta = new Conta("Bruno", 100);
        conta.sacar(100);

        assertEquals(0, conta.getSaldo());
    }

    @Test
    void saque_ValorMaiorqueSaldo_IllegalStateException() {
        // - Saque com valor maior que saldo lança IllegalStateException
        var conta = new Conta("Bruno", 10);
        double valorSaque = 20;
        assertThrows(IllegalStateException.class, () -> conta.sacar(valorSaque));
    }

    @Test
    void saque_ValorZero_IllegalArgumentException() {
        // - Saque com valor zero lança IllegalArgumentException
        var conta = new Conta("Bruno", 10);

        assertThrows(IllegalArgumentException.class, () -> conta.sacar(0));
    }

    @Test
    void saque_ValorNegativo_IllegalArgumentException() {
        // - Saque com valor negativo lança IllegalArgumentException
        var conta = new Conta("Bruno", 10);
        assertThrows(IllegalArgumentException.class, () -> conta.sacar(-10));
    }

    @Test
    void saque_ContaInativa_IllegalStateException() {
        // - Saque em conta inativa lança IllegalStateException
        var conta = new Conta("Bruno");
        conta.encerrar();
        assertThrows(IllegalStateException.class, () -> conta.sacar(10));
    }

    // =======================================================
    // Testes para transferir
    // Sugestão de testes:
    // - Transferência válida atualiza saldo de ambas as contas - DONE
    // - Transferência com saldo insuficiente lança exceção - DONE
    // - Transferência com valor zero/negativo lança exceção - DONE
    // - Transferência com conta origem inativa lança exceção - DONE
    // - Transferência com conta destino inativa lança exceção - DONE
    // =======================================================
    @Test
    void transf_AtualizaSaldo() {
        // - Transferência válida atualiza saldo de ambas as contas
        var conta1 = new Conta("Bruno", 10);
        var conta2 = new Conta("Wai Lu", 0);

        conta1.transferir(conta2, 10);

        assertEquals(0, conta1.getSaldo());
        assertEquals(10, conta2.getSaldo());
    }

    @Test
    void transf_SaldoInsuficiente_IllegalStateException() {
        // - Transferência com saldo insuficiente lança exceção
        var conta1 = new Conta("Bruno", 10);
        var conta2 = new Conta("Wai Lu", 0);
        assertThrows(IllegalStateException.class, () -> conta1.transferir(conta2, 20));
    }

    @Test
    void transf_valorZeroNegativo_IllegalArgumentException() {
        // - Transferência com valor zero/negativo lança exceção
        var conta1 = new Conta("Bruno", 10);
        var conta2 = new Conta("Wai Lu", 0);
        assertThrows(IllegalArgumentException.class, () -> conta1.transferir(conta2, 0));
    }

    @Test
    void transf_OrigemInativa_IllegalStateException() {
        // - Transferência com conta origem inativa lança exceção
        var conta1 = new Conta("Bruno");
        var conta2 = new Conta("Wai Lu");
        conta1.encerrar();
        assertThrows(IllegalStateException.class, () -> conta1.transferir(conta2, 10));
    }

    @Test
    void transf_DestinoInativo_IllegalStateException() {
        // - Transferência com conta destino inativa lança exceção
        var conta1 = new Conta("Bruno", 10);
        var conta2 = new Conta("Wai Lu", 0);
        conta2.encerrar();
        assertThrows(IllegalStateException.class, () -> conta1.transferir(conta2, 10));
    }

    // =======================================================
    // Testes para encerrar
    // Sugestão de testes:
    // - Encerrar conta com saldo zero funciona - DONE
    // - Encerrar conta com saldo lança IllegalStateException
    // - Encerrar conta já inativa lança IllegalStateException
    // - Conta encerrada tem isAtiva() == false
    // =======================================================

    @Test
    void encerrar_SaldoZero() {
        // - Encerrar conta com saldo zero funciona
        var conta = new Conta("Bruno");
        conta.encerrar();
        assertEquals(false, conta.isAtiva());
    }

    @Test
    void encerrar_ContaSaldo_IllegalStateException() {
        // - Encerrar conta com saldo lança IllegalStateException
        var conta = new Conta("Bruno", 10);
        assertThrows(IllegalStateException.class, () -> conta.encerrar());
    }

    @Test
    void encerrar_ContaInativa_IllegalStateException() {
        // - Encerrar conta já inativa lança IllegalStateException
        var conta = new Conta("Bruno", 10);
        assertThrows(IllegalStateException.class, () -> conta.encerrar());
    }

    @Test
    void encerrar_Verificar() {
        // - Conta encerrada tem isAtiva() == false
        var conta = new Conta("Bruno");
        conta.encerrar();

        assertEquals(false, conta.isAtiva());
    }

}
