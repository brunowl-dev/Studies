package business;

public class Disciplina {
	protected String codigo, ementa;
	
	public Disciplina(String codigo, String ementa)
	{
		this.codigo = codigo;
		this.ementa = ementa;
	}

	public String getEmenta() {
		return ementa;
	}

	public void setEmenta(String ementa) {
		this.ementa = ementa;
	}

	public String getCodigo() {
		return codigo;
	}

	@Override
	public String toString() {
		return "Codigo da Disciplina: " + this.getCodigo() + "\nEmenta: " + this.getEmenta() + "\n";
	}
}
