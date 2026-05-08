package encapsulamento_1;

public class Acesso_Numeros 
{
	
	int a; //Quando o encapsulamento é omitido, a variável é package private
	public int b; //NUNCA se deve declarar um public em POO
	private int c; //PADRÃO de POO
	protected int d; 
	
	public void setNumero(String id, int numero)
	{
		if (id == "a")
		{
			this.a = numero;		
		}
		
		if (id == "c")
		{
			this.c = numero;		
		}
		
		if (id == "d")
		{
			this.d = numero;		
		}
		
	}
	
	public void mostra_numero()
	{
		System.out.println("numero a = " + a);
		System.out.println("numero b = " + b);
		System.out.println("numero c = " + c);
		System.out.println("numero d = " + d);
	}
}
