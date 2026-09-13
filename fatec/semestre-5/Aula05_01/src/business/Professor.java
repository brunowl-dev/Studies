package business;

public class Professor extends Pessoa {
	protected String registro;
	
	public Professor(String nome, String email, String registro)
	{
		super(nome, email);
		this.registro = registro;
	}

	public String getRegistro() {
		return registro;
	}
	
	@Override
	public String toString()
	{
		return "Nome do professor: " + this.getNome() + "\nE-mail do aluno: " + this.getEmail() + "\nMatricula do aluno: " + this.getRegistro() + "\n"; 
	}
}
