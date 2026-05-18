package Interface;

public class Aplicacao
{
	public static void main(String[] args) 
	{
		BrasileiraoSERIEC torneio = new BrasileiraoSERIEC();
		String[] equipes = {"Volta Redonda", "Remo", "Botafogo-PB"};
		torneio.setEquipes(equipes);
		torneio.setPontos(new int[] {0,0,0});
		
		//Partida-teste
		torneio.partida(0, 1, 0, 1); //Volta Redonda 0 x 1 Remo
		torneio.setCampeao(equipes);
		System.out.println("O campeão é a equipe " + torneio.equipes[torneio.getCampeao()]);
	}
}
