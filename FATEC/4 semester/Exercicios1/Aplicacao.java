package Exercicios1;
import javax.swing.JOptionPane;

public class Aplicacao 
{
	public static void main(String[] args) 
	{
		/*Criar aplicação executável e criar variáveis de instância para
inserir os valores dos atributos através do método construtor e
pelos métodos sets( );*/
		
		
		//Instância com os atributos inseridos pelo método construtor
		String materia = JOptionPane.showInputDialog(null, "Digite o nome da matéria: ");
		String conteudo_programatico = JOptionPane.showInputDialog(null, "Digite o conteúdo programático da disciplina: ");
		String criterio = JOptionPane.showInputDialog(null, "Digite o critério de avaliação: ");
		String bibliografia = JOptionPane.showInputDialog(null, "Digite a bibliografia: ");
		
		PlanodeEnsino construtor = new PlanodeEnsino(materia, conteudo_programatico, criterio, bibliografia);
		
		/*6-Retornar os valores inseridos pelos métodos gets( ),
		mostrando-os no console.*/
		String mensagem = "INSTÂNCIA 1\nMATERIA: " + construtor.getMateria() + "\nCONTEÚDO PROGRAMÁTICO: " + construtor.getConteudo() + "\nCRITÉRIO DE AVALIAÇÃO: " + construtor.getCriterio() + "\nBIBLIOGRAFIA: " + construtor.getBibliografia();
		System.out.println(mensagem);
		
		
		
		//Instância com os atributos inseridos pelo método set
		materia = JOptionPane.showInputDialog(null, "Digite o nome da matéria: ");
		conteudo_programatico = JOptionPane.showInputDialog(null, "Digite o conteúdo programático da disciplina: ");
		criterio = JOptionPane.showInputDialog(null, "Digite o critério de avaliação: ");
		bibliografia = JOptionPane.showInputDialog(null, "Digite a bibliografia: ");
		
		PlanodeEnsino encapsulamento = new PlanodeEnsino();
		encapsulamento.setMateria(materia);
		encapsulamento.setConteudo(conteudo_programatico);
		encapsulamento.setCriterio(criterio);
		encapsulamento.setBibliografia(bibliografia);
		
		/*6-Retornar os valores inseridos pelos métodos gets( ),
		mostrando-os no console.*/
		mensagem = "INSTÂNCIA 2\nMATERIA: " + encapsulamento.getMateria() + "\nCONTEÚDO PROGRAMÁTICO: " + encapsulamento.getConteudo() + "\nCRITÉRIO DE AVALIAÇÃO: " + encapsulamento.getCriterio() + "\nBIBLIOGRAFIA: " + encapsulamento.getBibliografia();
		System.out.println("\n" + mensagem);
		
	}

}
