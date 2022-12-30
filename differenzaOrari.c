/*Scrivere un programma C che calcola il tempo trascorso (in ore, minuti e secondi) 
tra due istanti di tempo.
 Definire una struttura time che contiene ora, minuti e secondi.
 Il tempo trascorso tra 3:45:15 e 9:44:03 è 5 ore, 58 minuti e 48 secondi.
Il programma deve comprendere le funzioni:

struct time insertTime()
Richiede all'utente di inserire un istante e restituisce la corrispondente struttura. 
Se l'istante inserito non è valido viene richiesto di nuovo.
Suggerimento: Usare la funzione scanf con stringa di formato "%i:%i:%i" per permettere all'utente di
inserire una data nella forma: 12:03:33

bool checkTime(struct time)
Verifica se l'istante di tempo inserito è valido.
In particolare la funzione verifica che:
 Il numero che rappresenta i secondi sia compreso tra 0 e 59.
 Il numero che rappresenta i minuti sia compreso tra 0 e 59.
 Il numero che rappresenta l'ora sia compreso tra 0 e 23.

struct time elapsedTime(struct time t1, struct time t2)
Calcola il tempo trascorso tra t1 e t2.

int main(void)
Richiama opportunamente le altre funzioni*/

#include<stdio.h>
#include<stdbool.h>

struct time{
    int hour;
    int min;
    int sec;
};

//scrivo i prototipi delle funzioni che userò
struct time insertTime();
bool checkTime(struct time);
struct time elapsedTime(struct time, struct time);

int main(){
    struct time t1 = insertTime(); //inserisco il primo orario
    struct time t2 = insertTime(); //inserisco il secondo orario
    struct time diff = elapsedTime(t1,t2); //trovo il 3o orario (differenza tra secondo e primo)

    //stampo i tre orari
    printf("t1: %d:%d:%d\n",t1.hour,t1.min,t1.sec);
    printf("t2: %d:%d:%d\n",t2.hour,t2.min,t2.sec);
    printf("differenza tra orari: %d:%d:%d\n",diff.hour,diff.min,diff.sec);
}
 //funzione che chiede un orario e lo mette in una struttura struct time, per poi ritornarla
struct time insertTime(){
    struct time a;
    do{
        printf("inserisci un orario (formato hh:mm:ss): ");
        scanf("%d:%d:%d",&a.hour,&a.min,&a.sec);
    } while (checkTime(a) == false);   //chiedi l'orario finche checkTime mi dice che il formato è sbagliato
    return a; //ritorna la struttura struct time
}

//funzione che controlla se l'orario inserito in insertTime è nel formato corretto. torna T o F
bool checkTime(struct time b){
    if (b.sec<60 && b.min<60 && b.hour<24)
            return true;
    else{
        printf("Formato non corretto! Inserisci di nuovo.\n");
        return false;
    }
}

//funzione che calcola la differenza tra due orari, e ritorna una struttura con tale diff in formato
//struct time
struct time elapsedTime(struct time x, struct time y){
    struct time z;
    if(y.sec>=x.sec)
        z.sec = y.sec - x.sec;
    else{
        z.sec = 60 - (x.sec - y.sec);
        y.min = y.min - 1;
    }

    if(y.min>=x.min)
        z.min = y.min - x.min;
    else{
        z.min = 60 - (x.min - y.min);
    }

    if(y.hour >= x.hour)
        z.hour = y.hour - x.hour;
    else
        z.hour = y.hour + (24 - x.hour);
    return z;

}
