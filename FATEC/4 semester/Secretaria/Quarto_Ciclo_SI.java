package Secretaria;

public class Quarto_Ciclo_SI extends Secretaria_Escolar
{
	public static void main (String args[])
	{
		Secretaria_Escolar secretaria = new Secretaria_Escolar();
		Insere_Dados(secretaria);
		
		Secretaria_Escolar secretaria2 = new Secretaria_Escolar("Bruno", 21, 10.0, "Análise e desenvolvimento de sistemas");
		Insere_Dados(secretaria2);
	}
	
	public static void Insere_Dados(Secretaria_Escolar classe)
	{
		System.out.println("NOME DO ALUNO: \t" + classe.getNome_aluno());
		System.out.println("IDADE DO ALUNO: \t" + classe.getIdade_aluno());
		System.out.println("MÉDIA DO ALUNO: \t" + classe.getMedia_aluno());
		System.out.println("CURSO DO ALUNO: \t" + classe.getCurso_aluno());
	}
}
