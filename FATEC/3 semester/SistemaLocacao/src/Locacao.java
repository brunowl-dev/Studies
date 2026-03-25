public class Locacao {
	/*
	 * Dados:
	 * 
	 * Cliente (selecionado da lista de clientes)
	 * 
	 * Veículo (selecionado da lista de veículos)
	 * 
	 * Quantidade de dias
	 * 
	 * Valor total (calculado automaticamente = diária × dias)
	 */
	private static Cliente cliente;
	private static Veiculo veiculo;
	int dias;
	double valor;
	
	public Locacao(Cliente cliente, Veiculo veiculo, int dias) {
		this.cliente = cliente;
		this.veiculo = veiculo;
		this.dias = dias;
		this.valor = veiculo.getVALOR() * dias;
	}
	
	public String getNomeCliente() {
		return cliente.getNOME();
	}
	
	public String getPlacaCliente() {
		return veiculo.getPLACA();
	}
	
	public double getTotal() {
		return valor;
	}
}
