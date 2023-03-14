/*Scrivere una funzione void sum(double *s, double x, double y)

 Che assegna la somma tra il secondo e il terzo argomento (passati per valore) al primo argomento (passato per riferimento).

 La funzione deve essere richiamata dalla funzione main, la quale si occupa anche di richiedere due double all’utente e stampare il risultato.*/

#include<stdio.h>

void sum(double *s, double x, double y);

int main(){
    double x, y, somma;
    double *s;

    s = &somma;

    printf("inserisci due valori da sommare: ");
    scanf("%lf %lf", &x, &y);

    sum(s, x, y);
    printf("somma: %g\n", somma);


}

void sum(double *s, double x, double y){
    *s = x + y;
}


