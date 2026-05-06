package pacote_interface;

public class Implementa_Interface implements Classe_Interface {
	protected String fruta_vermelha;
	protected String fruta_citrica;
	
	public String identificaFruta(String fruta) 
	{
		return fruta;
	}

	public int quantidadeFrutas(int quant) 
	{
		return quant;
	}

	public double precoKilo(double preco) 
	{
		return preco;
	}

}
