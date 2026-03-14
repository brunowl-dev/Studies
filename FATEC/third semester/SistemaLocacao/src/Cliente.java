public class Cliente {
	/*
	 * Cadastro de Cliente
	 * 
	 * Dados:
	 * 
	 * Nome completo
	 * 
	 * CPF
	 * 
	 * Telefone
	 * 
	 * Endereço
	 */
	private String cpf;
	String nome, tel, endereco;
	
	public Cliente(String cpf, String nome, String tel, String endereco) {
		this.cpf = cpf;
		this.nome = nome;
		this.tel = tel;
		this.endereco = endereco;
	}
	
	public String getCPF() {
		return cpf;
	}
	
	public String getNOME() {
		return nome;
	}
	
	public String getTEL() {
		return tel;
	}
	
	public String getEND() {
		return endereco;
	}
}
