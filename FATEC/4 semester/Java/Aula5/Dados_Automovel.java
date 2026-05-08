package Aula5;

public class Dados_Automovel {

	public static void main(String[] args) {
		Automovel2 auto = new Automovel2("Volkswagen", "Fusca", "verde", 6897.99);
		System.out.println(auto.mostra_Automovel());
		
		auto = null;
		System.gc();
		System.out.println(auto.mostra_Automovel());
	}

}
