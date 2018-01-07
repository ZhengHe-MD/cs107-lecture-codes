#include <stdlib.h>
#include <assert.h>
#include "stack.h"

void StackNew(Stack *s) {
    s->loglength = 0;
    s->alloclength = 4;
    s->elems = malloc(4 * sizeof(int));
    assert(s->elems != NULL);
}

void StackDispose(Stack *s) {
    free(s->elems);
}

void StackPush(Stack *s, int value) {
    if (s->loglength == s->alloclength) {
        s->alloclength *= 2;
        s->elems = realloc(s->elems, s->alloclength * sizeof(int));
        assert(s->elems != NULL);
    }

    s->elems[s->loglength] = value;
    s->loglength++;
}

int StackPop(Stack *s) {
    assert(s->loglength > 0);
    int top = s->elems[s->loglength - 1];
    s->loglength--;
    return top;
}
