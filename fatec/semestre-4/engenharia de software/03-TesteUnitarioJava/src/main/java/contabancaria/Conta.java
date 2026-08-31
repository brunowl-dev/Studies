package contabancaria;

/**
 * Classe Conta Bancária — laboratório de Testes Unitários e TDD.
 *
 * INSTRUÇÕES:
 * 1. Leia os requisitos de cada método (javadoc + regras).
 * 2. Escreva os testes PRIMEIRO no arquivo ContaTest.java.
 * 3. Execute os testes e veja-os FALHAR (Red).
 * 4. Implemente o código mínimo para os testes PASSAREM (Green).
 * 5. Refatore se necessário (Refactor).
 */
public class Conta {

    private String titular;
    private double saldo;
    private boolean ativa;

    public String getTitular() {
        return titular;
    }

    public double getSaldo() {
        return saldo;
    }

    public boolean isAtiva() {
        return ativa;
    }

    /**
     * Cria uma conta bancária com saldo inicial.
     * Regras:
     * - O titular não pode ser nulo ou vazio (lançar IllegalArgumentException).
     * - O saldo inicial não pode ser negativo (lançar IllegalArgumentException).
     * - A conta deve ser criada como ativa.
     */
    public Conta(String titular, double saldoInicial) {
        if (titular == null || titular.isBlank())
            throw new IllegalArgumentException("O titular não pode ser nulo ou vazio.");
        if (saldoInicial < 0)
            throw new IllegalArgumentException("O saldo inicial não pode ser negativo.");

        this.titular = titular;
        this.saldo = saldoInicial;
        this.ativa = true;
    }

    /**
     * Cria uma conta bancária com saldo zero.
     */
    public Conta(String titular) {
        this(titular, 0);
    }

    /**
     * Deposita um valor na conta.
     * Regras:
     * - Valor deve ser maior que zero (lançar IllegalArgumentException).
     * - Conta deve estar ativa (lançar IllegalStateException).
     * - O saldo deve ser atualizado corretamente.
     */
    public void depositar(double valor) {
        // TODO: Implemente usando TDD
        if (valor <= 0) {
            throw new IllegalArgumentException();
        } else if (this.isAtiva() == false) {
            throw new IllegalStateException();
        } else {
            this.saldo += valor;
        }
    }

    /**
     * Saca um valor da conta.
     * Regras:
     * - Valor deve ser maior que zero (lançar IllegalArgumentException).
     * - Conta deve estar ativa (lançar IllegalStateException).
     * - Não pode sacar mais do que o saldo (lançar IllegalStateException).
     * - O saldo deve ser atualizado corretamente.
     */
    public void sacar(double valor) {
        // TODO: Implemente usando TDD
        if (valor <= 0) {
            throw new IllegalArgumentException();
        } else if (this.isAtiva() == false) {
            throw new IllegalStateException();
        } else if (valor > this.getSaldo()) {
            throw new IllegalStateException();
        } else {
            this.saldo -= valor;
        }
    }

    /**
     * Transfere valor desta conta para outra.
     * Regras:
     * - As duas contas devem estar ativas (lançar IllegalStateException).
     * - Valor deve ser maior que zero (lançar IllegalArgumentException).
     * - Saldo deve ser suficiente (lançar IllegalStateException).
     * - O saldo de ambas as contas deve ser atualizado corretamente.
     */
    public void transferir(Conta destino, double valor) {
        // TODO: Implemente usando TDD
        if (this.isAtiva() == false || destino.isAtiva() == false) {
            throw new IllegalStateException();
        } else if (valor <= 0) {
            throw new IllegalArgumentException();
        } else if (valor > this.getSaldo()) {
            throw new IllegalStateException();
        } else {
            this.saldo -= valor;
            destino.saldo += valor;
        }
    }

    /**
     * Encerra a conta.
     * Regras:
     * - A conta já deve estar ativa (lançar IllegalStateException se já inativa).
     * - O saldo deve ser zero para encerrar (lançar IllegalStateException se houver
     * saldo).
     * - A propriedade ativa deve ser alterada para false.
     */
    public void encerrar() {
        // TODO: Implemente usando TDD
        if (this.isAtiva() == false) {
            throw new IllegalStateException();
        } 
        else if (this.getSaldo() != 0) {
            throw new IllegalStateException();
        }
        else
        {
            this.ativa = false;
        }
    }
}
