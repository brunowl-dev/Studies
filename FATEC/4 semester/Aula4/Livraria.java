package Aula4;

public class Livraria 
{
	private String editora;
	private String autor;
	private String livro;
	int quantidade;
	double preco;
	
	public void setEditora(String editora)
	{
		this.editora = editora;
	}
	
	public void setAutor(String autor)
	{
		this.autor = autor;
	}
	
	public void setLivro(String livro)
	{
		this.livro = livro;
	}
	
	public void setQuantidade(int quantidade)
	{
		this.quantidade = quantidade;
	}
	
	public void setPreco(double preco)
	{
		this.preco = preco;
	}
	
	public String getEditora()
	{
		return editora;
	}
	
	public String getAutor()
	{
		return autor;
	}
	
	public String getLivro()
	{
		return livro;
	}
	
	public int getQuantidade()
	{
		return quantidade;
	}
	
	public double getPreco()
	{
		return preco;
	}
}
