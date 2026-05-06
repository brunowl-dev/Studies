package FigurasGeometricas;

public class Calcula_areas 
{
	public static void main (String args[])
	{
		Figuras_geometricas figGeo = new Figuras_geometricas();
		System.out.println("Área do retângulo: " + figGeo.getArea(figGeo.getLado_a(), figGeo.getLado_b()));
		System.out.println("Área do quadrado: " + figGeo.getArea());
		figGeo.setLado_a(4);
		System.out.println("Área do retângulo: " + figGeo.getArea(figGeo.getLado_a(), figGeo.getLado_b()));
		System.out.println("Área do quadrado: " + figGeo.getArea());
		
		System.out.println("\nEXERCICIO 3\n");
		Quadrado quadrado = new Quadrado();
		quadrado.setLado_a(2);
		System.out.println("Área da classe filha quadrado: " + quadrado.getArea());
		
		Retangulo retangulo = new Retangulo();
		retangulo.setLado_a(5);
		retangulo.setLado_b(4);
		System.out.println("Área da classe filha retângulo: " + retangulo.getArea());
		
		Cubo cubo = new Cubo();
		cubo.setLado_a(3);
		cubo.setLado_b(3);
		cubo.setLado_c(3);
		System.out.println("Área da classe filha cubo: " + cubo.getArea());
	}
}
