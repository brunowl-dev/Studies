import javax.swing.JOptionPane;
public class exercicios_enquanto {

	public static void main(String[] args) {
		String exercicioInput = JOptionPane.showInputDialog(null, "Digite o exercício: ");
		switch (exercicioInput) {
		case "1":
			 /*Faça um algoritmo que determine os quadrados de um conjunto de números inteiros positivos*/
			int num = 1;
			String numInput;
			while (num != 0) {
				numInput = JOptionPane.showInputDialog(null, "Digite o número ou digite zero pra finalizar o programa");
				num = Integer.parseInt(numInput);
				if (num == 0) {
					JOptionPane.showMessageDialog(null, "Finalizando o programa!");
					break;
				}
				JOptionPane.showMessageDialog(null, "O quadrado do número " + num + " é: " + num * num);
			}
			break;
		case "2":
			/*Faça um algoritmo que leia uma lista de números inteiros. A leitura de dados terminará qunado for ingressado o número zero. Pede-se a soma e a média de todos os números lidos (excluindo o zero)*/
			int num2 = 1, soma = 0, contNum = 0;
			double media;
			String num2Input;
			while (num2 != 0) {
				num2Input = JOptionPane.showInputDialog(null, "Digite o número para ingressar na lista, digite zero para finalizar!");
				num2 = Integer.parseInt(num2Input);
				if (num2 == 0) {
					break;
				}
				soma += num2;
				contNum++;
			}
			media = soma / contNum;
			JOptionPane.showMessageDialog(null, "Soma = " + soma + "\nMédia = " + media);
		}

	}

}
