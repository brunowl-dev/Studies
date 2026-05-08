package Aula3;
import javax.swing.JOptionPane;
public class ConsultaTransporte 
{
	
	public static void main(String[] args) 
	{
			String prefixo = JOptionPane.showInputDialog("Digite o prefixo do ônibus:");
			String placa = JOptionPane.showInputDialog("Digite a placa do ônibus:");
			String linha = JOptionPane.showInputDialog("Digite a linha do ônibus:");
			int portas = Integer.parseInt(JOptionPane.showInputDialog("Digite o portas do ônibus:"));
			int assentos = Integer.parseInt(JOptionPane.showInputDialog("Digite o assentos do ônibus:"));
			
			MeiodeTransporte onibus = new MeiodeTransporte(prefixo, placa, linha, portas, assentos);
			onibus.Informa_Transporte();
	}

}
