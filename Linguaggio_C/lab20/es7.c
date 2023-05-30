/*Si consideri una lista dinamica di interi, i cui elementi sono
del tipo definito come di seguito riportato:
typedef struct El {
int dato1;
int dato2;
struct El *next;
} ELEMENTO;
 Si codifichino in C le funzioni contamultipli() e multiplo().
 La funzione contamultipli() riceve come parametro la testa della lista e restituisce il numero di elementi della lista che hanno il primo valore numerico
(dato1) multiplo del secondo (dato2). Se la lista è vuota, la funzione restituisce il valore -1.
 Per verificare se un valore intero è multiplo di un altro la funzione deve richiamare la funzione ricorsiva multiplo() definita dallo studente.*/

#include<stdio.h>
#include<stdlib.h>
\1\\
typedef struct El sds{
int dato1;
int dato2;
struct El *next;
} ELEMENTO;

ELEMENTO * inserisci_in_coda(ELEMENTO *, int val1, int val2);
void print_list(ELEMENTO *);
int contamultipli(ELEMENTO *); 
int multiplo(int, int);

int main(){
    ELEMENTO *head = NULL;
    head = inserisci_in_coda(head, 1, 5);
    head = inserisci_in_coda(head, 4, 7);
    head = inserisci_in_coda(head, 4, 7);
    head = inserisci_in_coda(head, 4, 8);
    head = inserisci_in_coda(head, 4, 16);   

    print_list(head);
}

ELEMENTO * inserisci_in_coda(ELEMENTO *head, int num1, int num2)
{
    int i;
    ELEMENTO * nuovo = NULL;
    ELEMENTO * last = head;

    nuovo = (ELEMENTO *)malloc(sizeof(ELEMENTO *));
    nuovo->dato1 = num1;
    nuovo->dato2 = num2;
    nuovo->next = NULL;     //l'ultimo lo collego a NULL

    if(last != NULL){

        while(last->next != NULL)
        {
            last = last->next;
        }

    last->next = nuovo;     //collego il penultimo all'ultimo
    return head;
    }


    return nuovo;
}

void print_list(ELEMENTO *head)
{
    while(head != NULL)
    {
        printf("(%d, %d) ", head->dato1, head->dato2);
        head = head->next;
    }
    printf("\n");
}

int multiplo(int a, int b)
{
    if(a == 1 || b == 1)
        return 1;
    else
    {
        if(a%b == 0)
            return(multiplo(a/b, b));
        
        else if(b%a == 0)
            return(multiplo(a, b/a));

        else

}