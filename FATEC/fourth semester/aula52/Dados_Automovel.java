package aula52;

public class Dados_Automovel {

	public static void main(String[] args) {
		Automovel auto = new Automovel("Volkswagen", "Fusca", "Verde", 6897.99);
		System.out.println(auto.mostra_automovel());
		
		auto = null;
		System.gc();
		System.out.println(auto.mostra_automovel());

	}

}
