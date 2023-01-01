/*Si consideri la regione R del piano cartesiano individuata dalle ascisse comprese tra 0 e 9 e dalle ordinate
comprese tra 0 e 9.
Scrivere un programma C che chiede all'utente le coordinate di due punti a e b appartenenti a R e disegna
il perimetro del rettangolo con i lati paralleli agli assi cartesiani che ha il segmento ab come diagonale. Le
coordinate di a e b devono essere intere.*/
#include<stdio.h>
#define MAX 9

/*un semplice punto sul piano cartesiano*/
struct punto{
    int x,y;
};

struct ascissa{
    int max,min;
};
struct ordinata{
    int max,min;
};
/*questa struttura conterrà le ascisse max e min, e le ordinate max e min*/
struct rettangolo{
    struct ascissa a;
    struct ordinata o;
};

//prototipi delle funzioni

struct punto inserisci_punto( );
/*Richiede all'utente ascissa e ordinata (entrambe di tipo int) e restituisce la corrispondente struttura. 
Se una delle coordinate inserite non è compresa tra 0 e 9, essa viene richiesta di nuovo*/

struct rettangolo crea_rettangolo(struct punto, struct punto);
/*Riceve due punti, a e b, del piano cartesiano e restituisce il corrispondente rettangolo con i lati
paralleli agli assi che ha il segmento ab come diagonale.*/

void stampa_perimetro (struct rettangolo);
/*Stampa la regione R in cui è opportunamente raffigurato il perimetro di rettangolo.*/

int main(void);
/*Richiama le altre funzioni,  in modo che il programma produca i seguenti output:
$ ./a.out
Punto a.
Inserire l'ascissa (valore compreso tra 0 e 9): 3
Inserire l'ordinata (valore compreso tra 0 e 9): 6
Punto b.
Inserire l'ascissa (valore compreso tra 0 e 9): 5
Inserire l'ordinata (valore compreso tra 0 e 9): 2
9
8
7
6 * * *
5 * *
4 * *
3 * *
2 * * *
1
0
0 1 2 3 4 5 6 7 8 9
*/

int main(){
    struct punto pt_a,pt_b; //i miei due punti
    struct rettangolo rett; //il rettangolo
    printf("Punto a.\n");
    pt_a= inserisci_punto(); //inserisci x e y del punto a
    printf("Punto b.\n");
    pt_b = inserisci_punto(); //inserisci x e y del punto b
    rett = crea_rettangolo(pt_a, pt_b); //crea il rettangolo coi punti a e b
    /*dei test per controllare i passaggi da funzioni a main*/
    
    printf("punto a(x: %d, y: %d)\n",pt_a.x,pt_a.y);  //test stampa punto a
    printf("punto b(x: %d, y: %d)\n",pt_b.x,pt_b.y);  //test stampa punto b
    printf("ascisse max e min: %d, %d\n",rett.a.max,rett.a.min); //test stampa ascisse max e min
    printf("ordinate max e min: %d, %d\n",rett.o.max,rett.o.min); //test stampa ordinate max e min
    stampa_perimetro(rett); //stampa disegno
    
}

struct punto inserisci_punto(){
    struct punto point; //la struttura che passerò quando chiamo la funzione

    printf("Inserire l'ascissa (valore compreso tra 0 e 9): ");
    do{
        scanf("%d",&point.x);
    }while( point.x<0 || point.x>9 );
    
    printf("Inserire l'ordinata (valore compreso tra 0 e 9): ");
    do{
        scanf("%d",&point.y);
    }while( point.y<0 || point.y>9 );

    return point;
}

struct rettangolo crea_rettangolo(struct punto a, struct punto b){
    struct rettangolo r; //la struttura che passerò quando chiamo la funzione
    if(a.x > b.x){    //trovo l'ascissa maggiore e la metto in max, la minore in min
        r.a.max = a.x;  
        r.a.min = b.x;
    }
    else{
        r.a.max = b.x;
        r.a.min = a.x;
    }
    if(a.y > b.y){   //trovo l'ordinata maggiore e la metto in max, la minore in min
        r.o.max = a.y;
        r.o.min = b.y;
    }
    else{
        r.o.max = b.y;
        r.o.min = a.y;
    }
    return r;
}

void stampa_perimetro (struct rettangolo a){
    int i=0,j=0; //i=ordinata, j=ascissa
    for(i=MAX; i>=0; i--){  //con l'ordinata(i) parto da 9 e torno indietro
        printf("%d ",i); //mi stampo inanzitutto la mia i a inizio riga (con spazio)

        for(j=0;j<=MAX;j++){

            /*questo caso farà le basi superiore e inferiore (stampo * ogni incremento di ascissa j)*/
            if(i==a.o.min || i==a.o.max){  //se l'ordinata (i) è uguale all'ordinata max o min
                if(j>=a.a.min && j<=a.a.max) // e se l'ascissa (j) è compresa tra ascissa max e min
                    printf("* ");  //stampa *(con spazio)
                else
                    printf("  ");  //se no stampa spazio(con altro spazio)
            }
            /*questo caso farà le altezze, nel pezzo del rettangolo compreso tra base min e magg*/
            else if(i>a.o.min && i<a.o.max){ //se l'ordinata (i) è compresa tra l'ordinata max e min
                if(j==a.a.min || j==a.a.max)  //e se l'ascissa (j) è uguale a ordinata max o min
                    printf("* ");  //stampa *(con spazio)
                else
                    printf("  ");  //se no stampa spazio(con altro spazio)

            /*nel caso in cui l'ordinataj non sia ne compresa ne uguale alle ordinate min e max 
              non stampo nulla*/
            }

        }
    
        printf("\n");   //vai a capo ogni volta che finisce una linea 
    }
    printf("  "); //stampa la riga finale, arrampicato sugli specchi
    for(i=0; i<=MAX; i++){
        printf("%d ",i);
    }
}