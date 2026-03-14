package Aula5;

public class Dispositivo_Movel {
	//variável com escopo de instância: pode ser alterada por uma nova instância
	public String numero;
	//variáveis com escopo de classe (static)
	public static String usuario;
	public static int DDD;
	
	public void identifica_numero(String numero)
	{
		this.numero = numero;
	}
	
	public void identifica_user(String usuario)
	{
		this.usuario = usuario;
	}
}
