/* Scrivere una funzione sort che ordina 3 interi in ordine crescente. 
 La funzione non deve utilizzare un array ma 3 puntatori.
 La funzione deve essere richiamata dalla funzione main, la quale si occupa anche di richiedere i tre interi all’utente e stampare il risultato.*/

#include<stdio.h>

void sort(int *a, int *b, int *c);

int main(){
    int x, y, z;
    printf("Inserire tre numeri interi separati da uno spazio: ");
    scanf("%i %i %i", &x, &y, &z);
    sort(&x, &y, &z);
    printf("Numeri ordinati: %i, %i, %i\n", x, y, z);
}

void sort(int *a, int *b, int *c){
    if (*a > *b)

    }
}