package FigurasGeometricas;

public class Retangulo extends Figuras_geometricas
{
	private double lado_a;
	private double lado_b;
	private double area;
	
	Retangulo(){};
	
	Retangulo(double lado_a, double lado_b)
	{
		this.lado_a = lado_a;
		this.lado_b = lado_b;
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
	
	public double getArea()
	{
		return lado_a * lado_b;
	}
}
