package GUIAula;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Informa_dados extends JFrame implements ActionListener 
{

	Dados_Contribuinte receita = new Dados_Contribuinte();
	
	JLabel L1, L2, L3, L4, L5;
	JButton B1;
	JTextField T1, T2, T3, T4;
	JCheckBox C1, C2;
	
	boolean j1, j2;
	String nome, cpf, cnpj, cartao;

public static void main(String[] args) 
{
	JFrame janela = new Informa_dados();
	janela.show();
	WindowListener x = new WindowAdapter()
	{	public void windowClosing (WindowEvent fecha)
		{System.exit(0);}
	};
	janela.addWindowListener(x);
}

Informa_dados()
{
	setTitle("PROTÓTIPO DE ENGENHARIA DE SOFTWARE III");
	setSize(800, 400);
	
	getContentPane().setBackground(new Color(200, 200, 200));
	getContentPane();setLayout(new GridLayout(6,2));
	
	L1 = new JLabel("Identificação");
	L1.setForeground(Color.blue);
	L1.setFont(new Font(" ", Font.BOLD, 14));
	T1 = new JTextField();
	T1.setBackground(Color.white);
	T1.setForeground(Color.gray);
	
	
	L2 = new JLabel("CPF");
	L2.setForeground(Color.blue);
	L2.setFont(new Font(" ", Font.BOLD, 14));
	T2 = new JTextField();
	T2.setBackground(Color.white);
	T2.setForeground(Color.gray);
	
	L3 = new JLabel("CNPJ");
	L3.setForeground(Color.blue);
	L3.setFont(new Font(" ", Font.BOLD, 14));
	T3 = new JTextField();
	T3.setBackground(Color.white);
	T3.setForeground(Color.gray);
	
	L4 = new JLabel("Cartão");
	L4.setForeground(Color.blue);
	L4.setFont(new Font(" ", Font.BOLD, 14));
	T4 = new JTextField();
	T4.setBackground(Color.white);
	T4.setForeground(Color.gray);
	
	L5 = new JLabel("");
	L5.setForeground(Color.gray);
	L5.setFont(new Font(" ", Font.BOLD, 14));
	
	C1 = new JCheckBox("Pessoa Física");
	C2 = new JCheckBox("Pessoa Jurídica");
	
	B1 = new JButton("Leitura de dados");
	B1.setBackground(Color.white);
	B1.setForeground(Color.red);
	B1.addActionListener(this);
	
	getContentPane().add(T1);
	getContentPane().add(L1);
	getContentPane().add(T2);
	getContentPane().add(L2);
	getContentPane().add(T3);
	getContentPane().add(L3);
	getContentPane().add(T4);
	getContentPane().add(L4);
	
	getContentPane().add(C1);
	getContentPane().add(C2);
	
	getContentPane().add(B1);
	getContentPane().add(L5);
}

	public void actionPerformed(ActionEvent e)
	{
		if (e.getSource() == B1)
		{
			nome = T1.getText();
			cpf = T2.getText();
			cnpj = T3.getText();
			cartao = T4.getText();
			j1 = C1.isSelected();
			j2 = C2.isSelected();
			informa_dados();
		}
	}
	
	public void informa_dados()
	{
		receita.setNome(nome);
		receita.setCPF(cpf);
		receita.setCNPJ(cnpj);
		receita.setCartao(cartao);
		
		System.out.println("IDENTIFICAÇÃO DO CONTRIBUINTE\t" + receita.getNome());
		System.out.println("CARTÃO DO CONTRIBUINTE OU EMPRESA\t" + receita.getCartao());
		
		if (j1 == true)
		{
			System.out.println("CPF DO CONTRIBUINTE\t" + receita.getCPF());
		}
		if (j2== true)
		{
			System.out.println("CNPJ DO CONTRIBUINTE\t" + receita.getCNPJ());
		}
	}


}
