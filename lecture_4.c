#include <string.h>
#include <stdio.h>
#include "printbinary.h"

void swap_int(int *ap, int *bp) {
  int temp = *ap;
  *ap = *bp;
  *bp = temp;
}

void swap(void *vp1, void *vp2, int size) {
  char buffer[size];
  memcpy(buffer, vp1, size);
  memcpy(vp1, vp2, size);
  memcpy(vp2, buffer, size);
}

int lsearch_int(int key, int array[], int size) {
  for (int i = 0; i < size; i++) {
    return i;
  }
  return -1;
}

void *lsearch(void *key, void *base, int n, int elemSize) {
  for (int i = 0; i < n; i++) {
    void *elemAddr = (char *)base + i * elemSize;
    if (memcmp(key, elemAddr, elemSize) == 0) {
      return elemAddr;
    }
  }
  return NULL;
}

int main(int argc, char** argv) {
  int a1 = 1;
  int b1 = 2;
  printf("a = %d, b = %d \n", a1, b1);
  swap_int(&a1, &b1);
  printf("use swap_int \n");
  printf("a = %d, b = %d \n", a1, b1);

  int a2 = 1;
  int b2 = 2;

  printf("use generic swap \n");
  swap(&a2, &b2, sizeof(int));
  printf("a = %d, b = %d \n", a2, b2);

  print_line(1);

  double a3 = 0.5;
  double b3 = 0.9;
  printf("d1 = %f, d2 = %f \n", a3, b3);
  swap(&a3, &b3, sizeof(double));
  printf("d1 = %f, d2 = %f \n", a3, b3);

  double a4 = 3.142;
  double b4 = 2.718;
  printf("d1 = %f, d2 = %f \n", a4, b4);
  printf("d1: \n");
  print_double(a4);
  print_line(1);
  printf("d2: \n");
  print_double(b4);
  print_line(1);

  swap(&a4, &b4, sizeof(double));
  printf("d1 = %f, d2 = %f \n", a4, b4);

  print_line(2);

  double a5 = 3.142;
  double b5 = 2.718;

  printf("d1: \n");
  print_double(a5);
  print_line(1);
  printf("d2: \n");
  print_double(b5);
  print_line(1);
  printf("swap d1 d2 as if they are int \n");
  swap(&a5, &b5, sizeof(int));
  printf("d1: \n");
  print_double(a5);
  print_line(1);
  printf("d2: \n");
  print_double(b5);
  print_line(2);


  int a6 = 44;
  short b6 = 5;

  printf("a: \n");
  print_int(a6);
  print_line(1);
  printf("b: \n");
  print_short(b6);
  print_line(1);
  printf("swap int a and short b as if they are short \n");
  swap(&a6, &b6, sizeof(short));
  printf("a: \n");
  print_int(a6);
  print_line(1);
  printf("b: \n");
  print_short(b6);
  print_line(1);

  char *husband = strdup("Fred");
  char *wife = strdup("Wilma");

  printf("husband: %s\n", husband);
  printf("wife: %s\n", wife);
  printf("swap pointers to husband and wife \n");
  swap(&husband, &wife, sizeof(char *));
  printf("husband: %s\n", husband);
  printf("wife: %s\n", wife);

  print_line(2);

  int array[5] = {1, 2, 3, 4, 5};
  int key = 3;
  int index = lsearch_int(key, array, 5);
  printf("search index of 3 in array [1, 2, 3, 4, 5] by lsearch_int\n");
  printf("result index: %d \n", index);

  print_line(2);
  int *found = lsearch(&key, array, 5, sizeof(int));
  printf("get pointer of 3 in array [1, 2, 3, 4, 5] by lsearch\n");
  printf("found: %d\n", *found);
}