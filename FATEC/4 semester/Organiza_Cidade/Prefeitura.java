package Organiza_Cidade;

public class Prefeitura {

	public static void main(String[] args) {
		Regiao_de_Santos r = new Regiao_de_Santos();
		Bairro_de_Santos b = new Bairro_de_Santos();
		Cidade_de_Santos c = new Cidade_de_Santos();
		
		/* classe de hierarquia mais inferior dá acesso a todos os atributos */
		b.setBairro("Areia Branca");
		b.setRegiao("Zona Noroeste");
		b.setRua("Jornalista Paulo Matos");
		b.setPopulacao(100000);
		System.out.println("\nBAIRRO: " + b.getBairro());
		System.out.println("REGIÃO: " + b.getRegiao());
		System.out.println("RUA: " + b.getRua());
		System.out.println("POPULAÇÃO: " + b.getPopulacao());
		
		/*não dá acesso aos atributos da classe inferior*/
		r.setRegiao("Zona Oeste");
		r.setBairro("Vila Belmiro");
		r.setPopulacao(99000);
		System.out.println("\nBAIRRO: " + r.getBairro());
		System.out.println("REGIÃO: " + r.getRegiao());
		System.out.println("POPULAÇÃO: " + r.getPopulacao());
		
		c.setRegiao("Região Central");
		c.setPopulacao(20000);
		System.out.println("\nREGIÃO: " + c.getRegiao());
		System.out.println("POPULAÇÃO: " + c.getPopulacao());
		
		Logradouros logradouro = new Logradouros();
		/*
		 * 4. Verificar que atributos e métodos a nova classe “Logradouros” tem acesso.
		 */
		
		System.out.println("\nCLASSE LOGRADOURO");
		logradouro.setBairro("Areia Branca");
		logradouro.setRegiao("Zona Noroeste");
		logradouro.setPopulacao(2000);
		logradouro.setTipo_logradouro("Avenida");
		logradouro.setLocal_logradouro("Jornalista Paulo Matos");
		
		System.out.println("BAIRRO: " + logradouro.getBairro());
		System.out.println("REGIÃO: " + logradouro.getRegiao());
		System.out.println("POPULAÇÃO: " + logradouro.getPopulacao());
		System.out.println("TIPO DE LOGRADOURO: " + logradouro.getTipo_logradouro());
		System.out.println("LOCAL DO LOGRADOURO: " + logradouro.getLocal_logradouro());
	}

}
