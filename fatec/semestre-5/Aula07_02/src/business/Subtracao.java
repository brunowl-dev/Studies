package business;

public class Subtracao extends Calculo 
{
	public Subtracao(float valor1, float valor2) 
	{
		super(valor1, valor2);
	}
	
	public void calcular() 
	{
		this.resultado = valor1 - valor2;
	}
}
