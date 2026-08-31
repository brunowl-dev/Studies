      ******************************************************************
      * Author:
      * Date:
      * Purpose: Calculadora básica da fórmula de bhaskara
      * Tectonics: cobc
      ******************************************************************
       IDENTIFICATION DIVISION.
       PROGRAM-ID. EX13.
       AUTHOR. BRUNO WAI LU.
       DATA DIVISION.
       FILE SECTION.
       WORKING-STORAGE SECTION.
       01 VALORES.
           03 TABELA OCCURS 360 TIMES.
               05 ABC PIC 9(3) OCCURS 3.
       01 VAR-AUX.
           03 CONTADOR PIC 9(3) VALUE 1.
           03 VALOR-A PIC S9(3).
           03 VALOR-B PIC S9(3).
           03 VALOR-C PIC S9(3).
           03 DELTA PIC S9(3).
           03 VALOR-X PIC S9(3)V9(2).
           03 CONTINUAR PIC 9(3).
       PROCEDURE DIVISION.
       INICIO.
            DISPLAY 'DIGITE RESPECTIVAMENTE OS VALORES DE A, B E C'
            ACCEPT VALOR-A
            ACCEPT VALOR-B
            ACCEPT VALOR-C

            COMPUTE DELTA = (VALOR-B * VALOR-B)
            - (4 * VALOR-A * VALOR-C)

            IF DELTA < 0
                DISPLAY 'DELTA NEGATIVO, VALORES INVÁLIDOS!'
                GO TO INICIO
            ELSE
                COMPUTE VALOR-X = ((-VALOR-B) + FUNCTION SQRT (DELTA))
                / (2 * VALOR-A)

                DISPLAY 'X1: ' VALOR-X

                COMPUTE VALOR-X = ((-VALOR-B) - FUNCTION SQRT (DELTA))
                / (2 * VALOR-A)

                DISPLAY 'X2: ' VALOR-X
                MOVE VALOR-A TO ABC(CONTADOR, 1)
                MOVE VALOR-B TO ABC(CONTADOR, 2)
                MOVE VALOR-C TO ABC(CONTADOR, 3)

            DISPLAY 'DESEJA CONTINUAR?'
            DISPLAY '1 - SIM; 0 - NÃO'
            ACCEPT CONTINUAR

            IF CONTINUAR = 1
                GO TO INICIO

            DISPLAY 'PROGRAMA ENCERRADO'

            STOP RUN.
       END PROGRAM EX13.
