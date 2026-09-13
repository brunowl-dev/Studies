package view;
import business.*;
import javax.swing.JOptionPane;

public class Principal {

	public static void main(String[] args) {
		int opcao = 0;
		Pessoa pessoa = null;
		Aula aula = null;

		do {
			String menu = "1 - Registrar aula\n2 - Registrar alunos\n3 - Exibir informacoes da aula\n4 - Sair\n";
			opcao = Integer.parseInt(JOptionPane.showInputDialog(null, menu));
			
			switch(opcao) 
			{
			case 1:
				String nome = JOptionPane.showInputDialog(null, "Digite o nome do professor: ");
				String email = JOptionPane.showInputDialog(null, "Digite o email do professor: ");
				String registro = JOptionPane.showInputDialog(null, "Digite o registro do professor: ");
				pessoa = new Professor(nome, email, registro);
				
				String codigo = JOptionPane.showInputDialog(null, "Digite o código da disciplina: ");
				String ementa = JOptionPane.showInputDialog(null, "Digite a ementa da disciplina: ");
				Disciplina disc = new Disciplina(codigo, ementa);
				
				String topico = JOptionPane.showInputDialog(null, "Digite o topico da materia: ");
				String descricao = JOptionPane.showInputDialog(null, "Digite a descricao da materia: ");
				Materia mat = new Materia(topico, descricao);
				
				aula = new Aula(pessoa, disc, mat);
				break;
			case 2:
				nome = JOptionPane.showInputDialog(null, "Digite o nome do aluno: ");
				email = JOptionPane.showInputDialog(null, "Digite o email do aluno: ");
				aula.addAluno(nome, email);
				break;
			case 3:
				System.out.println(aula);
				break;
			}
		} while (opcao != 4);
	}
}