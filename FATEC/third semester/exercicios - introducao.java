package exercicios;
import javax.swing.JOptionPane;

public class Exercicios {

	public static void main(String[] args) {
		String num_exerciciosString = JOptionPane.showInputDialog(null,"Digite o número do exercício: ");
		int exercicio = Integer.parseInt(num_exerciciosString);
		
		switch (exercicio) {
		case 1:
			/*1.O imposto de renda de uma pessoa varia segundo uma tabela.
			Se o salário for menor do que R$ 1.000,00, não há imposto;
			Se for entre R$ 1.000,00 e R$ 2.200,00, o imposto é de 13% do valor do salário;
			Se for maior do que R$ 2.200,00, o imposto é de 22%;
			Faça um algoritmo que dado um valor, em reais, correspondente a um salário, informe o valor que será recebido (total menos imposto).*/
			String salarioStr = JOptionPane.showInputDialog(null,"Digite o salário: ");
			double salario = Double.parseDouble(salarioStr);
			double imposto = 0;
			
			if (salario > 1000 && salario < 2200) {
				imposto = salario * 0.13;
			}
			
			else if (salario >= 2200) {
				imposto = salario * 0.22;
			}
			double total = salario - imposto;
			
			String mensagem1 = "O valor que será recebido é: R$" + total;
			JOptionPane.showMessageDialog(null, mensagem1,"Salário líquido do usuário",
			JOptionPane.INFORMATION_MESSAGE);
			break;
		case 2:
			/*2. Construa um algoritmo que leia os três lados de um triângulo e determine se o triângulo é equilátero (3 lados iguais), isósceles (2 lados iguais) ou escaleno (3 lados 			diferentes).*/
			String aStr = JOptionPane.showInputDialog(null,"Digite o lado A do triângulo: ");
			String bStr = JOptionPane.showInputDialog(null,"Digite o lado B do triângulo: ");
			String cStr = JOptionPane.showInputDialog(null,"Digite o lado C do triângulo: ");
			int a = Integer.parseInt(aStr);
			int b = Integer.parseInt(bStr);
			int c = Integer.parseInt(cStr);
			
			if (a == b && a == c) {
				String mensagem2 = "O triângulo é equilátero!";
				JOptionPane.showMessageDialog(null, mensagem2,"Triângulo",
				JOptionPane.INFORMATION_MESSAGE);
			}
			else if (a == b || a == c || b == c) {
				String mensagem2 = "O triângulo é isósceles!";
				JOptionPane.showMessageDialog(null, mensagem2,"Triângulo",
				JOptionPane.INFORMATION_MESSAGE);
			}
			else {
				String mensagem2 = "O triângulo é escaleno!";
				JOptionPane.showMessageDialog(null, mensagem2,"Triângulo",
				JOptionPane.INFORMATION_MESSAGE);
			}
			break;
		case 3:
			/*3.Faça um algoritmo que leia o IMC (Índice de Massa Corporal) de uma pessoa.
			Se o resultado for abaixo de 18,5, informe uma mensagem de que a pessoa está abaixo do peso;
			Se o resultado for entre 18,5 e 24,99, informe uma mensagem de que a pessoa está com peso normal
			Se o resultado for acima de 25, informe uma mensagem de que a pessoa está acima do peso*/
			String alturaStr = JOptionPane.showInputDialog(null,"Digite a sua altura em metros, separando por ponto: ");
			String pesoStr = JOptionPane.showInputDialog(null,"Digite o seu peso em kg: ");
			
			double altura = Double.parseDouble(alturaStr);
			double peso = Double.parseDouble(pesoStr);
			double imc = peso / (altura * altura);
			
			if (imc <= 18.5) {
				String mensagem3 = "Você está abaixo do peso!";
				JOptionPane.showMessageDialog(null, mensagem3,"IMC",
				JOptionPane.INFORMATION_MESSAGE);
			}
			else if (imc > 18.5 && imc < 25) {
				String mensagem3 = "Você está com peso normal!";
				JOptionPane.showMessageDialog(null, mensagem3,"IMC",
				JOptionPane.INFORMATION_MESSAGE);
			}
			else {
				String mensagem3 = "Você está acima do peso!";
				JOptionPane.showMessageDialog(null, mensagem3,"IMC",
				JOptionPane.INFORMATION_MESSAGE);
			}
			break;
		case 4:
			/*4. Escreva um programa para ler o ano de nascimento de uma pessoa e escrever uma mensagem que diga se ela poderá ou não votar este ano (não é necessário considerar o mês em que 			ela nasceu). */
			String anoStr = JOptionPane.showInputDialog(null,"Digite o ano do seu nascimento: ");
			int ano = Integer.parseInt(anoStr);
			int idade = 2025 - ano;
			if (idade >= 18) {
				String mensagem4 = "Você pode votar esse ano!";
			    JOptionPane.showMessageDialog(null, mensagem4,"Votar",
			    JOptionPane.INFORMATION_MESSAGE);
			}
			else {
				String mensagem4 = "Você NÃO pode votar esse ano!";
			    JOptionPane.showMessageDialog(null, mensagem4,"Votar",
			    JOptionPane.INFORMATION_MESSAGE);
			}
			break;
		case 5:
			/*5. Faça um aplicativo em java que receba o preço de custo de um produto e mostre o valor de venda. Sabe-se que o preço de custo receberá um acréscimo de acordo com um percentual 			informado pelo usuário.*/
			String custoStr = JOptionPane.showInputDialog(null,"Digite o custo do seu produto: ");
			String percentStr = JOptionPane.showInputDialog(null,"Digite o percentual de lucro desejado: ");
			double custo = Double.parseDouble(custoStr);
			double percent = Double.parseDouble(percentStr);
			percent = percent / 100;
			double venda = custo + (custo * percent);
			String mensagem5 = "O valor de venda deve ser: R$" + venda;
		    JOptionPane.showMessageDialog(null, mensagem5,"Venda",
		    JOptionPane.INFORMATION_MESSAGE);
		    break;
		case 6:
			/*6. Faça um aplicativo em java que calcule o valor em Reais, correspondente aos dólares que um turista possui no cofre do hotel. O programa deve solicitar os seguintes dados: 			Quantidade de dólares guardados no cofre e cotação do dólar naquele dia.*/
			String saldoStr = JOptionPane.showInputDialog(null,"Digite oos doláres no cofre: ");
			String cotacaoStr = JOptionPane.showInputDialog(null,"Digite a cotação do dia: ");
			double saldo = Double.parseDouble(saldoStr);
			double cotacao = Double.parseDouble(cotacaoStr);
			double reais = saldo * cotacao;
			String mensagem6 = "Você tem R$" + reais;
		    JOptionPane.showMessageDialog(null, mensagem6,"Saldo em reais",
		    JOptionPane.INFORMATION_MESSAGE);
		    break;
		case 7:
			/*7. Elabore um programa que informe ao usuário quanto custará completar o tanque de
			seu veículo, para isso o usuário deverá informar a capacidade de seu tanque e se
			deseja abastecer álcool ou gasolina, considere que o preço da gasolina esta 6,60 e o
			álcool está 5,00*/
			String capacidadeStr = JOptionPane.showInputDialog(null,"Digite a capacidade do seu tanque em litros: ");
			String opcaoStr = JOptionPane.showInputDialog(null,"Digite a opção para abastecer, 1 para álcool, 2 para gasolina: ");
			double capacidade = Double.parseDouble(capacidadeStr);
			double total7 = 0;
			int opcao = Integer.parseInt(opcaoStr);
			if (opcao == 1) {
				double alcool = 5;
				total7 = capacidade * alcool;
			}
			else {
				double gasolina = 6.60;
				total7 = capacidade * gasolina;
			}
			String mensagem7 = "Você vai gastar R$" + total7;
		    JOptionPane.showMessageDialog(null, mensagem7,"Gasolina",
		    JOptionPane.INFORMATION_MESSAGE);
		    break;
		case 8:
			/*8. Construa um programa que indique se um número digitado está
			compreendido entre 20 e 90 ou não (20 e 90 não estão na faixa de
			valores).*/
			String numStr = JOptionPane.showInputDialog(null,"Digite o número: ");
			int num = Integer.parseInt(numStr);
			if (num > 20 && num < 90) {
				String mensagem8 = "O número está na faixa entre 20 e 90";
			    JOptionPane.showMessageDialog(null, mensagem8,"Faixa de números",
			    JOptionPane.INFORMATION_MESSAGE);
			}
			else {
				String mensagem8 = "O número NÃO está na faixa entre 20 e 90";
			    JOptionPane.showMessageDialog(null, mensagem8,"Faixa de números",
			    JOptionPane.INFORMATION_MESSAGE);
			} 
		}
		
	}

}
