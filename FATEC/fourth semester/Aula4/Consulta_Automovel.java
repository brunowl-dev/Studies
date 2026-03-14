package Aula4;
import javax.swing.JOptionPane;

public class Consulta_Automovel {

	public static void main(String[] args) {
		String marca = JOptionPane.showInputDialog("Digite o nome da marca do veículo");
		String modelo = JOptionPane.showInputDialog("Digite o nome o modelo do veículo");
		String cor = JOptionPane.showInputDialog("Digite o nome a cor do veículo");
		double preco = Double.parseDouble(JOptionPane.showInputDialog("Digite o preço do veículo"));
		
		Automovel a = new Automovel();
		a.setMarca(marca);
		a.setModelo(modelo);
		a.setCor(cor);
		a.setPreco(preco);
		
		String mensagem = "VEÍCULO\nMARCA: " + a.getMarca() + "\nMODELO: " + a.getModelo() + "\nCOR: " + a.getCor() + "\nPREÇO: R$" + a.getPreco() + "\n";
		JOptionPane.showMessageDialog(null, mensagem);

	}

}
