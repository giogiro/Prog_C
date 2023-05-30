#include<stdio.h>
#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte) \
(byte & 0x80 ? '1' : '0'), \
(byte & 0x40 ? '1' : '0'), \
(byte & 0x20 ? '1' : '0'), \
(byte & 0x10 ? '1' : '0'), \
(byte & 0x08 ? '1' : '0'), \
(byte & 0x04 ? '1' : '0'), \
(byte & 0x02 ? '1' : '0'), \
(byte & 0x01 ? '1' : '0')

void show_mem_rep_bin(char *start, int n);


int main() {
int i = 0x01234567;
show_mem_rep_bin((char *)&i, sizeof(i));
return 0;
}

void show_mem_rep_bin(char *start, int n) {
for (int i = 0; i < n; i++) {
printf(" "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(start[i]));
}
printf("\n");
}