package Aula5;

public class Nome_Classe {
	private String atributo;
	/*método construtor padrão deve ser escrito explicitamente se houver outra versão do mesmo: inicializa o atributo com valor default; no caso de string.*/
	
	Nome_Classe(){}
	/*Versão do método construtor que recebe o valor do atributo*/
	
	Nome_Classe(String atributo)
	{
		this.atributo = atributo;
	}
	/*Neste caso não haveria necessidade do método set, somente do get*/
	
	public String get_atributo()
	{
		return atributo;
	}
}
