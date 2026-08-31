package abstracao;

public abstract class Conceito 
{
	private String nome_condominio;
	private double despesa_condominio;
	
	protected String getNomeCondominio()
	{
		return nome_condominio;
	}
	
	protected double calculaCondominio(double despesa_condominio)
	{
		this.despesa_condominio = despesa_condominio;
		return despesa_condominio;
	}
	
	/*
	 * método abstrato não pode ser implementado na própria classe o fato de haver
	 * um método abstrato na classe obriga a mesma a ser abstrata
	 */
	public abstract void enderecoCondominio();
}
