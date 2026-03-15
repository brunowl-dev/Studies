package Aula4;
import javax.swing.JOptionPane;
public class ConsultaLivraria {

	public static void main(String[] args) {
		Livraria l = new Livraria();
		String editora = JOptionPane.showInputDialog(null, "Digite a editora:");
		String autor = JOptionPane.showInputDialog(null, "Digite a autor:");
		String livro = JOptionPane.showInputDialog(null, "Digite o livro:");
		int quantidade = Integer.parseInt(JOptionPane.showInputDialog(null, "Digite a quantidade:"));
		double preco = Double.parseDouble(JOptionPane.showInputDialog(null, "Digite o preço:"));
		
		l.setEditora(editora);
		l.setAutor(autor);
		l.setLivro(livro);
		l.setQuantidade(quantidade);
		l.setPreco(preco);
		
		String mensagem = "EDITORA: " + editora + "\nAUTOR: " + autor + "\nLIVRO: " + livro + "\nQUANTIDADE: " + quantidade + "\nPREÇO: " + preco;
		JOptionPane.showMessageDialog(null, mensagem);
	}

}
