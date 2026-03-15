package Aula3;
import javax.swing.JOptionPane;
public class ConsultaLivraria 
{
	public static void main(String[] args) 
	{
		Livraria cultura = new Livraria();
		
		JOptionPane.showMessageDialog(null, "Categorias\n1 - Romance\n2 - Espírita\n3 - Informática\n");
		int codigo = Integer.parseInt(JOptionPane.showInputDialog(null, "Código: "));
		String editora = JOptionPane.showInputDialog(null, "Editora: ");
		String autor = JOptionPane.showInputDialog(null, "Autor: ");
		String livro = JOptionPane.showInputDialog(null, "Livro: ");
		int quantidade = Integer.parseInt(JOptionPane.showInputDialog(null, "Quantidade: "));
		double preco = Double.parseDouble(JOptionPane.showInputDialog(null, "Preço: "));
		
		cultura.editora = editora;
		cultura.autor = autor;
		cultura.livro = livro;
		cultura.quantidade = quantidade;
		cultura.preco = preco;
		
		cultura.Informa_Livros(codigo);
	}
}
