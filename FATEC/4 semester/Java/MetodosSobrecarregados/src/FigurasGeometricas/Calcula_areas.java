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
	}
}
