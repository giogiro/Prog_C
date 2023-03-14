#include <stdio.h>

void foo1(int xval) {
    int x;
    x = xval;
    /* Stampate l'indirizzo e il valore di x */
    printf("x: \n indirizzo: %p \n valore: %d\n", &x, x);
    return x;
}

void foo2(int dummy) {
    int y;
    /* Stampate l'indirizzo e il valore di y */
    printf("y: \n indirizzo: %p \n valore: %d\n", &y, y);
}

int main(void) {

    foo1(7);
    foo2(11);

}