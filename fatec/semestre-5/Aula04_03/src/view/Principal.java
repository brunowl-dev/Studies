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
				
				System.out.println("Digite a potenca do veiculo em cavalos: ");
				int potencia = sc.nextInt();
				
				System.out.println("Digite o tipo de motor: ");
				String tipoMotor = sc.next();
				if (opcao == 1)
				{
					System.out.println("Digite a quantidade de portas");
					int quantidadePortas = sc.nextInt();
					veiculo = new Carro(modelo, fabricante, ano, quantidadePortas, potencia, tipoMotor);
				}
				else
				{
					veiculo = new Moto(modelo, fabricante, ano, potencia, tipoMotor);
				}
			}
		} while (opcao != 1 && opcao != 2);
		
		opcao = 0;
		do 
		{
			System.out.println("\n1 - Acelerar veículo\n2 - Desacelerar veículo\n3 - Parar veículo\n4 - Registrar manutencao\n5 - Sair");
			opcao = sc.nextInt();
			sc.nextLine();
			System.out.println();
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
					}
					break;
				case 4:
					System.out.println("Digite a data da última manutencao:");
					String dataManutencao = sc.nextLine();
					System.out.println("Digite o tipo de serviço: ");
					String tipoManutencao = sc.nextLine();	
					veiculo.registraManutencao(dataManutencao, tipoManutencao);
					break;
				case 5:
					System.out.println("Saindo...");
					break;
				default:
					System.out.println("Opção inválida!");
					break;
			}
			
			System.out.println(veiculo);
			
			if (opcao == 5)
			{
				break;
			}
		} while (opcao != 5);
		
		
		sc.close();
	}
}
