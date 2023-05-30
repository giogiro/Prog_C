/**
 * Programma per la gestione di una lista concatenata di numeri interi, es. 3 -> 6 -> 10 -> 2 -> 8.
 * In particolare:
 * la funzione left_rotate() modifica la lista, effettuando una rotazione a sinistra (LEFT) per cui il primo valore viene posto in fondo alla lista. La lista dell'esempio diventa: 6 -> 10 -> 2 -> 8
 * -> 3. la funzione right_rotate() modifica la lista, effettuando una rotazione a destra (RIGHT) per cui l'ultimo valore della lista viene messo davanti a tutti gli altri. La lista dell'esempio
 * diventa: 8 -> 3 -> 6 -> 10 -> 2. Se la lista è vuota o contiene un solo elemento, i sottoprogrammi preceenti non modificano la lista ricevuta in ingresso.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct node_ {
    int value;
    struct node_ *next;
} node_t;

node_t *new_node(int n);
node_t *append(node_t *head, int value);
void println(node_t *head);
node_t *left_rotate(node_t *head);
node_t *right_rotate(node_t *head);

/*
 * Program entry point
 * Output:
 * 3
 * 3 -> 6 -> 10 -> 2 -> 8
 * 6 -> 10 -> 2 -> 8 -> 3
 * 3 -> 6 -> 10 -> 2 -> 8
 * 8 -> 3 -> 6 -> 10 -> 2
 */
int main() {
    node_t *head = NULL;

    head = append(head, 3);
    head = left_rotate(head);
    println(head);

    head = append(head, 6);
    head = append(head, 10);
    head = append(head, 2);
    head = append(head, 8);

    println(head);
    head = left_rotate(head);
    println(head);

    head = right_rotate(head);
    println(head);
    head = right_rotate(head);
    println(head);

    return 0;
}

/**
 * Creates a new node with the given value.
 */
node_t *new_node(int value) {
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->value = value;
    node->next = NULL;
    return node;
}

/**
 * Appends an element with the given value at the end of the list.
 */
node_t *append(node_t *head, int value) {
    node_t *new = new_node(value);

    if (head == NULL) {
        head = new;
    } else {
        node_t *current, *prev;
        current = prev = head;

        while (current) {
            prev = current;
            current = current->next;
        }
        prev->next = new;
    }

    return head;
}
/**
 * Prints a representation of the list.
 */
void println(node_t *head)
{
    
        while(head != NULL)
        {
            printf("%d ", head->value);
            head = head->next;
        }
        printf("\n");
}

/**
 * Rotates the list, putting the last item at the beginning of the list (RIGHT).
 */
node_t *right_rotate(node_t *head)
{
    node_t *ultimo, *penultimo;
    ultimo = head;
    penultimo = head;
    if(head->next != NULL)
    {
        while(ultimo->next != NULL)
        {
            ultimo = ultimo->next;
        }

        while(penultimo->next != ultimo)
        {
            penultimo = penultimo->next;
        }

        penultimo->next = NULL;
        ultimo->next = head;

        return ultimo;
    }
    else
        return head;
}

/**
 * Rotates the list, putting the first item at the end of the list (LEFT).
 */
node_t *left_rotate(node_t *head)
{
    node_t *last, *new_head;
    last = head;
    if(head->next != NULL)
    {
        while(last->next != NULL)
        {
            last = last->next;
        }
        last->next = head;
        new_head = head->next;
        head->next = NULL;

        return new_head;
    }

    else
        return head;
}
