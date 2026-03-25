package Heranca;

public class Superclasse {

	private String atributo_1;
	
	Superclasse()
	{
		System.out.println("Acesso ao método construtor da superclasse");
	}
	
	public void set_atributo1(String atributo_1)
	{
		this.atributo_1 = atributo_1;
	}
	
	public String get_atributo1()
	{
		return atributo_1;
	}
}
