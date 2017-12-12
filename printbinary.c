#include <stdio.h>

void print_line(int numberOfLines) {
    for (int i = 0; i < numberOfLines; i++) {
        printf("\n");
    }
}

void print_char(char ch) {
    int i;
    for (i = 0; i < 8; i++) {
        printf("%d", !!((ch << i) & 0x80));
    }
}

void print_short(short s) {
    char a = *(char *)&s;
    char b = *((char *)&s + 1);
    // little endian
    print_char(b);
    print_char(a);
}

void print_int(int i) {
    short a = *(short *)&i;
    short b = *((short *)&i + 1);    
    
    print_short(b);
    print_short(a);
}

void print_long(long l) {
    int i = *(int *)&l;
    print_int(i);
}

void print_float(float f) {
    int i = *(int *)&f;
    print_int(i);
}

void print_double(double d) {
    int a = *(int *)&d;
    int b = *((int *)&d + 1);

    print_int(b);
    print_int(a);
}

