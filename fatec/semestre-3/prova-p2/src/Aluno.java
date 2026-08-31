public class Aluno {
	String nome;
	double nota1, nota2, media;
	
	public Aluno(String nome, double nota1, double nota2) {
		this.nome = nome;
		this.nota1 = nota1;
		this.nota2 = nota2;
		this.media = (nota1 + nota2) / 2;
	}
	
	public Double getMEDIA() {
		return media;
	}
	
	public String getNome() {
		return nome;
	}
	
}
