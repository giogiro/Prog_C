#include<stdio.h>
int main(){
    int i = 5;
    float f = 8.1340;
    char c ='a';

    int *p_int;
    float *p_float;
    char *p_char;

    p_int = &i;
    p_float = &f;
    p_char = &c;

    printf("int a: \nindirizzo: %p \nvalore: %d \nspazio: %lu \n\n", &i, i, sizeof(i));
    printf("float f: \nindirizzo: %p \nvalore: %g \nspazio: %ld \n\n", &f, f, sizeof(i));
    printf("char c: \nindirizzo: %p \nvalore: %c \nspazio: %ld \n\n", &c, c, sizeof(i));

    printf("puntatore ad a: \nindirizzo: %p \nvalore: %p \nspazio: %lu \n\n", &p_int, p_int, sizeof(p_int));
    printf("puntatore ad f: \nindirizzo: %p \nvalore: %p \nspazio: %ld \n\n", &p_float, p_float, sizeof(p_float));
    printf("puntatore a c: \nindirizzo: %p \nvalore: %p \nspazio: %ld \n\n", &p_char, p_char, sizeof(p_char));
}