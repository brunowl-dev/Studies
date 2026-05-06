package abstracao;

public class Aplicacao {
	public static void main(String[] args) 
	{
		Classe_Abstrata a = new Classe_Filha();
		a.setMensagem("Demonstrando Classe Abstrata");
		a.mostraMensagem();
	}
}
