      ******************************************************************
      * Author:
      * Date:
      * Purpose:
      * Tectonics: cobc
      ******************************************************************
       IDENTIFICATION DIVISION.
       PROGRAM-ID. EX7.
       AUTHOR. BRUNO WAI LU.
       DATE-WRITTEN. 15/05/2026

      *Desenvolva um programa em COBOL que armazene em uma matriz o
      *nome de 6 disciplinas do Curso de ADS e mostre em tela.

       ENVIRONMENT DIVISION.
       CONFIGURATION SECTION.
       SPECIAL-NAMES.
           DECIMAL-POINT IS COMMA.

       DATA DIVISION.
       FILE SECTION.

       WORKING-STORAGE SECTION.
       01 CURSO-ADS.
           03 DISCIPLINAS PIC X(100) OCCURS 6.
           03 DISC-ENTRADA PIC X(100).

       01 WT-CONTADORES.
           03 WT-CONTADOR PIC 9(1) VALUE 1.

       PROCEDURE DIVISION.
       PERFORM LACO-INSERE UNTIL WT-CONTADOR > 6.
       MOVE 1 TO WT-CONTADOR.
       PERFORM LACO-EXIBE UNTIL WT-CONTADOR > 6.
       STOP RUN.
       LACO-INSERE.
           DISPLAY 'INSIRA A MATERIA N°'WT-CONTADOR.
           ACCEPT DISC-ENTRADA.
           MOVE DISC-ENTRADA TO DISCIPLINAS(WT-CONTADOR).
           ADD 1 TO WT-CONTADOR.

       LACO-EXIBE.
           DISPLAY 'MATERIA N°'WT-CONTADOR.
           DISPLAY DISCIPLINAS(WT-CONTADOR).
           ADD 1 TO WT-CONTADOR.

       END PROGRAM EX7.
