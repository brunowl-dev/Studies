public class Cinemas_Antigos extends Cinemas_de_Santos
{
	private String nomeCinema;
	
	Cinemas_Antigos(String antigo)
	{
		System.out.println("História dos Cinemas de Santos\n" + antigo);
	}
	
	public void setNome(String nome)
	{
		this.nomeCinema = nome;
	}
	
	public String getNome()
	{
		return nomeCinema;
	}
}
