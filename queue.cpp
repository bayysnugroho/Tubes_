#include "queue.h"

void createElement(infotype info, adr &pObat){
	//Membuat element list
	pObat = new element;
	info(pObat) = info;
	next(pObat) = NULL;
}

//Queue
bool isQueueEmpty(Queue Q){
	//Cek apakah Queue kosong atau tidak
	if(Head(Q) == NULL){
		return true;
	}
	return false;
}

void createQueue(Queue &Q){
	//Membuat Queue
	Head(Q) = NULL;
	Tail(Q) = NULL;
	Q.size = 0;
}

void enqueue(Queue &Q, adr pObat){
	//Memasukkan element pointer obat ke Queue berdasarkan prioritasnya
	if(Head(Q) == NULL && Tail(Q) == NULL){
		Head(Q) = Tail(Q) = pObat;
	}else{
		adr temp = Head(Q);
		while(temp != NULL && info(temp).prioritas >= info(pObat).prioritas){
			temp = next(temp);
		}

		if(temp == NULL){
			next(Tail(Q)) = pObat;
			Tail(Q) = pObat;
		}else{
			if(temp == Head(Q)){
				next(pObat) = Head(Q);
				Head(Q) = pObat;
			}/*else{
				//Stack S;
				//createStack(S);
				adr node, tmpObat;

				node = Head(Q);
				while(node != temp){
					node = next(node);
					dequeue(Q, tmpObat);
					//push(S, tmpObat);
				}

				next(pObat) = node;
				Head(Q) = pObat;
				while(!isStackEmpty(S)){
					//pop(S, tmpObat);
					next(tmpObat) = Head(Q);
					Head(Q) = tmpObat;
				}
			}*/
		}
	}
	Q.size += 1;
}
void dequeue(Queue &Q, adr &pObat){
	//Menghapus Head dan memindahkan Head ke node selanjutnya (kalau ada, kalau gak ada nanti head dan tail jadi NULL)
	if(Head(Q) != NULL && Tail(Q) != NULL){
		pObat = Head(Q);
		if(Head(Q) == Tail(Q)){
			Head(Q) = Tail(Q) = NULL;
		}else{
			Head(Q) = next(pObat);
		}
		next(pObat) = NULL;
		Q.size -= 1;
	}
}

void showQueue(Queue Q){
	//Menampilkan Queue
	adr temp = Head(Q);
	int i = 0;

	cout << "Antrean Ambil Obat" << endl;
	while(temp != NULL){
		i += 1;
		cout << i << ". NIK : " <<info(temp).ID<< " - " <<info(temp).nama << " - " << info(temp).obat<< endl;
		temp = next(temp);
	}
}

