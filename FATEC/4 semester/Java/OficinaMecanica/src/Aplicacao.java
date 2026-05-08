import javax.swing.JOptionPane;
public class Aplicacao 
{
	public static void main(String[] args) 
	{
		/*
		 * 4 - Criar uma classe que acesse a aplicação e que possa, através de uma interface
		 * com o usuário, como por exemplo, JOptionPane, de onde possam ser inseridos
		 * valores aos atributos e escolhido o tipo de serviço a ser utilizado, de
		 * acordo com o carro do usuário.
		 */
		OficinaMecanica carro = null;
		OrdemServico escolha = new OrdemServico();
		
		int tipo = Integer.parseInt(JOptionPane.showInputDialog("ESCOLHA DO ESTABELECIMENTO\n1-Oficina Mecanica\n2-Concessionaria Volks\n3-Concessionaria Ford\n"));
		
		carro = escolha.Encapsula_Instancia(tipo, carro);
		String marca = JOptionPane.showInputDialog("DIGITE A MARCA: ");
		String modelo = JOptionPane.showInputDialog("DIGITE O MODELO: ");
		carro.set_marca(marca);
		carro.set_modelo(modelo);
		
		System.out.println(carro.pintura() + "\n" + 
		carro.funilaria() + "\n" + 
		carro.eletrica() + "\n");

	}

}
