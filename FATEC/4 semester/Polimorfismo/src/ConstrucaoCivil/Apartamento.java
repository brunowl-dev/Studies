package ConstrucaoCivil;

public class Apartamento extends Construcao
{
	Construcao apartamento = new Construcao();
	
	Apartamento()
	{
		apartamento.setTipo("APARTAMENTO");
	}
	
	public void Construir()
	{
		System.out.println("FAZ-SE " + apartamento.getTipo());
	}
}
