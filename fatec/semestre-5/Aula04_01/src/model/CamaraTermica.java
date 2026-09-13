package model;

public class CamaraTermica 
{
	private Temperatura tempMinima, tempMaxima;
	
	public Temperatura getTemperaturaMinima()
	{
		return tempMinima;
	}
	
	public Temperatura getTemperaturaMaxima()
	{
		return tempMaxima;
	}
	
	public CamaraTermica(float temperaturaMinima, float temperaturaMaxima)
	{
		tempMinima = new Temperatura();
		tempMinima.setCelsius(temperaturaMinima);
		
		tempMaxima = new Temperatura();
		tempMaxima.setCelsius(temperaturaMaxima);
	}
}
