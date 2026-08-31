import javax.swing.JOptionPane;
import java.util.ArrayList;
import java.util.Scanner;

public class Testes {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		ArrayList<String> nomes = new ArrayList<>();
		int i;
		for (i = 0; i < 5; i++) {
			String nome = sc.nextLine();
			nomes.add(nome);
		}

		System.out.println("Digite o nome a ser pesquisado:");
		String pesquisa = sc.nextLine();
		System.out.println(nomes.indexOf(pesquisa));
		sc.close();

	}

}