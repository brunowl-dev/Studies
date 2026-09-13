package business;

public class Manutencao {
	protected String dataUltimaManutencao;
	protected String tipoServico;
	
	public Manutencao(String dataUltimaManutencao, String tipoServico) {
		this.dataUltimaManutencao = dataUltimaManutencao;
		this.tipoServico = tipoServico;
	}
	
	@Override
	public String toString()
	{
		String retornar = "Data da ultima manutenaco: " + this.dataUltimaManutencao;
		retornar += "\nTipo do servico: " + this.tipoServico;
		return retornar;
	}
}
