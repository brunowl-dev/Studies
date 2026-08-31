      ******************************************************************
      * Author: BRUNO WAI LU
      * Date: 08/05/2026
      * Purpose: Cálculo de área a*b
      * Tectonics: cobc
      ******************************************************************
       IDENTIFICATION DIVISION.
       PROGRAM-ID. PROG02.
       AUTHOR. BRUNO WAI LU.
       DATA DIVISION.
       FILE SECTION.
       WORKING-STORAGE SECTION.
       77 LARGURA PIC 9(3) VALUE ZEROS.
       77 ALTURA PIC 9(3) VALUE ZEROS.
       77 AREA-RESULT PIC 9(3) VALUE ZEROS.
       PROCEDURE DIVISION.
       MAIN-PROCEDURE.
            DISPLAY "Cálculo de área A*B"
            DISPLAY "Largura: "
            ACCEPT LARGURA
            DISPLAY "ALTURA: "
            ACCEPT ALTURA
            MULTIPLY LARGURA BY ALTURA GIVING AREA-RESULT.
            DISPLAY "AREA: " AREA-RESULT "m²".
            STOP RUN.
       END PROGRAM PROG02.
