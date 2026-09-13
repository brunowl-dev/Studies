package view;

import business.*;
import java.util.Scanner;

public class Principal {

    public static void main(String[] args) {
    	//Nome do aluno: Bruno Antonio Wai Lu
        IGeradorSenha gerador;

        // TODO:
        // Gerar duas senhas fortes
        Scanner sc = new Scanner(System.in);
        int tamanho;
        System.out.println("Digite o tamanho da senha forte 1:");
        tamanho = sc.nextInt();
        gerador = new GeradorSenhaForte(tamanho);
        System.out.println("SENHA FORTE 1");
        System.out.println(gerador.gerarSenha());
        
        System.out.println("Digite o tamanho da senha forte 2:");
        tamanho = sc.nextInt();
        gerador = new GeradorSenhaForte(tamanho);
        System.out.println("SENHA FORTE 2");
        System.out.println(gerador.gerarSenha());
        		
        // Gerar dois PINs
        gerador = new GeradorPin();
        gerador.gerarSenha();
        System.out.println("PIN 1");
        System.out.println(gerador.gerarSenha());
        
        System.out.println("PIN 2");
        System.out.println(gerador.gerarSenha());
        // Utilizar a variável "gerador" para demonstrar polimorfismo
        
        sc.close();
    }		
}
