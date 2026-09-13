package model;

public class Temperatura 
{
	private float tempCelsius;
	
	public void setCelsius(float tempCelsius)
	{
		this.tempCelsius = tempCelsius;
	}
	
	public float getCelsius()
	{
		return tempCelsius;
	}
	
	public float getFahrenheit()
	{
		return tempCelsius * 1.8f + 32;
	}
}
