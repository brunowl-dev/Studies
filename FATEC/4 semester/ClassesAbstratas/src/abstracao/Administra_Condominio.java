package abstracao;

public class Administra_Condominio 
{
	public static void main(String args[])
	{
		Condominio b = new Condominio();
		Conceito c = new Condominio();
		
		//variável do tipo final equivale a uma constante
		final double a = 234.08;
		
		System.out.println("NOME CONDOMINIO " + b.getNomeCondominio());
		System.out.println("VALOR DO CONDOMINIO: R$ " + b.calculaCondominio(a));
		
		c.enderecoCondominio();
		
		/*variável final não pode ser alterada
		 * a = a + 1.0; "erro"*/
		 
		/*um método declarado como final não pode ser sobreescrito
		 * uma classe declarada como final não pode ser herdada*/
	}
}
