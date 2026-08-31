package Interface;

public class BrasileiraoSERIEC implements Torneio
{
	protected String nome = "Brasileirao Serie C";
	protected String[] equipes = new String[3];
	protected int[] pontos = new int[3];
	protected int indexCampeao;
	protected int maiorPonto;

	public String getNome()
	{
		return nome;
	}
	
	public void setNome(String nome)
	{
		this.nome = nome;
	}
	
	public String[] getEquipes()
	{
		return equipes;
	}
	
	public void setEquipes(String[] equipes)
	{
		for (int i = 0; i < 3; i++)
		{
			this.equipes[i] = equipes[i];
		}
	}
	
	public int[] getPontos()
	{
		return pontos;
	}
	
	public void setPontos(int[] pontos)
	{
		for (int i = 0; i < 3; i++)
		{
			this.pontos[i] = pontos[i];
		}
	}
	
	public void partida(int indexTime1, int indexTime2, int pontos1, int pontos2)
	{
		if (pontos1 > pontos2)
		{
			pontos[indexTime1] += 3;
		}
		else if (pontos2 > pontos1)
		{
			pontos[indexTime2] += 3;
		}
		else
		{
			pontos[indexTime1] += 1;
			pontos[indexTime2] += 1;
		}
	}
	
	public void setCampeao(String[] equipes)
	{
		int encontrar = this.pontos[0];
		for (int i = 1; i < 3; i++)
		{
			if (this.pontos[i] > encontrar)
			{
				encontrar = this.pontos[i];
			}
		}
		this.maiorPonto = encontrar;
	}
	
	public int getCampeao()
	{
		int i;
		for (i = 0; i < 3; i++)
		{
			if (pontos[i] == maiorPonto)
			{
				this.indexCampeao = i;
			}
		}
		
		return indexCampeao;
	}
}
