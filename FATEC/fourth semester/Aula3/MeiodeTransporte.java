package Aula3;

public class MeiodeTransporte 
{
	String prefixo, placa, linha;
	int portas, assentos;
	
	public MeiodeTransporte(String prefixo, String placa, String linha, int portas, int assentos) 
	{
		this.prefixo = prefixo;
		this.placa = placa;
		this.linha = linha;
		this.portas = portas;
		this.assentos = assentos;
	}
	
	public void Informa_Transporte()
	{
		System.out.println("PREFIXO: " + this.getPrefixo());
		System.out.println("PLACA: " + this.getPlaca());
		System.out.println("LINHA: " + this.getLinha());
		System.out.println("PORTAS: " + this.getPortas());
		System.out.println("ASSENTOS: " + this.getAssentos());
	}
	
	public String getPrefixo() 
	{
		return this.prefixo;
	}
	
	public String getPlaca() 
	{
		return this.placa;
	}
	
	public String getLinha() 
	{
		return this.linha;
	}
	
	public int getPortas() 
	{
		return this.portas;
	}
	
	public int getAssentos() 
	{
		return this.assentos;
	}
}
