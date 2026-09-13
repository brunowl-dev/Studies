package business;

public class Carro extends Veiculo 
{
	protected int quantidadePortas;
	
	public Carro(String modelo, String fabricante, int ano, int quantidadePortas, int potencia, String tipo)
	{
		super(modelo, fabricante, ano, potencia, tipo);
		this.quantidadePortas = quantidadePortas;
		this.velocidadeAtual = 0;
	}

	public void acelerar()
	{
		if (this.velocidadeAtual < 180)
		{
			this.velocidadeAtual += 5;
		}
	}
	
	public void desacelerar()
	{
		if (this.velocidadeAtual > 0)
		{
			this.velocidadeAtual -= 5;
		}
	}
	
	public void parar()
	{
		this.velocidadeAtual = 0;
	}
	
	public int getQuantidadePortas() {
		return quantidadePortas;
	}

	@Override
	public String toString()
	{
		String retornar = "Carro - " + this.getModelo() + "\nFabricante: " + this.getFabricante() + "\nAno: " + this.getAno() + "\nQuantidade de portas: " + this.getQuantidadePortas() + "\nVelocidade atual: " + this.getVelocidadeAtual() + "km/h\n";
		retornar += this.motor + "\n";
		if (this.manutencao != null)
		{
			retornar += this.manutencao;
		}
		return retornar;
	}
}
