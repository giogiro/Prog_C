/*Sia data una lista i cui nodi sono definiti tramite la
seguente struttura C:
struct nodo{
int valore;
struct nodo *next;
};
 Scrivere due funzioni C RICORSIVE che
ricevendo in ingresso un puntatore alla lista:
1) stampano la lista
2) contano quanti multipli di 3 sono presenti
nella lista.*/

#include<stdio.h>
#include<stdlib.h>

struct nodo
{
int valore;
struct nodo *next;
};

void print_lista(struct nodo *head);
int conta_multipli_3(struct nodo *head);
struct nodo * inser_in_testa(struct nodo *head, int valore);

int main()
{
    struct nodo *head = NULL;
    head = inser_in_testa(head, 6);
    head = inser_in_testa(head, 3);
    head = inser_in_testa(head, 8);
    head = inser_in_testa(head, 15);
    head = inser_in_testa(head, 12);
    head = inser_in_testa(head, 6);

    print_lista(head);

    printf("\nMultipli di 3: %d\n", conta_multipli_3(head));
}

void print_lista(struct nodo *head)
{
    struct nodo * current = head;

    while(current != NULL)
    {
        printf("%d ", current->valore);
        current = current->next;
    }
}

int conta_multipli_3(struct nodo *head)
{
    struct nodo *curr = head;
    int cont = 0;

    while(curr != NULL)
    {
        if(curr->valore % 3 == 0)
            cont ++;
        
        curr = curr->next;

    }
    return cont;
}

struct nodo * inser_in_testa(struct nodo *head, int val)
{
    struct nodo * nuovo = NULL;
    nuovo = (struct nodo *)malloc(sizeof(struct nodo *));
    if (nuovo != NULL)
    {   
        nuovo->valore = val;
        nuovo->next = head;
        head = nuovo;
    }
    else
        printf("\nSpazio insufficente!");

    return head;
}
