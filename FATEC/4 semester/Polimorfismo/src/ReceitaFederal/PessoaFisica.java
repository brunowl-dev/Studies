package ReceitaFederal;

public class PessoaFisica extends Contribuinte {
	private String rg;
	
	public void setRG(String rg)
	{
		this.rg = rg;
	}
	
	public String getRG()
	{
		return rg;
	}
	
	public void mostraClasse()
	{
		System.out.println("CLASSE PESSOA FISICA");
	}
}
