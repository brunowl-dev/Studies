package business;

public abstract class Veiculo 
{
	protected String modelo, fabricante;
	protected int ano;
	protected float velocidadeAtual;
	
	public Veiculo(String modelo, String fabricante, int ano)
	{
		this.modelo = modelo;
		this.fabricante = fabricante;
		this.ano = ano;
	}
	
	public void acelerar()
	{
		this.velocidadeAtual += 5;
	}
	
	public void desacelerar()
	{
		this.velocidadeAtual -= 5;
	}
	
	public void parar()
	{
		this.velocidadeAtual = 0;
	}

	public String getModelo() {
		return modelo;
	}

	public void setModelo(String modelo) {
		this.modelo = modelo;
	}

	public String getFabricante() {
		return fabricante;
	}

	public void setFabricante(String fabricante) {
		this.fabricante = fabricante;
	}

	public int getAno() {
		return ano;
	}

	public void setAno(int ano) {
		this.ano = ano;
	}

	public float getVelocidadeAtual() {
		return velocidadeAtual;
	}

}
