package Feira;

public abstract class Feira 
{
	Fazer_feira comprar;
	
	public Feira() {};
	
	public void setFruta(Fazer_feira fruta)
	{
		comprar = fruta;
	}
	
	public void setVerdura(Fazer_feira verdura)
	{
		comprar = verdura;
	}
	
	public void comprarFruta()
	{
		comprar.comprar();
	}
	
	public void comprarVerdura()
	{
		comprar.comprar();
	}
}
