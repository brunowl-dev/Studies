package ConstrucaoCivil;
import javax.swing.*;

public class EmpresadeConstrucao {

	public static void main(String[] args) {
		Construcao pedreiro = null;
		
		int tipo_construcao = Integer.parseInt(JOptionPane.showInputDialog("Digite o tipo da construção\n1-Casa\n2-Apartamento\n3-Tudo\n"));
		
		switch(tipo_construcao)
		{
		case 1:
			pedreiro = new Casa();
			break;
			
		case 2:
			pedreiro = new Apartamento();
			break;
			
		case 3:
			pedreiro = new Construcao();
			break;
		
		default:
			System.out.println("CONSTRUÇÃO INDEFINIDA");
			System.exit(0);
		}
		
		/*
		 * 1. Construir a aplicação de “construção de imóveis” e executála. Em que
		 * método da aplicação é utilizado o conceito de Polimorfismo?
		 */
		//R: No método Construir(), pois independente da classe selecionada pelo usuário, executa-se o mesmo método
		pedreiro.Construir();

	}

}
