package atividadeArrayList;
import java.util.ArrayList;
import javax.swing.JOptionPane;
public class ex2 {

	public static void main(String[] args) {
		/*Jogo da Palavra Oculta

Crie um jogo onde o usuário deve adivinhar uma palavra oculta (ex: "JAVA"). Use um array de char para armazenar a palavra e outro para mostrar os acertos. A cada tentativa, atualize a visualização da palavra com as letras corretas. O jogo termina quando a palavra for descoberta ou após 6 tentativas erradas.*/
		String OCULTA = "JAVA", PALAVRA = "____";
		char [] palavra = PALAVRA.toCharArray();
		char[] oculta = OCULTA.toCharArray();
		int i, acertos = 0;
		for (int tentativas = 0; tentativas < 6; tentativas++) {
			if (acertos == 4) {
				JOptionPane.showMessageDialog(null, "Você venceu\nA palavra era " + OCULTA);
				break;
			}
			String advinha = JOptionPane.showInputDialog(null, new String(palavra) + "\nDigite a letra: ");
			char letra = advinha.charAt(0);
			for (i = 0; i < 4; i++) {
				if (letra == oculta[i]) {
					palavra[i] = oculta[i];
					acertos++;
				}
			}
		}
	}

}
