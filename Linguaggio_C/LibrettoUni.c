/*Scrivere un programma C che gestisce un libretto universitario.*/
#include<stdio.h>
#include<stdbool.h>
#define MAX 30

/*Una data è una struttura formata da 3 interi: giorno, mese, e anno.*/
struct date{
    int day,month,year;
};

/*Un esame è una struttura formata da: una data di registrazione, un codice di tre caratteri rappresentante
il nome del corso, un codice di due caratteri rappresentante le iniziali del docente, un intero rappresentante
il voto, un booleano per la lode*/
struct esame{
    struct date d;
    char nomeCorso[4];
    char nomeDocente[3]; //due caratteri, iniziali del docente
    int voto;
    bool lode;
};

/*Un libretto universitario è una struttura formata da: un array di 20 esami ed un intero rappresentante il
numero di esami registrati.*/
struct libretto{
    struct esame esami[MAX];
    int numeroEsami;
};

/*PROTOTIPI FUNZIONI*/

void stampa_menu();
/*stampa a video la lista delle operazioni che possono essere eseguite dall'utente:
registra esame, stampa esami, calcola media, conta lodi, esci dal programma.*/

char leggi_scelta();
/*richiede all'utente quale tra le possibili operazioni vuole eseguire e restituisce un
carattere rappresentante tale scelta.
Attenzione: Ricordatevi di usare la stringa di formato " %c" con uno spazio davanti per eliminare qualsiasi
carattere di spazio/invio precedentemente inserito*/

void stampa_esami(struct libretto); /*stampa gli esami contenuti nel libretto l.*/

int media(struct libretto); /*calcola la media dei voti registrati nel libretto l.*/

int num_lodi(struct libretto); /*restituisce il numero di lodi registrate nel libretto l.*/

struct libretto registra_esame(struct libretto, struct esame);
/*registra l'esame e nel libretto l e restituisce il libretto aggiornato.
Attenzione: Ricordatevi che le modifiche effettuate dalla funzione sul libretto non sono visibili all'
esterno, quindi il libretto aggiornato va restituito come risultato della funzione e assegnato alla 
variabile precedente*/

int main(){
/*richiama le funzioni stampa_menu() e leggi_scelta(), ed esegue l'operazione richiesta, finchè la scelta
effettuata dall'utente non è quella di uscire.*/
    int scelta;
    struct libretto libretto1; //dichiaro il libretto
    libretto1.numeroEsami=0;  //dichiaro qua all'inizio che il numero di esami è 0
    struct esame es;          //dichiaro l'esame
    printf("Libretto Universitario di Giovanni Girelli!\n");
    do{             //ripeto la scelta dell'operazione finche scelta == 'e';
        stampa_menu();  //stampo il menu
        scelta = leggi_scelta();  //faccio scegliere la lettera per l'operazione
        printf("%c",scelta);

        switch (scelta){
            case 'a':
            printf("inserisci la data dell'esame: ");
            scanf("%d/%d/%d", &es.d.day, &es.d.month, &es.d.year);
            printf("inserisci il nome del corso (3 lettere): ");
            scanf(" %s", &es.nomeCorso);
            printf("inserisci le iniziali del docente (2 lettere): ");
            scanf(" %s", &es.nomeDocente);
            printf("inserisci il voto: ");
            scanf("%d", &es.voto);
            printf("lode? (0:no, 1:si): ");
            scanf("%d", &es.lode);
            libretto1 = registra_esame(libretto1, es); //inserisco l'es che ho appena inserito in libretto1
            break;

            case 'b':
            stampa_esami(libretto1); //stampa gli esami contenuti in lib
            break;

            case 'c':
            printf("media: %d\n", media(libretto1)); //stampo l'int che mi torna la funzione media_esami
            break;

            case 'd':
            printf("numero lodi: %d\n", num_lodi(libretto1));
            break;

            case 'e':
            printf("chiusura del programma!\n");
        }

    }while(scelta=='a' || scelta=='b' || scelta=='c' || scelta=='d');

}

void stampa_menu(){
    printf("[a] registra esame\n[b] stampa esami\n[c]calcola media\n");
    printf("[d]conta lodi\n[e]esci dal programma\n");
}

char leggi_scelta(){
    char c;
    do{
        printf("---cosa vuoi fare?\n");
        scanf(" %c",&c);
    }while(c!='a' && c!='b' && c!='c' && c!='d' && c!='e'); //se la scelta è diversa da abcde riinserisci
    return c;
}

struct libretto registra_esame(struct libretto l, struct esame es){
    l.esami[l.numeroEsami] = es;  //modifico il libretto passato come arg. mettendolo in esami[]
    l.numeroEsami =+ 1;     //incremento numeroEsami che uso come indice in esami[]
    return l;
}

void stampa_esami(struct libretto l){
    int i;
    printf("numero esami: %d\n",l.numeroEsami);
    printf("dei corsi: ");
    for(i=0; i<l.numeroEsami; i++){
        printf("%s ",l.esami[i].nomeCorso);
    }
    printf("\n");
}

int media(struct libretto l){
    int i, media=0,somma=0;
    for(i=0; i<l.numeroEsami; i++){
        somma = somma + l.esami[i].voto;
    }
    media = somma / l.numeroEsami;
    return media;
}

int num_lodi(struct libretto l){
    int i,lodi=0;
    for(i=0; i<l.numeroEsami; i++){
        if(l.esami[i].lode)
            lodi =+ lodi;
    }
    return lodi;
}