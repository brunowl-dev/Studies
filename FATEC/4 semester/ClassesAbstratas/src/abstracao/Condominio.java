package abstracao;

public class Condominio extends Conceito
{
	protected String getNomeCondominio()
	{
		return "Vila Nova";
	}
	
	protected double calculaCondominio(double a)
	{
		return a * 1.066;
	}
	
	//implementação de método abstrato
	public void enderecoCondominio()
	{
		System.out.println("Rua A, n° 22");
	}
}
