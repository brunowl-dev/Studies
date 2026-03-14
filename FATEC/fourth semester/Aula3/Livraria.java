package Aula3;
import javax.swing.JOptionPane;

public class Livraria 
{
	String editora, autor, livro, mensagem;
	int quantidade;
	double preco;
	
	public void Informa_Livros(int codigo)
	{
		switch(codigo)
		{
		
		case 1:
			mensagem = "CATEGORIA ROMANCE\n" + "LIVRO: " + livro + "\nEDITORA: " + editora + "\nAUTOR: " + autor + "\nQUANTIDADE: " + quantidade + "\nPREÇO: R$" + preco + "\n";
			JOptionPane.showMessageDialog(null, mensagem);
			break;
			
		case 2:
			mensagem = "CATEGORIA ESPÍRITA\n" + "LIVRO: " + livro + "\nEDITORA: " + editora + "\nAUTOR: " + autor + "\nQUANTIDADE: " + quantidade + "\nPREÇO: R$" + preco + "\n";
			JOptionPane.showMessageDialog(null, mensagem);
			break;
			
		case 3:
			mensagem = "CATEGORIA INFORMÁTICA\n" + "LIVRO: " + livro + "\nEDITORA: " + editora + "\nAUTOR: " + autor + "\nQUANTIDADE: " + quantidade + "\nPREÇO: R$" + preco + "\n";
			JOptionPane.showMessageDialog(null, mensagem);
			break;
			
		default:
			System.out.println("Código não corresponde a nenhuma categoria do livro\n");
		}
	}
}
