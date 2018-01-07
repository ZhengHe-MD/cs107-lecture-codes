#include <stdio.h>
#include <string.h>
#include "stack.h"

void *lsearch(void *key, void *base, int size, int elemSize, int (* cmpFn)(void *, void *)) {
    for (int i = 0; i < size; i++) {
        void *elemAddr = (char *)base + i*elemSize;
        if (cmpFn(key, elemAddr) == 0) return elemAddr;
    }
    return NULL;
}


int IntCmp(void *elem1, void *elem2) {
    int *ip1 = elem1;
    int *ip2 = elem2;
    return *ip1 - *ip2;
}


int StrCmp(void *elem1, void *elem2) {
    char *sp1 = *(char **)elem1;
    char *sp2 = *(char **)elem2;
    return strcmp(sp1, sp2);
}

int main(int argc, char **argv) {
    // generic linear search usage

    // compare ints
    int intArray[] = {4, 2, 3, 7, 11, 6};
    int intKey = 7;
    int intArraySize = sizeof(intArray) / sizeof(int);
    int *foundInt = lsearch(&intKey, intArray, intArraySize, sizeof(int), IntCmp);
    printf("found %d\n", *foundInt);

    char *strArray[] = {"Ab", "#F", "B", "Gb", "D"};
    char *strKey = "Gb";
    int strArraySize = sizeof(strArray) / sizeof(char *);
    char **foundStr = lsearch(&strKey, strArray, strArraySize, sizeof(char *), StrCmp);
    printf("found %s\n", *foundStr);

    Stack s; 
    StackNew(&s);
    
    for (int i = 0; i < 5; i++) {
        printf("push: %d \n", i);
        StackPush(&s, i);
    }
    
    for (int j = 0; j < 5; j++) {
        int k = StackPop(&s);
        printf("pop: %d \n", k); 
    }
    StackDispose(&s);
}
