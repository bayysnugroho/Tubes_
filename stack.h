#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

const int jum = 5;

typedef int info;
typedef int adrress;

struct Stack{
    info T[jum];
    adrress Top;
};

bool isFull(Stack S);
bool isStackEmpty(Stack S);
Stack createStack();
void push(Stack &S, info obat);
void pop(Stack &S, info obat);
void view(Stack S);

#endif // STACK_H_INCLUDED
