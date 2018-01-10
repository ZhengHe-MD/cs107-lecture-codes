typedef struct {
    int *elems;
    int loglength;
    int alloclength;
} Stack;

void StackNew(Stack *s);
void StackDispose(Stack *s);
void StackPush(Stack *s, int value);
int StackPop(Stack *s);
