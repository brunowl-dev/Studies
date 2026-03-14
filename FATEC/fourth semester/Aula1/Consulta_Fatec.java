package Aula1;

public class Consulta_Fatec 
{
	public static void main(String[] args) 
	{
		Fatec f = new Fatec("Baixada Santista", "ADS");
		System.out.printf("Unidade: %s\nCurso: %s\n", f.getUnidade(), f.getCurso());
	}

}
