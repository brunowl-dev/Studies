******************************************************************
      * Author:
      * Date:
      * Purpose:
      * Tectonics: cobc
      ******************************************************************
       IDENTIFICATION DIVISION.
       PROGRAM-ID. ex8.
       AUTHOR. BRUNO WAI LU.
       DATE-WRITTEN. 15/05/2026

      *Desenvolva um programa em COBOL que armazene em uma matriz com
      *as notas P1, P2 e Atividade de um aluno em 6 disciplinas

       DATA DIVISION.
       FILE SECTION.

       WORKING-STORAGE SECTION.
       01 ENTRADA.
           03 ENTRADA-NOTA PIC 9(2)V9(2) VALUE ZERO.

       01 NOTAS OCCURS 6.
           03 P1 PIC 9(2)V9(2) VALUE ZEROS.
           03 P2 PIC 9(2)V9(2) VALUE ZEROS.
           03 ATT PIC 9(2)V9(2) VALUE ZEROS.

       01 WT-CONTADORES.
           03 WT-CONTADOR PIC 9(1) VALUE 1.

       PROCEDURE DIVISION.
       PERFORM LACO-INSERE UNTIL WT-CONTADOR > 6.
       MOVE 1 TO WT-CONTADOR.
       PERFORM LACO-EXIBE UNTIL WT-CONTADOR > 6.
       STOP RUN.
       LACO-INSERE.
      *    INPUT NOTAP1
           DISPLAY 'DIGITE A NOTA DA P1 DA MATERIA N°'WT-CONTADOR
           ACCEPT ENTRADA-NOTA
           MOVE ENTRADA-NOTA TO P1(WT-CONTADOR)

      *    INPUT NOTAP2
           DISPLAY 'DIGITE A NOTA DA P2 DA MATERIA N°'WT-CONTADOR
           ACCEPT ENTRADA-NOTA
           MOVE ENTRADA-NOTA TO P2(WT-CONTADOR)

      *    INPUT ATIVIDADE
           DISPLAY 'DIGITE A NOTA DA ATT DA MATERIA N°'WT-CONTADOR
           ACCEPT ENTRADA-NOTA
           MOVE ENTRADA-NOTA TO ATT(WT-CONTADOR)

           ADD 1 TO WT-CONTADOR.

       LACO-EXIBE.
           DISPLAY 'MATERIA N°'WT-CONTADOR
           DISPLAY 'P1: 'P1(WT-CONTADOR)
           DISPLAY 'P2: 'P2(WT-CONTADOR)
           DISPLAY 'ATIVIDADE: 'ATT(WT-CONTADOR)
           DISPLAY ''

           ADD 1 TO WT-CONTADOR.

       END PROGRAM ex8.
