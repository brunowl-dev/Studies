public class Consulta_Cinemas
{
	public static void main(String[] args) 
	{
		Cine_Roxy roxy = new Cine_Roxy();
		Cine_Caicara caicara = new Cine_Caicara("Antigo cinema da\n" + "Av. Conselheiro Nebias - Boqueirao");
		
		caicara.setLoc("Avenida Conselheiro Nebias com a Praia");
		caicara.setNome("Cine Caiçara");
		System.out.println("Cine \t" + caicara.getNome() + "\nficava na esquina da:\t" + caicara.getLoc());

		// 3 - Verificando se a classe Cine Roxy pode ter o atributo nomeCinema
		/*roxy.setNome("Cine Roxy");
		System.out.println("Nome do roxy + " roxy.getNome());*/
		//A Classe Cine Roxy não pode ter esse atributo, pois é um atributo de outra filha (Cinemas_Antigos) de Cinemas_de_Santos
		
		// 4 - Testando classe Cinemas_do_Shopping
		Cinemas_do_Shopping miramar = new Cinemas_do_Shopping();
		miramar.setLoc("Shopping Miramar - Gonzaga");
		miramar.setNome("Cineflix");
		
		System.out.println("Nome do cinema: " + miramar.getNome());
		System.out.println("Localizacao do cinema: " + miramar.getLoc());
	}

}
