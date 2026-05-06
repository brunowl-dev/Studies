package abstracao;

public abstract class Classe_Abstrata 
{
	private String mensagem;
	
	protected void setMensagem(String mensagem)
	{
		this.mensagem = mensagem;
	}
	
	protected String getMensagem()
	{
		return mensagem;
	}
	
	protected abstract void mostraMensagem();
}
