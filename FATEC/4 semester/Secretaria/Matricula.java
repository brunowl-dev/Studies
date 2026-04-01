package Secretaria;

public class Matricula extends Quarto_Ciclo_SI
{
	public static void main (String args[])
	{
	Quarto_Ciclo_SI classe = new Quarto_Ciclo_SI();
	classe.setMatricula_aluno("RA123456");
	System.out.println("Matrícula: \t" + classe.getMatricula_aluno());
	}
}
