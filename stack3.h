#include <stdbool.h>

typedef struct {
  void *elems;
  int elemSize;
  int loglength;
  int alloclength;
  void (*freefn)(void *);
} stack;

void StackNew(stack *s, int elemSize, void(*freefn)(void *));
void StackDispose(stack *s);
bool StackEmpty(stack *s);
void StackPush(stack *s, void *elemAddr);
void StackPop(stack *s, void *elemAddr);