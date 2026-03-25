package Papelaria;

public class Material_Escolar extends Papelaria {
	private double preco_caderno;
	private int quantidade_caixas_lapis;
	
	Material_Escolar()
	{
		super();
	}
	
	Material_Escolar(double preco_caderno, int quantidade_caixas_lapis)
	{
		this.preco_caderno = preco_caderno;
		this.quantidade_caixas_lapis = quantidade_caixas_lapis;
	}
	
	public double get_preco_caderno()
	{
		return preco_caderno;
	}
	
	public int get_quantidade_caixas_lapis()
	{
		return quantidade_caixas_lapis;
	}
}
