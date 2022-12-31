#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include<iostream>
#include<cstdlib>
using namespace std;

#define info(P) (P)->info
#define next(P) (P)->next
#define Head(Q) ((Q).Head)
#define Tail(Q) ((Q).Tail)
#define Top(S) ((S).Top)

struct infotype{
	string nama;
	string ID;
	string alamat;
	string obat;
	int Jumlah;
	int prioritas;
};

typedef struct element *adr;

struct element{
	infotype info;
	adr next;
};

struct Queue{
	adr Head, Tail;
	int size;
};

void createElement(infotype info, adr &pObat);

//Queue
bool isQueueEmpty(Queue Q);
void createQueue(Queue &Q);
void enqueue(Queue &Q, adr pObat);
void dequeue(Queue &Q, adr &pObat);
void showQueue(Queue Q);


#endif // QUEUE_H_INCLUDED
