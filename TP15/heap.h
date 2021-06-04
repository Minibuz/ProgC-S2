typedef struct _stack_ {
    int value;
    struct _stack_* next;
} Stack;

typedef struct _head_ {
    Stack* firstElement;
    int size;
} Head;

Head* createHead();
Stack* createStack(int value);
void freeStack(Head* h);
int stackSize(Head* h);

void push(Head* currentHead,int value);
int pop(Head* currentHead);
void reverse(Head* currentHead);

void printHead(Head* h);
void printWholeStack(Head* h);