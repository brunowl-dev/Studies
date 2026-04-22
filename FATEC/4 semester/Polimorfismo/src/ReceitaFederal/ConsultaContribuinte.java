package ReceitaFederal;
import javax.swing.JOptionPane;

public class ConsultaContribuinte {

	public static void main(String[] args) {
		Contribuinte contribuinte = null;
		
		int tipo = Integer.parseInt(JOptionPane.showInputDialog("DIGITE O TIPO DE CONTRIBUINTE\n1 - Contribuinte\n2 - Pessoa Fisica\n3 - Pessoa Juridica\n4 - Funcionario\n"));
		
		switch(tipo)
		{
		case 1:
			contribuinte = new Contribuinte();
			break;
		case 2:
			contribuinte = new PessoaFisica();
			break;
		case 3:
			contribuinte = new PessoaJuridica();
			break;
		case 4:
			contribuinte = new Funcionario();
			break;
			
		default:
			System.out.println("Não foi selecionado um valor válido!");
			System.exit(0);
		}
		
		contribuinte.mostraClasse();

	}

}
