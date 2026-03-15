package encapsulamento_2;

import encapsulamento_1.Acesso_Numeros;

public class Verifica_Encapsulamento_2 {

	public static void main(String[] args) 
	{
		Acesso_Numeros chave = new Acesso_Numeros();
		//chave.a = 10;
		chave.setNumero("a", 10);
		chave.b = 20;
		//chave.c = 30;
		chave.setNumero("c", 30);
		//chave.d = 40;
		chave.setNumero("d", 40);
		
		chave.mostra_numero();
	}

}
