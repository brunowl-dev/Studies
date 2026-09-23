package business;

public class Adicao extends Calculo 
{
	public Adicao(float valor1, float valor2) 
	{
		super(valor1, valor2);
	}
	
	public void calcular() 
	{
		this.resultado = valor1 + valor2;
	}
}
