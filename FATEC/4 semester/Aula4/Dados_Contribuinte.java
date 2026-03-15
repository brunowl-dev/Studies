package Aula4;
//Aula4 package tem encapsulamento_1 e encapsulamento_2
public class Dados_Contribuinte 
{
	private String nome;
	private String CPF;
	private String CNPJ;
	private String cartao;
	
	public void setNome(String nome)
	{
		this.nome = nome;
	}
	
	public void setCPF(String CPF)
	{
		this.CPF = CPF;
	}
	
	public void setCNPJ(String CNPJ)
	{
		this.CNPJ = CNPJ;
	}
	
	public void setCartao(String cartao)
	{
		this.cartao = cartao;
	}
	
	public String getNome()
	{
		return nome;
	}
	
	public String getCPF()
	{
		return CPF;
	}
	
	public String getCNPJ()
	{
		return CNPJ;
	}
	
	public String getCartao()
	{
		return cartao;
	}
}
