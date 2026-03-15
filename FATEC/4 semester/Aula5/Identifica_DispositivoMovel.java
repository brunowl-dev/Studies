package Aula5;

public class Identifica_DispositivoMovel {

	public static void main(String[] args) {
		//primeira instância
		Dispositivo_Movel a = new Dispositivo_Movel();
		a.identifica_numero("13 99655 8666");
		a.identifica_user("Carla");
		//segunda instância
				Dispositivo_Movel b = new Dispositivo_Movel();
				b.identifica_numero("13 99777 6688");
				b.identifica_user("Giovana");
				
		System.out.println("numero do telefone: " + a.numero);
		System.out.println("uusário do telefone: " + a.usuario);
		
		System.out.println("numero do telefone: " + b.numero);
		System.out.println("uusário do telefone: " + b.usuario);
		
		b.DDD = 17;
		a.DDD = 16;
		
		System.out.println("DDD do telefone: " + b.DDD);
		System.out.println("DDD do telefone: " + a.DDD);
	}

}
