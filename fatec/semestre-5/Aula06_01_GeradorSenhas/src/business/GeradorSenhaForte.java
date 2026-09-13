package business;
import java.util.Scanner;

public class GeradorSenhaForte extends GeradorSenha {

    private int tamanho;
    Scanner sc = new Scanner(System.in);
    public GeradorSenhaForte(int tamanho) {
        // TODO validar tamanho mínimo
    	
    	if (tamanho < 12)
    	{
    		System.out.println("Digite um tamanho de senha válido! (Minimo 12 caracteres)");
    		do {
    			System.out.println("Digite novamente um tamanho: ");
    			tamanho = sc.nextInt();
    		} while (tamanho <  12 );
    		this.tamanho = tamanho;
    	}
    	else
    	{
    		this.tamanho = tamanho;
    	}	
    }

    @Override
    public String gerarSenha() {
        // TODO implementar
    	// Criação das variaveis e inicializacao
    	char[] senha = new char[tamanho];
    	char caractere = ' ';
    	int i, tipoCaractere;
    	
    	// Atribuiçao dos caracteres obrigatorios, nao importa a ordem, pois depois será embaralhado	
    	senha[0] = sortearCaractere(MAIUSCULAS);
    	senha[1] = sortearCaractere(MINUSCULAS);
    	senha[2] = sortearCaractere(NUMEROS);
    	senha[3] = sortearCaractere(ESPECIAIS);
    	
    	for (i = 4; i < tamanho; i++)
    	{
    		//Decisao aleatoria do tipo de caracter, tipos numerados de 1 a 4
    		tipoCaractere = random.nextInt(1,5);
    		
    		switch(tipoCaractere)
    		{
    			case 1:
    				caractere = sortearCaractere(MAIUSCULAS);
    				break;
    			case 2:
    				caractere = sortearCaractere(MINUSCULAS);
    				break;
    			case 3:
    				caractere = sortearCaractere(NUMEROS);
    				break;
    			case 4:
    				caractere = sortearCaractere(ESPECIAIS);
    				break;
    		}
    		
    		senha[i] = caractere;
    	}
    	
    	String senhaForte = new String(senha);
    	senhaForte = embaralhar(senhaForte);
        return senhaForte;
    }
    
}
