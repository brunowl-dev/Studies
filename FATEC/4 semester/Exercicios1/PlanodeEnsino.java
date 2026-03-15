package Exercicios1;

public class PlanodeEnsino 
{
	/*1 - Criar a classe (objeto) com a abstração de um “Plano de
Ensino” com os atributos: matéria, conteúdo programático,
critério de avaliação e bibliografia;*/
	private String materia;
	private String conteudo_programatico;
	private String criterio;
	private String bibliografia;	
	
	//2 - Criar a versão padrão do método construtor;
	PlanodeEnsino () {}
	
	/*3 - Criar uma versão do método construtor onde os atributos
	possam ser inicializados com valores;*/
	PlanodeEnsino (String materia, String conteudo_programatico, String criterio, String bibliografia) 
	{	
		this.materia= materia;	
		this.conteudo_programatico = conteudo_programatico;
		this.criterio = criterio;
		this.bibliografia = bibliografia;
	}
	
	/*4 - Criar os respectivos métodos sets( ) e gets( ) para cada
atributo;*/
	public void setMateria(String materia)
	{
		this.materia = materia;
	}
	
	public String getMateria()
	{
		return materia;
	}
	
	public void setConteudo(String conteudo_programatico)
	{
		this.conteudo_programatico = conteudo_programatico;
	}
	
	public String getConteudo()
	{
		return conteudo_programatico;
	}
	
	public void setCriterio(String criterio)
	{
		this.criterio = criterio;
	}
	
	public String getCriterio()
	{
		return criterio;
	}
	
	public void setBibliografia(String bibliografia)
	{
		this.bibliografia = bibliografia;
	}
	
	public String getBibliografia()
	{
		return bibliografia;
	}
}
