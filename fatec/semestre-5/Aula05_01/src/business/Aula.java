package business;
import java.util.ArrayList;

public class Aula {
	Pessoa professor;
	Disciplina disc;
	Materia mat;
	ArrayList<Aluno> alunos = new ArrayList<>();
	
	public Aula(Pessoa professor, Disciplina disc, Materia mat)
	{
		this.professor = professor;
		this.disc = disc;
		this.mat = mat;
	}
	
	public void addAluno(String nome, String email)
	{
		String matricula = "000" + (alunos.size() + 1);;
		Aluno aluno = new Aluno(nome, email, matricula);
		alunos.add(aluno);
	}
	
	@Override
	public String toString()
	{
		String retornar = " ";
		if (alunos.size() >= 5)
		{
			retornar += this.disc;
			retornar += this.mat;
			retornar += this.professor;
			
			for (Aluno aluno : alunos)
			{
				retornar += aluno;
			}
			return retornar;
		}
		return "Sao necessarios 5 alunos!";
	}
}
