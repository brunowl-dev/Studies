package Papelaria;

public class Caneta extends Material_Escolar{
	private double espessura;
	private String marca;
	private String cor;
	
	Caneta()
	{
		super();
	}
	
	Caneta(double espessura, String marca, String cor)
	{
		this.espessura = espessura;
		this.marca = marca;
		this.cor = cor;
	}
	
	public double get_espessura()
	{
		return espessura;
	}
	
	public String get_marca()
	{
		return marca;
	}
	
	public String get_cor()
	{
		return cor;
	}
}
