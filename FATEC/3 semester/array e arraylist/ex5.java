package atividadeArrayList;
import javax.swing.JOptionPane;
public class ex5 {

	public static void main(String[] args) {
		/*Leia 20 números inteiros e armazene em um vetor. Crie um segundo vetor contendo apenas os números primos do primeiro vetor.*/
		int j = 0, i;
		int[] vetor = new int[20];
		int[] primo = new int[20];
		for (i = 0; i < 20; i++) {
			String stringNum = JOptionPane.showInputDialog(null, "Digite o número: ");
			int num = Integer.parseInt(stringNum);
			vetor[i] = num;
			if (num % 2 != 0) {
				primo[j] = num;
				j++;
			}
		}
		String mensagem = "";
		for (i = 0; i < j; i++) {
			mensagem += primo[i] + " ";
		}
		JOptionPane.showMessageDialog(null, "Seu vetor de primos é\n" + mensagem);

	}

}
