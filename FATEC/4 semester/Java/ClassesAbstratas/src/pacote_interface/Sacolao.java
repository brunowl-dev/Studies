package pacote_interface;

public class Sacolao {
	public static void main(String[] args) 
	{
		Implementa_Interface a = new Implementa_Interface();
		a.fruta_citrica = "laranja";
		a.fruta_vermelha = "maçã";
		
		System.out.println("Fruta Cítrica: \t" + a.identificaFruta(a.fruta_citrica));
		System.out.println("Fruta Vermelha: \t" + a.identificaFruta(a.fruta_vermelha));
		
		System.out.println("Quantidade de frutas: \t" + a.quantidadeFrutas(12));
		System.out.println("Preço do kilo das frutas: \tR$ " + a.precoKilo(5.66));
	}
}
