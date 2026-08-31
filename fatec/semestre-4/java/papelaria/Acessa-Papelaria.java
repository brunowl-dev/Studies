package Papelaria;

public class Acessa_Papelaria {
	public static void main(String[] args) {
		
		//primeiro acesso ao método construtor da super classe
		Papelaria a = new Papelaria();
		a.set_caderno("brochura");
		System.out.println("Caderno tipo: " + a.get_caderno());
		
		Papelaria b = new Papelaria("lápis de cor");
		System.out.println("Lápis tipo: " + b.get_lapis() + "\n");
		
		//segundo acesso agora ao método construtor da classe filha
		Material_Escolar c = new Material_Escolar();
		
		//terceiro acesso ao métodoc onstrutor da classe filha mas agora com parâmetros
		Material_Escolar d = new Material_Escolar(33.84, 20);
		System.out.println("preço do caderno R$" + d.get_preco_caderno());
		System.out.println("quantidade de caixa de lápis: " + d.get_quantidade_caixas_lapis());
		
		//nova classe, filha de material_escolar
		Caneta filha = new Caneta(0.7, "BIC", "preto");
		System.out.println("preço do caderno R$" + filha.get_preco_caderno());
		System.out.println("quantidade de caixa de lápis: " + filha.get_quantidade_caixas_lapis());
		System.out.println("espessura d caneta: " + filha.get_espessura() + "mm");
		System.out.println("marca da caneta: " + filha.get_marca());
		System.out.println("cor da caneta: " + filha.get_cor());
	}

}
