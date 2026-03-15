package Aula5;

public class Acesso_Objeto {
	public static void main(String[] args) 
	{
		Nome_Classe a = new Nome_Classe();
		/*instância pelo método construtor padrão*/
		
		Nome_Classe b = new Nome_Classe("valor do atributo");
		//versão do método construtor que atribui valor ao atributo
		
		System.out.println("Valor do atributo: " + a.get_atributo());
		System.out.println("Valor do atributo: " + b.get_atributo());
	}
}
