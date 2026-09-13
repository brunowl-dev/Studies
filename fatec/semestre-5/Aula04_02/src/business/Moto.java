package business;

public class Moto extends Veiculo
{
	protected boolean descansoAcionado;
	
	public Moto(String modelo, String fabricante, int ano)
	{
		super(modelo, fabricante, ano);
		this.velocidadeAtual = 0;
		descansoAcionado = true;
	}

	
	
	public boolean isDescansoAcionado() {
		return descansoAcionado;
	}

	public void acelerar()
	{
		if (this.velocidadeAtual < 180)
		{
			this.velocidadeAtual += 2.5;
			descansoAcionado = false;
		}
	}
	
	public void desacelerar()
	{
		if (this.velocidadeAtual > 0)
		{
			this.velocidadeAtual -= 2.5;
			if (velocidadeAtual == 0)
			{
				descansoAcionado = true;
			}
		}
	}
	
	public void parar()
	{
		this.velocidadeAtual = 0;
		descansoAcionado = true;
	}
	
	@Override
	public String toString()
	{
		String retornar = "Moto - " + this.getModelo() + "\nFabricante: " + this.getFabricante() + "\nAno: " + this.getAno() + "\nDescanso acionado: " + this.isDescansoAcionado() + "\nVelocidade atual: " + this.getVelocidadeAtual() + "km/h";
		return retornar;
	}
}
