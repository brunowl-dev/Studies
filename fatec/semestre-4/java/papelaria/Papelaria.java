package Papelaria;

public class Papelaria {
	private String caderno;
	private String lapis;
	
	Papelaria ()
	{
		System.out.println("Acesso ao método construtor padrão da superclasse Papelaria\n");
	}
	
	Papelaria(String lapis)
	{
		this.lapis = lapis;
	}
	
	public void set_caderno(String caderno)
	{
		this.caderno = caderno;
	}
	
	public String get_caderno()
	{
		return caderno;
	}
	
	public String get_lapis()
	{
		return lapis;
	}
}
