package business;

public abstract class Pessoa {
	protected String nome, email;
	
	public Pessoa(String nome, String email)
	{
		this.nome = nome;
		this.email = email;
	}

	public String getNome() {
		return nome;
	}

	public String getEmail() {
		return email;
	}

	public void setEmail(String email) {
		this.email = email;
	}
	
	
}
