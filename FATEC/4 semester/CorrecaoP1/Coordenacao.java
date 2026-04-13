public class Coordenacao
{
	public static void main (String args[])
	{
		//Questao 2
		Plano_Ensino plano = new Plano_Ensino();
		plano.setMateria("Programação Orientada a Objetos");
		System.out.println("Nome da matéria: " + plano.getMateria());
		//Fim da questao 2
		
		//Questao 4
		Cronograma cronograma = new Cronograma("Mauricio");
		System.out.println("Nome do professor: " + cronograma.getProf());
	}
}
