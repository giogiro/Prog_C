#include<stdio.h>

/*Considera l'ordine lessicografico, la lunghezza in subordine, e restituisce: un valore negativo se this precede  that, un valore positivo se this segue 
that, il valore 0 se le due stringhe sono uguali.*/
//int compareTo(char this [ ], char that [ ]);

/*Copia la stringa this nella stringa that utilizzando solo caratteri minuscoli. Per esempio, se this é "LaTeX-2e" allora that diventa "latex-2e".*/
void copy_to_lower_cases(char this [ ], char that [ ]);

/*Verifica se due stringhe sono uguali, a pre scindere da caratteri maiuscoli o minuscoli;*/
//bool equals_ignore_cases(char [ ], char [ ]);

//int compareTo(char this [ ], char that [ ]){
//}

void copy_to_lower_cases(char this [ ], char that [ ]){
    int i;

    for(i=0; this[i]!='\n'; i++){

        if (this[i]>64 && this[i]<91)
            that[i] = this[i] + 32;
        else
            that[i] = this[i];
    }
    that[i] = '\0';

}

//bool equals_ignore_cases(char [ ], char [ ]){
//}
