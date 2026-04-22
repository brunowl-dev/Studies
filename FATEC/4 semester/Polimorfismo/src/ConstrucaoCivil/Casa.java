package ConstrucaoCivil;

public class Casa extends Construcao
{
	Construcao casa = new Construcao();
	
	public Casa()
	{
		casa.setTipo("Casa");
	}
	
	public void Construir()
	{
		System.out.println("FAZ-SE " + casa.getTipo());
	}
}
