/* algoritmo di ordinamento BUBBLE SORT*/
#include<stdio.h>
int main(){

    int array[100]; //array da ordinare
    int lunghezza,c,d,swap;

    /*inserisco lunghezza array*/
    do{
        scanf("%d", &lunghezza);
    }while(lunghezza<=0);

    /*inserisco array*/
    for(c=0; c<lunghezza; c++){
        scanf("%d", &array[c]);
    }
    
    /*stampo array*/
    for(c=0; c<lunghezza; c++){
        printf("%d ", array[c]);
    }
    printf("\n");

    /*ordinare l'array*/
    for(c=0; c<lunghezza-1; c++){ 
        for(d=0; d<lunghezza-1-c; d++){
            if(array[d] > array[d+1]){ //se il valore è maggiore del valore nella posizione dopo: scambio
                swap = array[d];
                array[d] = array[d+1];
                array[d+1] = swap;
            }
        }
    }

    /*stampare l'array ordinato*/
    for(c=0; c<lunghezza; c++){
        printf("%d ", array[c]);
    }
}