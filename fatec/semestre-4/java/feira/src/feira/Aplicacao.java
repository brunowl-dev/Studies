package Feira;

public class Aplicacao 
{
	public static void main (String[] args)
	{
		Feira fruta = new Fruta();
		fruta.setFruta(fruta.comprar);
		fruta.comprarFruta();
		
		Feira verdura = new Verdura();
		verdura.setVerdura(verdura.comprar);
		verdura.comprarVerdura();
	}
}
