******************************************************************
      * Author:
      * Date:
      * Purpose:
      * Tectonics: cobc
      ******************************************************************
       IDENTIFICATION DIVISION.
       PROGRAM-ID. EX9.
       AUTHOR. BRUNO WAI LU.
       DATE-WRITTEN. 15/05/2026

      *    Desenvolva um programa em COBOL que armazene em uma matriz, a
      *    partir da entrada de um número, informe os próximos 5 números
      *    pares em
      *    ordem crescente numa lista e depois os 5 números ímpares
      *    em ordem
      *    descrecente, e, ao final, perguntando se o usuário
      *    quer novamente inserir
      *    um novo número ou encerrar.

       DATA DIVISION.
       FILE SECTION.

       WORKING-STORAGE SECTION.
       01 VAR-AUXILIAR.
           03 WT-CONTADOR PIC 9(1) VALUE 1.
           03 NUM-ENTRADA PIC S9(3).
           03 NUM-AUXILIAR PIC S9(3).
           03 RESTO PIC 9(3).
           03 QUOCIENTE PIC 9(3).

       01 VETORES OCCURS 5.
           03 PARES PIC S9(3).
           03 IMPARES PIC S9(3).

       PROCEDURE DIVISION.
       DISPLAY 'DIGITE O NÚMERO DE ENTRADA'
       ACCEPT NUM-ENTRADA.
       MOVE NUM-ENTRADA TO NUM-AUXILIAR.
       PERFORM ADICIONA-PARES UNTIL WT-CONTADOR > 5.

       MOVE 1 TO WT-CONTADOR.
       MOVE NUM-ENTRADA TO NUM-AUXILIAR
       PERFORM ADICIONA-IMPARES UNTIL WT-CONTADOR > 5.

       DISPLAY 'NUMERO DE ENTRADA: ' NUM-ENTRADA

       MOVE 1 TO WT-CONTADOR.
       DISPLAY 'PARES'
       PERFORM EXIBE-PARES UNTIL WT-CONTADOR > 5.

       MOVE 1 TO WT-CONTADOR.
       DISPLAY 'IMPARES'
       PERFORM EXIBE-IMPARES UNTIL WT-CONTADOR > 5.

       STOP RUN.

       ADICIONA-PARES.
           ADD 1 TO NUM-AUXILIAR
           DIVIDE NUM-AUXILIAR BY 2 GIVING QUOCIENTE REMAINDER RESTO
           IF RESTO = 0
               MOVE NUM-AUXILIAR TO PARES(WT-CONTADOR)
               ADD 1 TO WT-CONTADOR
           END-IF.

       ADICIONA-IMPARES.
           SUBTRACT 1 FROM NUM-AUXILIAR
           DIVIDE NUM-AUXILIAR BY 2 GIVING QUOCIENTE REMAINDER RESTO
           IF RESTO NOT = 0
               MOVE NUM-AUXILIAR TO IMPARES(WT-CONTADOR)
               ADD 1 TO WT-CONTADOR
           END-IF.

       EXIBE-PARES.
           DISPLAY PARES(WT-CONTADOR)
           ADD 1 TO WT-CONTADOR.

       EXIBE-IMPARES.
           DISPLAY IMPARES(WT-CONTADOR)
           ADD 1 TO WT-CONTADOR.

       END PROGRAM EX9.
