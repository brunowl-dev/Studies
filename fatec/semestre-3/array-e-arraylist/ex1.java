package atividadeArrayList;
import java.util.ArrayList;
import javax.swing.JOptionPane;

public class ex1 {

	public static void main(String[] args) {
	/*Sistema de Votação com Regras
	Crie um sistema de votação para escolher o representante da turma. O sistema deve:
	
	Permitir o cadastro de candidatos (nome e número).
	Permitir que os alunos votem informando o número do candidato.
	Cada aluno pode votar apenas uma vez (simule com um array de RA dos alunos).
	Ao final, exiba o vencedor e a quantidade de votos de cada candidato.
	Desafio: O programa deve impedir votos duplicados e validar se o número do candidato existe. Use ArrayList para armazenar os dados.*/
		int opcao = 0;
		ArrayList<String> nomesCandidatos = new ArrayList<>();
		ArrayList<Integer> alunosRA = new ArrayList<>();
		ArrayList<Integer> votos = new ArrayList<>();
		ArrayList<Integer> numerosCandidatos = new ArrayList<>();
		while (opcao != 4) {
			String inputOpcao = JOptionPane.showInputDialog(null, "MENU\n1-Cadastro dos candidatos\n2-Votar\n3-Finalizar votação\n4-Sair\n");
			opcao = Integer.parseInt(inputOpcao);
			
			switch (opcao) {
			case 4:
				JOptionPane.showMessageDialog(null, "Programa finalizado!");
				break;
			case 1:
				String nome = JOptionPane.showInputDialog(null, "Digite o nome do candidato: ");
				String stringNumero = JOptionPane.showInputDialog(null, "Digite o número do candidato: ");
				int numero = Integer.parseInt(stringNumero);
				nomesCandidatos.add(nome);
				numerosCandidatos.add(numero);
				votos.add(0);
				JOptionPane.showMessageDialog(null, "Candidato " + nome + " - " + numero + " adicionado!");
				break;
			case 2:
				String stringRA = JOptionPane.showInputDialog(null, "Digite seu RA para prosseguir com a votação: ");
				int raAluno = Integer.parseInt(stringRA);
				if (checkaRA(alunosRA, raAluno) == true) {
					JOptionPane.showMessageDialog(null, "Seu RA já está cadastrado, você não pode votar de novo!");
				}
				else {
					String mensagemVoto = "";
					for (int i = 0; i < nomesCandidatos.size(); i++) {
						mensagemVoto += nomesCandidatos.get(i) + " - " + numerosCandidatos.get(i) + "\n";
					}
					String stringVoto = JOptionPane.showInputDialog(null, "Qual candidato deseja votar?\n" + mensagemVoto);
					int votoNumero = Integer.parseInt(stringVoto);
					int indiceVoto = numerosCandidatos.indexOf(votoNumero);
					if (indiceVoto == -1) {
						JOptionPane.showMessageDialog(null, "Número do candidato inválido!");
					}
					else {
						int voto = votos.get(indiceVoto);
						voto += 1;
						votos.set(indiceVoto, voto);
						alunosRA.add(raAluno);
					}
				}
				break;
			case 3:
				int vencedor = vencedor(votos);
				JOptionPane.showMessageDialog(null, "O vencedor da eleição foi o candidato:\n" + nomesCandidatos.get(vencedor) + " - " + numerosCandidatos.get(vencedor) + " com " + votos.get(vencedor) + " votos!");
				break;
			}
		}
	}
	
	private static boolean checkaRA(ArrayList<Integer> alunosRA, int raAluno) {
		int tamanho = alunosRA.size();
		for (int i = 0; i < tamanho; i++) {
			if (raAluno == alunosRA.get(i)) {
				return true;
			}
		}
		return false;
		}
	
	private static int vencedor(ArrayList<Integer> votos) {
		int maximo = 0;
		for (int i = 0; i < votos.size(); i++) {
			if (votos.get(i) > maximo) {
				maximo = votos.get(i);
			}
		}
		return votos.indexOf(maximo);
	}
	}