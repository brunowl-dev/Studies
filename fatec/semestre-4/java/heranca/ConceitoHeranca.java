package Heranca;

public final class ConceitoHeranca {

	public static void main(String[] args) {
		Classe_Filha2 filha2 = new Classe_Filha2();

		filha2.set_atributo1("valor do atributo1");
		filha2.set_atributo2("valor do atributo2");
		System.out.println(filha2.get_atributo1());
		System.out.println(filha2.get_atributo2());
	}

}
