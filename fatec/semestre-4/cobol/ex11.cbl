      ******************************************************************
      * Author: BRUNO WAI LU
      * Date: 2026
      * Purpose: CALCULO TRIGONOMETRICO
      * Tectonics: cobc
      ******************************************************************
       IDENTIFICATION DIVISION.
       PROGRAM-ID. EX11.
       AUTHOR. BRUNO WAI LU.
       DATA DIVISION.
       FILE SECTION.
       WORKING-STORAGE SECTION.
       01 VAR-AUX.
           03 CONTADOR-MEDIDAS PIC 9(3) VALUE 1.
           03 CONTINUAR PIC 9(1) VALUE ZERO.
           03 ENTRADA-OPOSTO PIC 9(3).
           03 ENTRADA-HIPOTENUSA PIC 9(3).
           03 CALCULA-ADJACENTE PIC 9(3)V9(2).
           03 DECIDE-CALCULO PIC 9(1).
           03 CALCULAR-SCT PIC 9(3)V9(2).
       01 VALORES.
           03 MEDIDAS OCCURS 360 TIMES.
                   05 OPOSTO-HIPOTENUSA PIC 9(3) OCCURS 2.
       PROCEDURE DIVISION.
       INICIO.
           DISPLAY 'DIGITE A MEDIDA DO CATETO OPOSTO: '
           ACCEPT ENTRADA-OPOSTO

           DISPLAY 'DIGITE A MEDIDA DA HIPOTENUSA: '
           ACCEPT ENTRADA-HIPOTENUSA

           MOVE ENTRADA-OPOSTO TO OPOSTO-HIPOTENUSA(CONTADOR-MEDIDAS, 1)
           MOVE ENTRADA-OPOSTO TO OPOSTO-HIPOTENUSA(CONTADOR-MEDIDAS, 2)

           DISPLAY 'VOCÊ QUER CALCULAR: '
           DISPLAY '1 - SENO'
           DISPLAY '2 - COSSENO'
           DISPLAY '3 - TANGENTE'
           ACCEPT DECIDE-CALCULO

           IF DECIDE-CALCULO = 1
               COMPUTE CALCULAR-SCT =
               ENTRADA-OPOSTO / ENTRADA-HIPOTENUSA
               DISPLAY 'O VALOR DO SENO É ' CALCULAR-SCT
           ELSE
               IF DECIDE-CALCULO = 2
                   COMPUTE CALCULA-ADJACENTE =
                   (ENTRADA-HIPOTENUSA * ENTRADA-HIPOTENUSA) -
                   (ENTRADA-OPOSTO * ENTRADA-OPOSTO)
                   COMPUTE CALCULA-ADJACENTE =
                   FUNCTION SQRT (CALCULA-ADJACENTE)
                   COMPUTE CALCULAR-SCT =
                   CALCULA-ADJACENTE / ENTRADA-HIPOTENUSA
                   DISPLAY 'O VALOR DO COSSENO É ' CALCULAR-SCT
               ELSE
                   COMPUTE CALCULA-ADJACENTE =
                   (ENTRADA-HIPOTENUSA * ENTRADA-HIPOTENUSA) -
                   (ENTRADA-OPOSTO * ENTRADA-OPOSTO).
                   COMPUTE CALCULA-ADJACENTE =
                   FUNCTION SQRT (CALCULA-ADJACENTE).
                   COMPUTE CALCULAR-SCT =
                   ENTRADA-OPOSTO / CALCULA-ADJACENTE
                   DISPLAY 'O VALOR DA TANGENTE É ' CALCULAR-SCT

           COMPUTE CONTADOR-MEDIDAS = CONTADOR-MEDIDAS + 1

           DISPLAY 'DESEJA CONTINUAR COM O PROGRAMA?'
           DISPLAY '1 - SIM; 0 - NÃO'
           ACCEPT CONTINUAR.

           IF CONTINUAR = 1
               GO TO INICIO.

           DISPLAY 'PROGRAMA ENCERRADO!'

           STOP RUN.
       END PROGRAM EX11.
