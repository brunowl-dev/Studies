package Funcionarios;
import javax.swing.JOptionPane;

public class Aplicacao 
{
	public static void main(String args[])
	{
		Ficha_funcionarios funcionarios = new Ficha_funcionarios(22, 2889.09, "Gisele", "Pedagoga");
		JOptionPane.showMessageDialog(null, funcionarios.mostra_funcionarios());
		
		concatena_aplicacao();
	}
	
	public static void concatena_aplicacao()
	{
		Acesso_secundario a = new Acesso_secundario();
	}
}
