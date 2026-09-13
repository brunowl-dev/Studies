package business;

public class GeradorPin extends GeradorSenha{

    @Override
    public String gerarSenha() {
        // TODO implementar
    	char[] pin = new char[6];
    	char caractere = ' ';
    	int i, valido;
    	
    	// Atribuiçao dos caracteres obrigatorios, nao importa a ordem, pois depois será embaralhado	
    	
    	for (i = 0; i < 6; i++)
    	{
    		valido = 0;
    		do {
    			caractere = sortearCaractere(NUMEROS);
    			if (i != 0)
    			{	
    				if ((caractere != pin[i-1]) && (caractere != pin[i-1] - 1) && (caractere != pin[i-1] + 1))
    				{
    					valido = 1;
    				}
    			}
    			else {
    				valido = 1;
    			}
    		} while (valido == 0);
    		
    		pin[i] = caractere;
    	}
    	
    	String pinForte = new String(pin);
    	return pinForte;
    }
}
