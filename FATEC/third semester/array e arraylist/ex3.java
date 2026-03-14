package atividadeArrayList;
import javax.swing.JOptionPane;
public class ex3 {

	public static void main(String[] args) {
		/*Crie um programa que leia 10 números inteiros e armazene em um vetor. Em seguida, inverta a ordem dos elementos no próprio vetor, sem usar um vetor auxiliar.*/
		int[] numeros = new int[10];
		int i, j = 9, aux;
		String stringVetor = "";
		for (i = 0; i < 10; i++) {
			String stringNum = JOptionPane.showInputDialog(null, "Digite o número a ser armazenado na posição " + i);
			int num = Integer.parseInt(stringNum);
			numeros[i] = num;
			stringVetor += numeros[i] + " ";
		}
		JOptionPane.showMessageDialog(null, "Seu vetor está assim\n" + stringVetor);
		stringVetor = "";
		for (i = 0; i < 5; i++) {
			aux = numeros[i];
			numeros[i] = numeros[j];
			numeros[j] = aux;
			j--;
		}
		for (i = 0; i < 10; i++) {
			stringVetor += numeros[i] + " ";
		}
		JOptionPane.showMessageDialog(null, "Seu vetor AGORA está assim\n" + stringVetor);
		
	}

}
