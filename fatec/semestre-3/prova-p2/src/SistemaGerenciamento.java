import javax.swing.JOptionPane;
import java.util.ArrayList;
public class SistemaGerenciamento {
	public static void main(String[] args) {
		ArrayList<Aluno> listaAlunos = new ArrayList<Aluno>();
		int menu = -1, indice;
		while (menu != 5) {
			if (menu == 5) {
				break;
			}
			menu = Integer.parseInt(JOptionPane.showInputDialog(null, "SISTEMA DE GERENCIAMENTO DE ALUNOS\n1-Cadastrar aluno\n2-Listar alunos\n3-Pesquisar aluno\n4-Remover aluno\n5-Sair\n"));
			switch (menu) {
			case 1:
				listaAlunos.add(cadastraAluno());
				break;
			case 2:
				mostrarAlunos(listaAlunos);
				break;
			case 3:
				indice = pesquisarAluno(listaAlunos);
				if (indice == -1) {
					JOptionPane.showMessageDialog(null, "Aluno não encontrado!");
					break;
				}
				JOptionPane.showMessageDialog(null, "Aluno encontrado!\nNome: " + listaAlunos.get(indice).getNome() + "\nMedia: " + listaAlunos.get(indice).getMEDIA() + "\n");
				break;
			case 4:
				indice = pesquisarAluno(listaAlunos);
				if (indice == -1) {
					JOptionPane.showMessageDialog(null, "Aluno não encontrado!");
					break;
				}
				listaAlunos.remove(indice);
				JOptionPane.showMessageDialog(null, "Aluno removido!");
				break;
			case 5:
				JOptionPane.showMessageDialog(null, "Programa finalizando...");
				break;
			default:
				JOptionPane.showMessageDialog(null, "Opção inválida!");
			}
		}

	}
	
	public static Aluno cadastraAluno() {
		String nome = JOptionPane.showInputDialog(null, "Digite o nome do aluno a ser cadastrado: ");
		double nota1 = Double.parseDouble(JOptionPane.showInputDialog(null, "Digite a nota 1 do aluno " + nome));
		double nota2 = Double.parseDouble(JOptionPane.showInputDialog(null, "Digite a nota 2 do aluno " + nome));
		Aluno novoAluno = new Aluno(nome, nota1, nota2);
		JOptionPane.showMessageDialog(null, "O aluno " + nome + " foi cadastrado!");
		return novoAluno;
	}
	
	public static void mostrarAlunos (ArrayList<Aluno> listaAlunos) {
		int i;
		for (i = 0; i < listaAlunos.size(); i++) {
			String mensagem = "SISTEMA DE GERENCIAMENTO DE ALUNOS\n";
			mensagem += "Aluno n°0" + i + " - " + listaAlunos.get(i).getNome() + "\nMédia: " + listaAlunos.get(i).getMEDIA() + "\n";
			JOptionPane.showMessageDialog(null, mensagem);
		}
	}

	public static int pesquisarAluno (ArrayList<Aluno> listaAlunos) {
		int i, indice = -1;
		String pesquisa = JOptionPane.showInputDialog(null, "Digite o nome do aluno a ser procurado: ");
		for (i = 0; i < listaAlunos.size(); i++) {
			if (listaAlunos.get(i).getNome().equals(pesquisa)) {
				indice = i;
				break;
			}
		}
		return indice;
	}
	
}
