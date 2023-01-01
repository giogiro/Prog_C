/*Scrivere un programma C che richiede all'utente di inserire due date e calcola il numero 
di giorni trascorsi tra di esse.*/
#include<stdio.h>
#include<stdbool.h>

//definisco la "classe", la structure di riferimento (con typedef,così per creare istanze è piu semplice)
struct date {
    int day;
	int month;
	int year;
};

struct date insertDate(); //chiedo a utente giorno mese e anno, restutuisco la struttura date
bool checkDate(struct date);
int giornoMax(struct date); //passo la struttura e mi restituisce il numero di giorni di quel mese
bool bisestile(struct date);
int n(struct date); //
int f(int, int);
int g(int);
int k(struct date); //se data è 
int elapsedDays(struct date, struct date); //sommo i numeri che mi restituisce n()

int main(){
    struct date data1 = insertDate();
    struct date data2 = insertDate();
    printf("data1: %d-%d-%d\n",data1.day,data1.month,data1.year);
    printf("data2: %d-%d-%d\n",data2.day,data2.month,data2.year);
    printf("giorni di differenza tra le date: %d",elapsedDays(data1,data2));
}

struct date insertDate(){
    struct date a; // a è la struttura che verrà passata nel main, che io metterò in data1 e data2
    do{
        printf("inserisci una data nel seguente formato --/--/---- : ");
        scanf("%d/%d/%d",&a.day,&a.month,&a.year);
    } while (checkDate(a) == false);
    return a;
}
int giornoMax(struct date a){
    int giorni[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if (bisestile(a) == true)
        giorni[2] = 29;
    return giorni[a.month];
}

bool bisestile(struct date a){
    if(a.year % 4 == 0 && (a.year % 100 != 0 || a.year % 400 == 0)){
        return true;
    }
}

bool checkDate(struct date a){
    if(a.year<1000 || a.year<=0 || a.month>12 || a.month<=0 || a.day>giornoMax(a) || (a.month<3 || a.year<1700)){
        printf("la data che hai inserito non è corretta!\n");
        return false;
    }
    else
        return true;
}
int k(struct date a){
    /*0 se d è seguente al 1/3/1900
    1 se d è compresa tra 1/3/1800 e 28/2/1900
    2 se d è compresa tra 1/3/1700 e 28/2/1800*/
    if(a.day>=1 && a.month>=3 && a.year>=1900) //se è maggiore del ....1900 ritorna 0
        return 0;
    else if(a.day>=1 && a.month>=3 && a.year>=1800) //se non è magg del ..1900 ma magg di ..1800 ritorna 1
        return 1;
    else //se è min di 1800 e magg di 1700(ovvio per checkdate) ritorna 2
        return 2;
}

int g(int a){
    /*g(d.month) = (    d.month + 13 se d.month ≤ 2
                   (    d.month + 1  altrimenti   */
    if (a<=2)
        return a+13;
    else
        return a+1;
}

int f(int a, int b){
    /*f(d.year, d.month) = (    d.year − 1 se d.month ≤ 2
                           (    d.year     altrimenti            */
    if (b<=2)
        return a-1;
    else
        return a;
}

int n(struct date a){
    return ((1461 * f(a.year, a.month)) / 4) + ((153 * g(a.month)) / 5) + a.day + k(a);
}

int elapsedDays(struct date a, struct date b){
    return n(a) - n(b);
}