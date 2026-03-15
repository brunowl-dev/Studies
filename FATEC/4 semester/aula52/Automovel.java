package aula52;

public class Automovel 
{
	private String marca;
	private String modelo;
	private String cor;
	private double preco;
	
	Automovel(String marca, String modelo, String cor, double preco)
	{
		this.marca = marca;
		this.modelo = modelo;
		this.cor = cor;
		this.preco = preco;
	}
	
	String dados;
	
	public String mostra_automovel()
	{
		dados = "MARCA:\t" + marca + "\n" + "MODELO:\t" + modelo + "\n" + "COR:\t" + cor + "\n" + "PREÇO:\t" + preco + "\n";
		return dados;
	}
}
