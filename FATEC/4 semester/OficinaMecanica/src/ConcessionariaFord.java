public class ConcessionariaFord extends OficinaMecanica
{
	/*
	 * 2-Criar uma filha de Oficina_Mecânica, chamada Concessionária_Ford, que
	 * contenha métodos polimorfos a: pintura( ), funilaria ( ) e elétrica( ). Em
	 * cada um destes métodos devem ser retornados dados típicos relacionados à
	 * marca Ford e ao modelo Belina.
	 */
	public String pintura()
	{
		return "pintar de branco";
	}
	
	public String funilaria()
	{
		return "reparar porta";
	}
	
	public String eletrica()
	{
		return "instalar multimidia";
	}
}
