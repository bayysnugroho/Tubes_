#include <iostream>
#include <conio.h>
#include "stack.h"

using namespace std;

bool isEmpty(Stack S){
    if(S.Top == 0){
        return true;
    }else{
        return false;
    }
}

bool isFull(Stack S){
    if(S.Top==jum){
        return true;
    }else{
        return false;
    }
}

Stack createStack(){
    Stack S;

    S.Top = 0;

    return S;
}

void push(Stack &S, info obat){
    if(isFull(S)){
        cout<<"Stack Penuh";
    }else{
        S.Top = S.Top + 1;
        S.T[S.Top] = obat;
    }
}

void pop(Stack &S, info obat){
    adrress P;

    if(isEmpty(S)){
        cout<<"Stack kosong";
    }else{
        P = S.T[S.Top];
        S.Top = S.Top - 1;
    }
}

void viewStack(Stack S){
    if(isEmpty(S)){
        cout<<"Stack kosong";
    }else{
        for(int i=(S.Top - 1); i >=0; i--){
            cout<<S.T[i];
        }
    }
}
