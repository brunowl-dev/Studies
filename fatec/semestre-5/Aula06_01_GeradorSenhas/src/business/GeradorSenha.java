	package business;
	
	import java.security.SecureRandom;
	
	public abstract class GeradorSenha implements IGeradorSenha {
	
	    protected static final String MAIUSCULAS =
	            "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	    protected static final String MINUSCULAS =
	            "abcdefghijklmnopqrstuvwxyz";
	
	    protected static final String NUMEROS =
	            "0123456789";
	
	    protected static final String ESPECIAIS =
	            "!@#$%&*?";
	
	    protected final SecureRandom random = new SecureRandom();
	
	    protected char sortearCaractere(String caracteres) {
	        int posicao = random.nextInt(caracteres.length());
	        return caracteres.charAt(posicao);
	    }
	
	    protected String embaralhar(String valor) {
	    	char[] caracteres = valor.toCharArray();
	    	
	
	        for (int i = caracteres.length - 1; i > 0; i--) {
	            int posicao = random.nextInt(i + 1);
	
	            char auxiliar = caracteres[i];
	            caracteres[i] = caracteres[posicao];
	            caracteres[posicao] = auxiliar;
	        }
	
	    	return new String(caracteres);
	    }
	}