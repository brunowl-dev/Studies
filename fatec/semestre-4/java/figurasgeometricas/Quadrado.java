package FigurasGeometricas;

public class Quadrado extends Figuras_geometricas
{
	private double lado_a;
	private double area;
	
	Quadrado(double lado)
	{
		this.lado_a = lado;
	}
	
	Quadrado(){};
	
	public void setLado_a(double lado)
	{
		this.lado_a = lado;
	}
	
	public double getLado_a()
	{
		return lado_a;
	}
	
	public double getArea()
	{
		return lado_a * lado_a;
	}
}
