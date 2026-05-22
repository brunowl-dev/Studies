      ******************************************************************
      * Author:
      * Date:
      * Purpose:
      * Tectonics: cobc
      ******************************************************************
       IDENTIFICATION DIVISION.
       PROGRAM-ID. EX12.
       AUTHOR. BRUNO WAI LU.
       DATA DIVISION.
       FILE SECTION.
       WORKING-STORAGE SECTION.
       01 VALORES.
           03 TABELAS OCCURS 360 TIMES.
               05 MEDIDAS-TRIANGULO PIC 9(3) OCCURS 3.
               05 MEDIDAS-CIRCULO PIC 9(3)V9(2) OCCURS 1.
       01 VAR-AUX.
           03 CONTADOR-TRIANGULO PIC 9(3) VALUE 1.
           03 CONTADOR-CIRCULO PIC 9(3) VALUE 1.
           03 LADO-A PIC 9(3).
           03 LADO-B PIC 9(3).
           03 LADO-C PIC 9(3).
           03 DECIDE PIC 9(1) VALUE ZERO.
           03 CONTINUAR PIC 9(1) VALUE ZERO.
           03 PERIMETRO-TRIANGULO PIC 9(3).
           03 AREA-TRIANGULO PIC 9(3)V9(2).
           03 AREA-CIRCULO PIC 9(3)V9(2).
           03 SEMI-PERIMETRO PIC 9(3)V9(2).
       PROCEDURE DIVISION.
       INICIO.
            DISPLAY 'CALCULAR'
            DISPLAY '1 - ÁREA E PERÍMETRO DO TRIÂNGULO'
            DISPLAY '2 - ÁREA DA CIRCUNFERÊNCIA'
            ACCEPT DECIDE.

            IF DECIDE = 1
                DISPLAY 'DIGITE, RESPECTIVAMENTE, AS SEGUINTES MEDIDAS'
                DISPLAY 'LADO A, LADO B, LADO C'
                ACCEPT LADO-A
                ACCEPT LADO-B
                ACCEPT LADO-C
                COMPUTE PERIMETRO-TRIANGULO = LADO-A + LADO-B + LADO-C
                COMPUTE SEMI-PERIMETRO = (LADO-A + LADO-B + LADO-C) / 2
                COMPUTE AREA-TRIANGULO =
                (SEMI-PERIMETRO - LADO-A) *
                (SEMI-PERIMETRO - LADO-B) * (SEMI-PERIMETRO - LADO-C)
                COMPUTE AREA-TRIANGULO =
                SEMI-PERIMETRO * AREA-TRIANGULO
                COMPUTE AREA-TRIANGULO = FUNCTION SQRT (AREA-TRIANGULO)
                DISPLAY 'ÁREA DO TRIANGULO: ' AREA-TRIANGULO 'm²'
                DISPLAY 'PERÍMETRO DO TRIANGULO: ' PERIMETRO-TRIANGULO
                MOVE LADO-A TO MEDIDAS-TRIANGULO(CONTADOR-TRIANGULO, 1)
                MOVE LADO-B TO MEDIDAS-TRIANGULO(CONTADOR-TRIANGULO, 2)
                MOVE LADO-C TO MEDIDAS-TRIANGULO(CONTADOR-TRIANGULO, 3)
                ADD 1 TO CONTADOR-TRIANGULO
            ELSE
                DISPLAY 'DIGITE O RAIO: '
                ACCEPT LADO-A
                COMPUTE AREA-CIRCULO = (LADO-A * LADO-A) * 3.14
                DISPLAY 'A AREA DA CIRCUNFERÊNCIA ' AREA-CIRCULO 'm²'
                MOVE LADO-A TO MEDIDAS-CIRCULO(CONTADOR-CIRCULO, 1)
                ADD 1 TO CONTADOR-CIRCULO.

           DISPLAY 'DESEJA CONTINUAR?'
           DISPLAY '1 - SIM; 0 - NÃO'
           ACCEPT CONTINUAR

           IF CONTINUAR = 1
               GO TO INICIO.

           DISPLAY 'PROGRAMA ENCERRADO'

            STOP RUN.
       END PROGRAM EX12.
