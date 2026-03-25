public class Veiculo {
	/*
	 * Cadastro de Veículo
	 * 
	 * Dados:
	 * 
	 * Placa
	 * 
	 * Modelo
	 * 
	 * Ano
	 * 
	 * Valor da diária
	 */
	private String placa;
	String modelo;
	int ano;
	double valor;
	
	public Veiculo(String placa, String modelo, int ano, double valor) {
		this.placa = placa;
		this.modelo = modelo;
		this.ano = ano;
		this.valor = valor;
	}
	
	public String getPLACA() {
		return placa;
	}
	
	public String getMODELO() {
		return modelo;
	}
	
	public int getANO() {
		return ano;
	}
	
	public double getVALOR() {
		return valor;
	}
	
}
