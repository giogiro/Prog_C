/*Esercizio 2
Array quasi ordinato 13
 Diciamo che un array a[] è "quasi ordinato" se tutti i
valori negativi (se esistono) precedono i valori maggiori o
uguali di zero (se esistono); si noti che i valori negativi
possono comparire in ordine qualsiasi, come pure i valori
maggiori o uguali di zero.
 Ad esempio l'array {-1, -7, 8, 10, 8, 1} è quasi ordinato,
come gli array {-9, -7, -1, -3} e {13, 9, 0, 21, 33},
 mentre l'array {3, -1, 4, 5} non lo è (compare un valore
>= 0 prima di uno negativo).
 Scrivere la funzione int quasi_ordinato(int a[], int n)
che, dato in input un array a[] non vuoto e la sua
lunghezza n, ritorna 1 se e solo se a[] è quasi ordinato, 0
altrimenti.*/
#include<stdio.h>
#include<stdlib.h>
#define N 6

int quasi_ordinato(int a[], int n);

int main()
{
    int array[N] = {1, 7, 8, 10, 8, 1};
    printf("%d\n", quasi_ordinato(array, N));
}

int quasi_ordinato(int a[], int n)
{
    int i, flag = 0, q_ordinato = 1;

    for(i=0; i<n; i++)
    {
        if(*(a+i)>0)
            flag = 1;

        if(*(a+i)<0 && flag == 1)
            q_ordinato = 0;
        
    }
    return q_ordinato;
}

