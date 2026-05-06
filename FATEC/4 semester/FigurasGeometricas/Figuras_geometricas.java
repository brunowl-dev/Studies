package FigurasGeometricas;

public class Figuras_geometricas 
{
	private double lado_a;
	private static double lado_b;
	private double lado_c;
	private double area;
	
	Figuras_geometricas()
	{
		lado_a = 2;
		lado_b = 3;
		lado_c = 1;
	}
	
	public void setLado_a(double lado_a)
	{
		this.lado_a = lado_a;
	}
	
	public void setLado_b(double lado_b)
	{
		this.lado_b = lado_b;
	}
	
	public double getLado_a()
	{
		return lado_a;
	}
	
	public double getLado_b()
	{
		return lado_b;
	}
	
	public double getArea(double lado_a, double lado_b)
	{
		this.lado_a = lado_a;
		this.lado_b = lado_b;
		area = lado_a * lado_b;
		return area;
	}
	
	public double getArea()
	{
		area = lado_c * lado_c;
		return area;
	}
}
