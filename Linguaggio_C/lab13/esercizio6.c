/*Scrivere un programma C che richiede all'utente di inserire due stringhe e determina se sono uguali o diverse, a prescindere da caratteri maiuscoli o 
minuscoli.
Nel caso di stringhe diverse il programma deve visualizzarle in ordine lessicografico e, in subordine, in ordine di lunghezza. In altre parole: l'ordine tra 
i caratteri é determinato dalla tabella ASCII e, nel caso una stringa sia prefisso dell'altra, viene prima quella piú corta.
Per esempio: se le due stringhe sono "ora" e "orario", si deve scrivere prima "ora" e poi "orario".
Le seguenti funzioni devono essere dichiarate nel header file my_functions.h e definite nel file my_functions.c:

int compareTo(char this [ ], char that [ ]) Considera l'ordine lessicografico, la lunghezza in subordine, e restituisce: un valore negativo se this precede 
that, un valore positivo se this segue that, il valore 0 se le due stringhe sono uguali.

void copy_to_lower_cases(char this [ ], char that [ ]) Copia la stringa this nella stringa that utilizzando solo caratteri minuscoli. Per esempio, se this é 
"LaTeX-2e" allora that diventa "latex-2e".

bool equals_ignore_cases(char [ ], char [ ]) Verifica se due stringhe sono uguali, a pre-
scindere da caratteri maiuscoli o minuscoli;

Nota: non utilizzare le funzioni definite in string.h.
Nel file main.c deve essere definita la funzione int main(void) che richiama le precedenti
funzioni per risolvere l'esercizio.
Esempio:
$ ./a.out
Prima stringa massimo 80 caratteri: BaNaNa
Seconda stringa massimo 80 caratteri: bAnAnA
Le stringhe sono uguali, a prescindere da caratteri minuscoli/maiuscoli.
$ ./a.out
Prima stringa massimo 80 caratteri: BaNaNa
Seconda stringa massimo 80 caratteri: bAndAnA
Le stringhe sono diverse,
eccole scritte in ordine alfabetico: BaNaNa bAndAnA
$ ./a.out
Prima stringa massimo 80 caratteri: bananA
Seconda stringa massimo 80 caratteri: banDaNa
Le stringhe sono diverse,
eccole scritte in ordine alfabetico: banDaNa bananA
$ ./a.out
Prima stringa massimo 80 caratteri: bAnDa
Seconda stringa massimo 80 caratteri: bAnDaNa
Le stringhe sono diverse,
eccole scritte in ordine alfabetico: bAnDa bAnDaNa*/

#include<stdio.h>
#include"my_functions.h"
#define L 100

int main(){

    char stringa1[L], stringa2[L];
    char stringa1Min[L], stringa2Min[L];

    printf("inserire prima stringa: ");
    fgets(stringa1, L, stdin);
    printf("inserire seconda stringa: ");
    fgets(stringa2, L, stdin);

    copy_to_lower_cases(stringa1, stringa1Min);
    copy_to_lower_cases(stringa2, stringa2Min);


    for(int i=0; stringa1Min[i]!='\0'; i++){
        printf("%c", stringa1Min[i]);
    }
    printf("\n");

}