package Heranca;

public class Classe_Filha1 extends Superclasse{

	private String atributo2;
	
	Classe_Filha1()
	{
		super();
		System.out.println("Acesso ao método construtor da classe filha 1");
	}
	
	public void set_atributo2(String atributo2)
	{
		this.atributo2 = atributo2;
	}
	
	public String get_atributo2()
	{
		return atributo2;
	}
}
