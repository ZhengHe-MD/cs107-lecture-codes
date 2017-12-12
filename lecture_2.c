#include <stdio.h>
#include "printbinary.h"

int main(int argc, char ** argv) {
    char ch1 = 'A';
    short s1 = ch1;
    printf("cast char 'A' to short \n");
    print_char(ch1);
    print_line(1);
    print_short(s1);
    print_line(2);
    
    short s2 = 67;
    char ch2 = s2;
    printf("cast short 67 to char \n");
    print_short(s2);
    print_line(1);
    print_char(s2);
    print_line(2);

    short s3 = 1033;
    int i3 = s3;
    printf("cast short 1033 to int \n");
    print_short(s3);
    print_line(1);
    print_int(i3);
    print_line(2);

    int i4 = 10502151;
    short s4 = i4;
    printf("cast int 10502151 to short \n");
    print_int(i4);
    print_line(1);
    print_short(s4);
    print_line(2);

    short s5 = -1;
    int i5 = s5;
    printf("cast short -1 to int \n");
    print_short(s5);
    print_line(1);
    print_int(i5);
    print_line(2);
    
    int i6 = -65536;
    short s6 = i6;
    printf("cast int -65536 to short \n");
    print_int(i6);
    print_line(1);
    print_short(s6);
    print_line(2);

    int i7 = 5;
    float f7 = i7;
    printf("cast int 5 to float \n");
    print_int(i7);
    print_line(1);
    print_float(f7);
    print_line(2);

    int i8 = 37;
    float f8 = *(float*)&i8;
    printf("cast int 37 to float \n");
    print_int(i8);
    print_line(1);
    print_float(f8);
    print_line(2);

    float f9 = 7.0;
    short s9 = *((short*)&f9);
    printf("cast float 7.0 to short \n");
    print_float(f9);
    print_line(1);
    print_short(s9);
    print_line(2);
}
