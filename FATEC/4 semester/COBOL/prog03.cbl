      ******************************************************************
      * Author: BRUNO WAI LU
      * Date: 08/05/2026
      * Purpose: Controle de nota
      * Tectonics: cobc
      ******************************************************************
       IDENTIFICATION DIVISION.
       PROGRAM-ID. PROG03.
       DATA DIVISION.
       FILE SECTION.
       WORKING-STORAGE SECTION.
       77 WRK-NOME PIC X(30).
       77 WRK-MATERIA PIC X(15).
       77 WRK-NOTA PIC 9(2).
       PROCEDURE DIVISION.
       MAIN-PROCEDURE.
            DISPLAY "POR FAVOR, DIGITE SEU NOME:"
            ACCEPT WRK-NOME

            DISPLAY "DIGITE A MATERIA QUE VOCE ESTA CURSANDO:"
            ACCEPT WRK-MATERIA

            DISPLAY "DIGITE SUA NOTA:"
            ACCEPT WRK-NOTA

            DISPLAY 'OLA, ' WRK-NOME
               'VOCE ESTA MATRICULADO NA MATERIA ' WRK-MATERIA
               'SUA NOTA FOI ' WRK-NOTA

            GOBACK.
            STOP RUN.
       END PROGRAM PROG03.
