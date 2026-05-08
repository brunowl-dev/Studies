package Aula2;

public class Transporte 
{
	int assentos, portas;
	String motorista;
	String id;
	String linha;
	
	public Transporte(int assentos, String id, int portas, String linha, String motorista) 
	{
		this.assentos = assentos;
		this.id = id;
		this.portas = portas;
		this.linha = linha;
		this.motorista = motorista;
	}
	
	public int getAssentos()
	{
		return assentos;
	}
	
	public String getId()
	{
		return id;
	}
	
	public int getPortas()
	{
		return portas;
	}
	
	public String getLinha()
	{
		return linha;
	}
	
	public String getMotorista()
	{
		return motorista;
	}
}
