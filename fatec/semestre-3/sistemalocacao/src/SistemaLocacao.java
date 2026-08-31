import javax.swing.JOptionPane;
import java.util.ArrayList;
public class SistemaLocacao {
	public static void main(String[] args) {
		ArrayList<Cliente> listaClientes = new ArrayList<Cliente>();
		ArrayList<Veiculo> listaVeiculos = new ArrayList<Veiculo>();
		ArrayList<Locacao> listaLocacoes = new ArrayList<Locacao>();
		int menu = -1;
		while (menu != 5) {
			if (menu == 5) {
				break;
			}
			menu = Integer.parseInt(JOptionPane.showInputDialog(null, "SISTEMA DE LOCAÇÃO DE VEÍCULOS\n1-Cadastrar cliente\n2-Cadastrar veículo\n3-Registrar locação\n4-Listar locações\n5-Sair\n"));
			switch (menu) {
			case 1:
				listaClientes.add(cadastraCliente());
				JOptionPane.showMessageDialog(null, "O Cliente foi cadastrado!");
				break;
			case 2:
				listaVeiculos.add(cadastraVeiculo());
				JOptionPane.showMessageDialog(null, "O Veículo foi cadastrado!");
				break;
			case 3:
				listaLocacoes.add(registraLocacao(listaClientes, listaVeiculos));
				JOptionPane.showMessageDialog(null, "Locação registrada!");
				break;
			case 4:
				mostraLocacao(listaLocacoes);
				break;
			case 5:
				JOptionPane.showMessageDialog(null, "Programa finalizando...");
				break;
			default:
				JOptionPane.showMessageDialog(null, "Opção inválida!");
			}
		}
	}
	
	public static Cliente cadastraCliente() {
		String cpf = JOptionPane.showInputDialog(null, "Digite o CPF do cliente: ");
		String nome = JOptionPane.showInputDialog(null, "Digite o nome do cliente: ");
		String tel = JOptionPane.showInputDialog(null, "Digite o telefone do cliente: ");
		String endereco = JOptionPane.showInputDialog(null, "Digite o enderçeo do cliente (separando por vírgula): ");
		Cliente novoCliente = new Cliente(cpf, nome, tel, endereco);
		return novoCliente;
	}
	
	public static Veiculo cadastraVeiculo() {
		String placa = JOptionPane.showInputDialog(null, "Digite a placa do veículo: ");
		String modelo = JOptionPane.showInputDialog(null, "Digite o modelo do veículo (marca - modelo): ");
		int ano = Integer.parseInt(JOptionPane.showInputDialog(null, "Digite o ano do veículo: "));
		double valor = Double.parseDouble(JOptionPane.showInputDialog(null, "Digite o valor da diária: "));
		Veiculo novoVeiculo = new Veiculo(placa, modelo, ano, valor);
		return novoVeiculo;
	}
	
	public static Locacao registraLocacao(ArrayList<Cliente> listaClientes, ArrayList<Veiculo> listaVeiculos) {
		int indiceCliente = 0, indiceVeiculo = 0;
		String cpf = JOptionPane.showInputDialog(null, "Digite o CPF do cliente da locação: ");
		for (int i = 0; i < listaClientes.size(); i++) {
			if (listaClientes.get(i).getCPF() == cpf) {
				indiceCliente = i;
				break;
			}
		}
		
		String placa = JOptionPane.showInputDialog(null, "Digite a placa do veículo da locação: ");
		for (int i = 0; i < listaVeiculos.size(); i++) {
			if (listaVeiculos.get(i).getPLACA() == placa) {
				indiceVeiculo = i;
				break;
			}
		}
		int dias = Integer.parseInt(JOptionPane.showInputDialog(null, "Digite o número de dias da locação: "));
		
		Locacao novaLocacao = new Locacao(listaClientes.get(indiceCliente), listaVeiculos.get(indiceVeiculo), dias);
		return novaLocacao;
	}
	
	public static void mostraLocacao(ArrayList<Locacao> listaLocacoes) {
		int i;
		for (i = 0; i < listaLocacoes.size(); i++) {
			String mensagem = "Locação n°0" + i + "\n" + "PLACA: " + listaLocacoes.get(i).getPlacaCliente() + "\n" + "NOME: " + listaLocacoes.get(i).getNomeCliente() + "\n" + "VALOR: " + listaLocacoes.get(i).getTotal();
			JOptionPane.showMessageDialog(null, mensagem);
		}
	}
}
