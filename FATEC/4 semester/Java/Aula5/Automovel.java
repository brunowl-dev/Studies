package Aula5;

public class Automovel 
{
	private int ano;
	private String marca;
	private String modelo;
	private static String cor;
	private double preco;
	
	//método construtor
	Automovel () {}
	//método construtor
	Automovel (int ano, String marca, String modelo, double preco)
	{
		this.ano = ano;
		this.marca = marca;
		this.modelo = modelo;
		this.preco = preco;
	}
	
	static 
	{
		cor = "verde";
	}
		
	public void mostraCarro()
	{
		System.out.println("\nMarca do Carro:\t"+ marca + "\nmodelo: \t" + modelo + "\nano:\t" + ano + "\ncor: \t" + cor + "\npreço:\t" + preco);
	}
}
