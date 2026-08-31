package Organiza_Cidade;

public class Logradouros extends Regiao_de_Santos{
	
	Logradouros()
	{ 
		super("l");
	}
	
	Logradouros(String l) 
	{ 
		super(l);
	}
	
	/*
	 * 2. Adicionar à aplicação uma classe chamada “Logradouros”, com extensão para
	 * Região_de_Santos, com os atributos “tipo_logradouro” e “local_logradouro”,
	 * ambos do tipo string.
	 */
	
	private String tipo_logradouro;
	private String local_logradouro;
	
	public void setTipo_logradouro(String tipoLog)
	{
		this.tipo_logradouro = tipoLog;
	}
	
	public void setLocal_logradouro(String locLog)
	{
		this.local_logradouro = locLog;
	}
	
	public String getTipo_logradouro()
	{
		return tipo_logradouro;
	}
	
	public String getLocal_logradouro()
	{
		return local_logradouro;
	}
	
	
	
	
}
