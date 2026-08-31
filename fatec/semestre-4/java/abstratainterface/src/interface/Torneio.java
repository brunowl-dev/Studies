package Interface;

public interface Torneio 
{
	//Nome do torneio
	public String getNome();
	public void setNome(String nome);
	
	//Array com os times
	public String[] getEquipes();
	public void setEquipes(String[] equipes);
	
	//Array com os pontos
	public int[] getPontos();
	public void setPontos(int[] pontos);
	
	//Partida
	public void partida(int indexTime1, int indexTime2, int pontos1, int pontos2);
	
	//Decide campeao
	public void setCampeao(String[] equipes);
	public int getCampeao();
}
