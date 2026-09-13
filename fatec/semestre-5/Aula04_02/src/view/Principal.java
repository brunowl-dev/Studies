package view;
import java.util.Scanner;
import business.*;

public class Principal 
{	
	public static void main(String[] args) 
	{
		Veiculo veiculo = null;
		Scanner sc = new Scanner(System.in);
		int opcao = 0;
		do
		{
			System.out.println("MENU\n1 - Criar carro\n2 - Criar moto\n");
			opcao = sc.nextInt();
			if (opcao != 1 && opcao != 2)
			{
				System.out.println("Opção inválida!");
			}
			else 
			{
				System.out.println("Digite o modelo do veículo:");
				String modelo = sc.next();
				
				System.out.println("Digite o fabricante do veículo:");
				String fabricante = sc.next();
				
				System.out.println("Digite o ano do veículo:");
				int ano = sc.nextInt();
				if (opcao == 1)
				{
					System.out.println("Digite a quantidade de portas");
					int quantidadePortas = sc.nextInt();
					veiculo = new Carro(modelo, fabricante, ano, quantidadePortas);
				}
				else
				{
					veiculo = new Moto(modelo, fabricante, ano);
				}
			}
		} while (opcao != 1 && opcao != 2);
		
		opcao = 0;
		do 
		{
			System.out.println("1 - Acelerar veículo\n2 - Desacelerar veículo\n3 - Parar veículo\n4 - Sair\n");
			opcao = sc.nextInt();
			switch(opcao)
			{
				case 1:
				if (veiculo.getVelocidadeAtual() >= 180)
				{
					System.out.println("O Veículo está muito rápido para ser acelerado!");
				}
				else
				{
					veiculo.acelerar();
					System.out.println(veiculo);
				}
					break;
				case 2:
					if (veiculo.getVelocidadeAtual() == 0)
					{
						System.out.println("O Veículo já está parado!");
					}
					else
					{
						veiculo.desacelerar();
						System.out.println(veiculo);
					}
					break;
				case 3:
					if (veiculo.getVelocidadeAtual() == 0)
					{
						System.out.println("O Veículo já está parado!");
					}
					else
					{
						veiculo.parar();
						System.out.println(veiculo);
					}
					break;
				case 4:
					System.out.println("Saindo...");
					break;
				default:
					System.out.println("Opção inválida!");
					break;
			}
			
			if (opcao == 4)
			{
				break;
			}
		} while (opcao != 4);
		
		
		sc.close();
	}
}
