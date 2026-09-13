package business;

public class Motor 
{
	protected int potencia;
	protected String tipo;
	
	public Motor(int potencia, String tipo)
	{
		this.potencia = potencia;
		this.tipo = tipo;
	}
	
	@Override
	public String toString()
	{
		String retornar = "Potencia: " + this.potencia + " cavalos de potência";
		retornar += "\nTipo do motor: " + this.tipo;
		return retornar;
	}
}
