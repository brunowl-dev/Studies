package view;
import model.*;
import java.util.Scanner;

public class Principal 
{
	public static void main(String[] args) 
	{
		Scanner sc = new Scanner(System.in);
		float t1, t2;
		
		System.out.println("Digite a temperatura mínima");
		t1 = sc.nextFloat();
		
		System.out.println("Digite a temperatura máxima");
		t2 = sc.nextFloat();
		
		CamaraTermica temperatura = new CamaraTermica(t1, t2);
		
		System.out.printf("Temperatura mínima:\nCelsius: %.2f°C\nFahrenheit: %.2f°F\n", temperatura.getTemperaturaMinima().getCelsius(), temperatura.getTemperaturaMinima().getFahrenheit());
		
		System.out.printf("Temperatura máxima:\nCelsius: %.2f°C\nFahrenheit: %.2f°F\n", temperatura.getTemperaturaMaxima().getCelsius(), temperatura.getTemperaturaMaxima().getFahrenheit());
		
		sc.close();
	}
}
