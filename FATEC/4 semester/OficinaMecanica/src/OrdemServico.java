public class OrdemServico 
{
	/*
	 * 3-Criar uma classe chamada Ordem_Serviço, onde possa ser definido o método
	 * polimorfo a ser utilizado.
	 */
	
	public OficinaMecanica Encapsula_Instancia(int tipo, OficinaMecanica carro)
	{
		switch(tipo)
		{
		case 1:
			carro = new OficinaMecanica();
			break;
		case 2:
			carro = new ConcessionariaVolks();
			break;
		case 3:
			carro = new ConcessionariaFord();
			break;
		}
		
		return carro;
	}
}
