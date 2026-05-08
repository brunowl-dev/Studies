package Aula4;
public class Informa_dados {
	public static void main(String[] args) 
	{
		Dados_Contribuinte a = new Dados_Contribuinte();
		a.setNome("Daniela Bento");
		a.setCPF("065.887.443-54");
		a.setCNPJ("776 998 /0001");
		a.setCartao("9776-J");
		
		System.out.println("Nome do contribuinte: " + a.getNome());
		System.out.println("CPF do contribuinte: " + a.getCPF());
		System.out.println("CNPJ do contribuinte: " + a.getCNPJ());
		System.out.println("Cartão do contribuinte: " + a.getCartao());
	}	

}
