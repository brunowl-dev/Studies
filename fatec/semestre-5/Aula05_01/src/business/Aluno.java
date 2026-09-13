package business;

public class Aluno extends Pessoa {
	protected String matricula;
	
	public Aluno(String nome, String email, String matricula)
	{
		super(nome, email);
		this.matricula = matricula;
	}

	public String getMatricula() {
		return matricula;
	}
	
	@Override
	public String toString()
	{
		return "Nome do aluno: " + this.getNome() + "\nE-mail do aluno: " + this.getEmail() + "\nMatricula do aluno: " + this.getMatricula() + "\n";
	}
}
