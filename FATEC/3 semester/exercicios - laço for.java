import javax.swing.JOptionPane;
import java.text.DecimalFormat;
public class Laço_Repeticao {

	public static void main(String[] args) {
		String exercicioInput = JOptionPane.showInputDialog(null, "Digite o número do exercício: ");
		switch (exercicioInput) {
		case "1":
			/*Faça um algoritmo que imprima os 4 primeiros números inteiros pares positivos*/
			int contador1Positivos = 0, i;
			String num1Input = JOptionPane.showInputDialog(null, "Digite o número:");
			int num1 = Integer.parseInt(num1Input);
			for (i = num1; contador1Positivos < 4; i++) {
				if (i % 2 == 0 && i >= 0) {
					JOptionPane.showMessageDialog(null, i);
					contador1Positivos++;
				}
			}
			break;
		case "2":
			/*Faça um algoritmo que imrpima a soma dos 4 primeiros númeors inteiros positivos*/
			int contador2Positivos = 0, j, soma = 0;
			String num2Input = JOptionPane.showInputDialog(null, "Digite o número: ");
			int num2 = Integer.parseInt(num2Input);
			for (j = num2; contador2Positivos < 4; j++) {
				if (j % 2 == 0 && j >= 0) {
					soma += j;
					contador2Positivos++;
				}
			}
			JOptionPane.showMessageDialog(null, soma);
			break;
		case "3":
			/*Faça um algoritmo que imprima a soma dos n primeiros números inteiros pares positivos*/
			int contador3Positivos = 0, k, soma3 = 0, n;
			String nInput = JOptionPane.showInputDialog(null, "Digite o valor de n:");
			n = Integer.parseInt(nInput);
			String num3Input = JOptionPane.showInputDialog(null, "Digite o número: ");
			int num3 = Integer.parseInt(num3Input);
			for (k = num3; contador3Positivos < n; k++) {
				if (k % 2 == 0 && k >= 0) {
					soma3 += k;
					contador3Positivos++;
				}
			}
			JOptionPane.showMessageDialog(null, soma3);
			break;
		case "4":
			/*Desenvolver um algoritmo para calcular a soma: 1 + 1/2 (denomindaor chegar até 200)*/
			float soma4 = 1, denominador = 2, var;
			for (var = denominador; var <= 200; var++) {
				if (var % 2 == 0) {
					soma4 += (1 / var);
				}
			}
			JOptionPane.showMessageDialog(null, soma4);
			break;
		}
	}

}
