package business;

public class Materia {
	protected String topico, descricao;
	
	public Materia(String topico, String descricao)
	{
		this.topico = topico;
		this.descricao = descricao;
	}

	public String getTopico() {
		return topico;
	}

	public void setTopico(String topico) {
		this.topico = topico;
	}

	public String getDescricao() {
		return descricao;
	}

	public void setDescricao(String descricao) {
		this.descricao = descricao;
	}

	@Override
	public String toString() {
		return "Topico da materia: " + this.getTopico() + "\nDescricao: " + this.getDescricao() + "\n";
	}
}
