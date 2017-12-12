#include <stdio.h>
#include <string.h>
#include "printbinary.h"

struct fraction {
    int num;
    int denum;
};

struct student {
    char *name;
    char suid[8];
    int numUnits;
};

int main(int argc, char ** argv) {
    double d1 = 3.1416;
    char ch1 = *(char *)&d1;
    printf("interpret double pointer to 3.1416 as char pointer\n");
    print_double(d1);
    print_line(1);
    print_char(ch1);
    print_line(2);

    short s2 = 45;
    double d2 = *(double *)&s2;
    printf("interpret short pointer to 45 as double pointer\n");
    print_short(s2);
    print_line(1);
    print_double(d2);
    print_line(2);

    struct fraction pi;
    pi.num = 22;
    pi.denum = 7;
    
    struct fraction pi2 = *((struct fraction *)&(pi.denum));
    pi2.denum = 23;
    printf("num: %d, denum: %d \n", pi2.num, pi2.denum); 
    print_line(2);

    int arr[5];
    arr[3] = 128;
    printf("interpret int pointer to 128 as short pointer to 2");
    print_int(arr[3]);
    ((short *)arr)[6] = 2;
    print_line(1);
    print_int(arr[3]);
    print_line(2);

    struct student pupils[4];
    pupils[0].numUnits = 21;
    pupils[2].name = strdup("Adam");
    pupils[3].name = pupils[0].suid + 6;
    strcpy(pupils[1].suid, "40415xx");
    strcpy(pupils[3].name, "123456");
    printf("%d \n", pupils[0].numUnits);
}
