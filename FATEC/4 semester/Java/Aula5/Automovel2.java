package Aula5;

public class Automovel2 
{
	private String marca;
	private String modelo;
	private String cor;
	private double preco;
	
	Automovel2(String marca, String modelo, String cor, double preco)
	{
		this.marca = marca;
		this.modelo = modelo;
		this.cor = cor;
		this.preco = preco;
	}
	
	String dados;
	
	public String mostra_Automovel()
	{
		String dados = "MARCA:\t" + marca + "\n" + "MODELO:\t" + modelo + "\n" + "COR:\t" + cor + "\n" + "PREÇO:\t" + preco + "\n";
		return dados;
	}
}
