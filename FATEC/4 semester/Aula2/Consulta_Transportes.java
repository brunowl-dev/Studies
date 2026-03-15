package Aula2;

public class Consulta_Transportes 
{

	public static void main(String[] args) 
	{
		Transporte onibus = new Transporte(30, "4250", 2, "139", "Adilson");
		System.out.printf("Número de assentos: %d\nPrefixo do ônibus: %s\nNúmero de portas: %d\nLinha: %s\nNome do motorista: %s\n", onibus.getAssentos(), onibus.getId(), onibus.getPortas(), onibus.getLinha(), onibus.getMotorista());
	}	

}
