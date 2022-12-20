#include<stdio.h>
#include<stdbool.h>
											/*
											struct date {
												int da;
												int mo;
												int yr;
											};



											struct date insertdate(){
												struct date a;
												printf("inserisci una data (formato --/--/----: ");
												scanf("%d/%d/%d",&a.da, &a.mo, &a.yr);
												return a;
											}
											*/
typedef struct {
	int day;
	int month;
	int year;
} date;

int d(date a){
	if (a.day > 1 && a.month > 3 && a.year > 1900)
		return 0;
	else if(a.day == 1 && a.month == 3 && a.year == 1800 1/3/1800 e 28/2/1900)
}

int k(date a){
}

int g(date a){
}

int f(date a){
}

int n(date a){
}


int elapsedays(date a, date b){
	if (a.month != b.month)
}

date insertdate(){
	date a;
	printf("inserisci una data (formato --/--/----: ");
	scanf("%d/%d/%d",&a.day, &a.month, &a.year);
	return a;
}

bool bisestile(date e){
	bool si;
	si = e.year % 4 == 0 && (e.year % 100 != 0 || e.year % 400 == 0);
	return si;
}

int checkmonth(date d){
	int giorni[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	if (bisestile(d)){
		giorni[2]=29;
	}
	return giorni[d.month];
}

bool checkdate(date c){
	if(c.year<1000 || c.month>12 || c.day>checkmonth(c)){
		printf("data sbaglaita!\n");
		return false;
	}
}

date insertdate(){
	date a;
	printf("inserisci una data (formato --/--/----: ");
	scanf("%d/%d/%d",&a.day, &a.month, &a.year);
	return a;
}

int main() {
	date data1 = insertdate();
	date data2 = insertdate();

	int differenza = elapsedays();


	
	


}
