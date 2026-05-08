package Organiza_Cidade;

public class Regiao_de_Santos extends Cidade_de_Santos 
{
	Regiao_de_Santos()
	{
		super("r");
	}
	
	Regiao_de_Santos(String f)
	{
		super(f);
	}
	
	private String bairro;
	
	public void setBairro(String bairro)
	{
		this.bairro = bairro;
	}
	
	public String getBairro()
	{
		return bairro;
	}
}
