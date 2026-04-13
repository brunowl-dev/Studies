public class Plano_Ensino 
{
	//Questao 1
	private String materia;
	
	//Questao 3
	private String professor;
	
	Plano_Ensino(){};
	
	Plano_Ensino(String professor)
	{
		this.professor = professor;
	}
	
	public String getProf()
	{
		return professor;
	}
	
	//Fim da questao 3
	
	public void setMateria(String materia)
	{
		this.materia = materia;
	}
	
	public String getMateria()
	{
		return materia;
	}
	
	
}
