package view;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;

import business.*;

import java.awt.Container;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;

public class Formulario 
{
	private JFrame frame;
	private JLabel lblValor1, lblValor2, lblResultado, lblTitulo;
	private JTextField ftxtValor1, ftxtValor2;
	private JButton btnAdd, btnSub, btnMult, btnDiv;
	private Calculo calculo = null;
	private float valor1, valor2;
	
	public Formulario()
	{
		InicializaComponentes();
	}
	
	private void atualizaResultado()
	{
		lblResultado.setText("RESULTADO: " + calculo.getResultado());	
	}
	
	private void InicializaComponentes()
	{
		frame = new JFrame("Calculadora JFrame");
		frame.setBounds(100, 100, 500, 500);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setLayout(null);
		
		Container painelDeConteudo = frame.getContentPane();
		
		lblTitulo = new JLabel("Calculadora");
		lblTitulo.setBounds(187, 0, 200, 25);
		lblTitulo.setFont(new Font("Arial", Font.BOLD, 16));
		painelDeConteudo.add(lblTitulo);
		
		lblValor1 = new JLabel("Valor 1");
		lblValor1.setBounds(45, 50, 70, 25);
		lblValor1.setFont(new Font("Arial", Font.BOLD, 16));
		painelDeConteudo.add(lblValor1);
		
		ftxtValor1 = new JTextField();
		ftxtValor1.setBounds(25, 75, 100, 25);
		ftxtValor1.setFont(new Font("Times New Roman", Font.PLAIN, 16));
		painelDeConteudo.add(ftxtValor1);
		
		lblValor2 = new JLabel("Valor 2");
		lblValor2.setBounds(375, 50, 70, 25);
		lblValor2.setFont(new Font("Arial", Font.BOLD, 16));
		painelDeConteudo.add(lblValor2);
		
		ftxtValor2 = new JTextField();
		ftxtValor2.setBounds(350, 75, 100, 25);
		ftxtValor2.setFont(new Font("Times New Roman", Font.PLAIN, 16));
		painelDeConteudo.add(ftxtValor2);
		
		btnAdd = new JButton("ADIÇÃO");
		btnAdd.setBounds(25, 150, 435, 25);
		btnAdd.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				valor1 = Float.parseFloat(ftxtValor1.getText());
				valor2 = Float.parseFloat(ftxtValor2.getText());
				calculo = new Adicao(valor1, valor2);
				calculo.calcular();
				atualizaResultado();
			}
		});
		painelDeConteudo.add(btnAdd);
		
		btnSub = new JButton("SUBTRAÇÃO");
		btnSub.setBounds(25, 180, 435, 25);
		btnSub.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				valor1 = Float.parseFloat(ftxtValor1.getText());
				valor2 = Float.parseFloat(ftxtValor2.getText());
				calculo = new Subtracao(valor1, valor2);
				calculo.calcular();
				atualizaResultado();
			}
		});
		painelDeConteudo.add(btnSub);
		
		btnMult = new JButton("MULTIPLICAÇÃO");
		btnMult.setBounds(25, 210, 435, 25);
		btnMult.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				valor1 = Float.parseFloat(ftxtValor1.getText());
				valor2 = Float.parseFloat(ftxtValor2.getText());
				calculo = new Multiplicacao(valor1, valor2);
				calculo.calcular();
				atualizaResultado();
			}
		});
		painelDeConteudo.add(btnMult);
		
		btnDiv = new JButton("DIVISÃO");
		btnDiv.setBounds(25, 240, 435, 25);
		btnDiv.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				valor1 = Float.parseFloat(ftxtValor1.getText());
				valor2 = Float.parseFloat(ftxtValor2.getText());
				calculo = new Divisao(valor1, valor2);
				calculo.calcular();
				atualizaResultado();
			}
		});
		painelDeConteudo.add(btnDiv);
		
		lblResultado = new JLabel("RESULTADO: ");
		lblResultado.setBounds(30, 0, 400, 800);
		lblResultado.setFont(new Font("Arial", Font.BOLD, 16));
		painelDeConteudo.add(lblResultado);
		
		frame.setVisible(true);
	}
}
