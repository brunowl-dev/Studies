      ******************************************************************
      * Author: BRUNO WAI LU
      * Date: 08/05/2026
      * Purpose: EXERCICIO 6A
      * Tectonics: cobc
      ******************************************************************
       IDENTIFICATION DIVISION.
       PROGRAM-ID. PROG04.
       AUTHOR. BRUNO WAI LU.
       DATE-WRITTEN. 08/05/2026
       DATA DIVISION.
       FILE SECTION.
       WORKING-STORAGE SECTION.
       77 WRK-NOME PIC X(30).
       77 WRK-MATERIA PIC X(15).
       77 WRK-NOTA PIC 9(2).
       77 WRK-SITUACAO PIC X(20).
       77 WRK-ENCERRAR PIC X(1).
       PROCEDURE DIVISION.
       INICIO.
           MOVE SPACES TO WRK-NOME, WRK-MATERIA
           INITIALIZE WRK-NOTA

            DISPLAY "POR FAVOR, DIGITE SEU NOME:"
            ACCEPT WRK-NOME

            DISPLAY "DIGITE A MATERIA QUE VOCE ESTA CURSANDO:"
            ACCEPT WRK-MATERIA

            DISPLAY "DIGITE SUA NOTA:"
            ACCEPT WRK-NOTA

            IF WRK-NOTA >= 0 AND WRK-NOTA <= 4
                MOVE 'REPROVADO' TO WRK-SITUACAO
            ELSE
                IF WRK-NOTA = 5 OR WRK-NOTA = 6
                    MOVE 'EM RECUPERACAO' TO WRK-SITUACAO
                ELSE
                    IF WRK-NOTA >= 7 AND WRK-NOTA <= 10
                        MOVE 'APROVADO' TO WRK-SITUACAO
                    ELSE
                        MOVE 'NOTA INVALIDA' TO WRK-SITUACAO
                    END-IF
                END-IF
           END-IF

           DISPLAY 'OLA, ' WRK-NOME
               'VOCE ESTA MATRICULADO NA MATERIA ' WRK-MATERIA
               'SUA NOTA FOI ' WRK-NOTA
               ' VOCE ESTA ' WRK-SITUACAO

           DISPLAY 'DESEJA ENCERRAR O PROGRAMA?'
           DISPLAY '0 - NÃO'
           DISPLAY '1 - SIM'
           ACCEPT WRK-ENCERRAR

           IF WRK-ENCERRAR = 0
               GO TO INICIO.
            GOBACK.
            STOP RUN.
       END PROGRAM PROG04.
