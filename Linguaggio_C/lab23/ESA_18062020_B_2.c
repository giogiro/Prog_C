#include <stdio.h>
#include <string.h>
#define FNAME "testoB.txt"
#define MAXS 15
#define SOGLIA 3

// prototipi
int conta(char *, int *);
void trova(FILE *);

int main() {
    FILE *fp;

    fp = fopen(FNAME, "r");
    if (fp) {
        trova(fp);

        fclose(fp);
    } else
        printf("Errore di apertura del file\n");
    return 0;
}

// cerca nel file fp le parole con almeno 3 vocali di cui almeno una 'a' e le stampa
void trova(FILE *fp) {
    char p[MAXS + 1];
    // definire altre variabili necessarie/utili
    int i, vocali, almeno_a;
    int *quante_a;

    fscanf(fp, "%s", p);
    while (!feof(fp)) {
        vocali = 0;
        
        // sviluppare il codice della funzione
        for(i=0; p[i]!='\0'; i++)
        {
            if(strchr("aeiou", p[i]))
                vocali++;
            
            conta(p, a)

        }
        if(vocali > 2 && almeno_a)
            printf("%s\n", p);
            
    }
}

// conta - RICORSIVA - quante vocali ci sono in s e inserisce nella variabile num quante di queste sono 'a'
int conta(char *s, int *numa) {}
