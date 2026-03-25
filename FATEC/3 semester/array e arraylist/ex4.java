package atividadeArrayList;
import javax.swing.JOptionPane;
public class ex4 {

	public static void main(String[] args) {
		/*Leia um vetor de 7 posições com números inteiros. Verifique se o vetor é um palíndromo (ou seja, se a sequência é igual quando lida de trás para frente).*/
		int[] numeros = new int[7];
		int i, j = 6;
		boolean palindromo = true;
		for (i = 0; i < 7; i++) {
			String stringNum = JOptionPane.showInputDialog(null, "Digite o número a ser armazenado na posição " + i);
			int num = Integer.parseInt(stringNum);
			numeros[i] = num;
		}
		for (i = 0; i < 7 / 2; i++) {
			if (numeros[i] != numeros[j]) {
				palindromo = false;
				break;
			}
			j--;
		}
		if (palindromo == true) {
			JOptionPane.showMessageDialog(null, "Seu vetor é um palíndromo!");
		}
		else {
			JOptionPane.showMessageDialog(null, "Seu vetor NÃO é um palíndromo!");
		}
		
	}

}
