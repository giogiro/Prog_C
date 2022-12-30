/*Scrivere un programma C per la registrazione e lo studio delle condizioni meteorologiche in un certo periodo.
Le condizioni meteorologiche di un giorno sono raccolte in una struttura dati meteo composta da: una
struttura per la registrazione di data e ora, un float contenente la temperatura, un float contenente la
pressione atmosferica, un float contenente la percentuale di umidità e un float contenente la quantità di
pioggia caduta.
Assumete che il programma gestisca al massimo 30 registrazioni in una struttura archivio formata da un
array di dati meteo e un intero rappresentante il numero di dati registrati.
Il programma è composto dalle seguenti funzioni:
void stampa_menu(void) stampa a video la lista delle operazioni che possono essere eseguite dall'utente:
registra nuovo dato meteorologico, calcola statistiche, esci dal programma.
char leggi_scelta(void) richiede all'utente quale tra le possibili operazioni vuole eseguire e restituisce un
carattere rappresentante tale scelta.
Attenzione: Ricordatevi di usare la stringa di formato " %c" con uno spazio davanti per eliminare qualsiasi
carattere di spazio/invio precedentemente inserito.
struct archivio registra(struct archivio a, struct dati_meteo d) registra un nuovo insieme di dati 
meteo d nell'archivio a e restituisce l'archivio aggiornato.
Attenzione: Ricordatevi che le modifiche efiettuate dalla funzione sull'archivio non sono visibili all
'esterno, quindi l'archivio aggiornato va restituito come risultato della funzione e assegnato alla 
variabile precedente.
struct statistiche calcola(struct archivio a) ritorna una struttura contenente le statistiche dei dati inseriti. La struttura struct statistiche contiene i valori minimi/massimi/medi di temperatura/pressione/umidità/pioggia .
int main(void) richiama le funzioni stampa_menu() e leggi_scelta(), ed esegue l'operazione richiesta,
finchè la scelta effettuata dall'utente non è quella di uscire.*/

#include<stdio.h>
        struct data{
            int day,month,year;
        };
        struct ora {
            int sec,min,hour;
        };

    struct dataora{
        struct data dt;
        struct ora hr;
        };

struct dati_meteo{
    float temp;
    float press;
    float umid;
    float piog;
    struct dataora dthr;
};

struct archivio{
    struct dati_meteo dati[30];
    int numerodati;
};

 struct statistiche{
    struct temperatura{
        int mint,maxt,medt;
    };
    struct pressione{
        int minpr,maxpr,medpr;
    };
    struct umidita{
        int minu,maxu,medu;
    };
    struct piog{
        int minp,maxp,medp;
    };
 };

//prototipi delle funzioni che uso
void stampa_menu();
char leggi_scelta();
struct archivio registra(struct archivio, struct dati_meteo);
struct statistiche calcola(struct archivio);


int main(){
    char scelta;
    struct archivio arch;
    arch.numerodati=0;  //lo imposto a 0 perchè poi ogni volta che chiamo la funzione lo incremento
    struct dati_meteo dato;
    struct dataora e;
    struct data f;
    
    do{
        stampa_menu();  //mi stampa semplicemente il menu
        scelta = leggi_scelta(); //questa funzione mi restituisce una lettera (a,b,c) e la mette in scelta
        printf("hai scelto: %c\n",scelta);  //stampo la scelta per sicurezza intanto che faccio il prog

        switch (scelta){  //in base a scelta faccio cose:
            case 'a': //inserisco un dato meteo e lo archivio in archivio a

            printf("inserisci data (gg/mm/yyyy); ");
            scanf("%d/%d/%d",&dato.dthr.dt.day, &dato.dthr.dt.month, &dato.dthr.dt.year);
            printf("inserisci orario (hh/mm/ss): ");
            scanf("%d/%d/%d",&dato.dthr.hr.hour, &dato.dthr.hr.sec, &dato.dthr.hr.min);
            printf("inserisci la temperatura: ");
            scanf("%f",&dato.temp);
            printf("inserisci la pressione atmosferica: ");
            scanf("%f",&dato.press);
            printf("inserisci l'umidità: ");
            scanf("%f",&dato.umid);
            printf("inserisci la pioggia(mm): ");
            scanf("%f",&dato.piog);
            arch = registra(arch, dato);
            break;

            case ('b'): 
                //devo ancora farlo(statistiche dei dati gia inseriti)
            break;

            case 'c':
            printf("chiusura programma!\n");
            break;
        }

    }while(scelta=!'c'); //se ho scelto c, esco dal programma;
}

void stampa_menu(){
    printf("Benvenuto nella stazione meteo!\n[a] Registra nuovo dato meteorologico\n[b] Calcola statistiche\n[c] Esci dal programma\n");
}

char leggi_scelta(){
    char scelta;
    printf("Cosa desideri fare? ");
    scanf(" %c",&scelta);
    return scelta;
}

struct archivio registra(struct archivio a, struct dati_meteo dato){
    a.dati[a.numerodati] = dato;
    a.numerodati++;
}
