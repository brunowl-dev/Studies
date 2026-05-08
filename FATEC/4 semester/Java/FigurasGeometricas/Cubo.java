package FigurasGeometricas;

public class Cubo extends Figuras_geometricas
{
	private double lado_a;
	private double lado_b;
	private double lado_c;
	private double area;
	
	Cubo(){};
	
	Cubo(double lado_a, double lado_b, double lado_c)
	{
		this.lado_a = lado_a;
		this.lado_b = lado_b;
		this.lado_c = lado_c;
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
	
	public void setLado_c(double lado_c)
	{
		this.lado_c = lado_c;
	}
	
	public double getLado_c()
	{
		return lado_c;
	}
	
	public double getArea()
	{
		return lado_a * lado_b * lado_c;
	}
}
