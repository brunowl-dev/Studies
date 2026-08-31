package Organiza_Cidade;

public class Cidade_de_Santos 
{
	private String regiao;
	private int populacao;
	
	Cidade_de_Santos() {}
	
	Cidade_de_Santos(String secretaria)
	{
		if (secretaria == "r") 
		{
			System.out.println("Secretaria de Regionais");
		}
		else if (secretaria == "b")
		{
			System.out.println("Secretaria de Bairros");
		}
		else if (secretaria == "l")
		{
			/*
			 * 3. Inserir na superclasse, no método construtor, uma mensagem impressa como
			 * foi feito para região e bairro. Acessar o método construtor da superclasse
			 * através do método super( )
			 */
			System.out.println("Secretaria de Logradouros");
		}
	}
	
	public void setRegiao(String regiao)
	{
		this.regiao = regiao;
	}
	
	public void setPopulacao(int populacao)
	{
		this.populacao = populacao;
	}
	
	public String getRegiao()
	{
		return regiao;
	}
	
	public int getPopulacao()
	{
		return populacao;
	}
}
