#include<stdio.h>
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