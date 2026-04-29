public class ConcessionariaVolks extends OficinaMecanica
{
	/*
	 * 1-Criar uma filha de Oficina_Mecânica, chamada Concessionária_Volks, que
	 * contenha métodos polimorfos a: pintura( ), funilaria ( ) e elétrica( ). Em
	 * cada um destes métodos devem ser retornados dados típicos relacionados à
	 * marca Volkswagen e ao modelo Fusca.
	 */
	public String pintura()
	{
		return "pintar de azul";
	}
	
	public String funilaria()
	{
		return "martelinho de ouro";
	}
	
	public String eletrica()
	{
		return "trocar farol";
	}
}
