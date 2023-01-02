#include "queue.h"
#include "stack.h"

int main(){
    Stack S1,S2,S3,S4,S5,S6,S7;
	Queue Q;
	infotype info;
	int menu, jenis, i, N;
	adr pObat;
	int a = 5,b = 5,c = 5,d = 5,e = 5,f = 5, g = 5;

	S1 = createStack();
	S2 = createStack();
	S3 = createStack();
	S4 = createStack();
	S5 = createStack();
	S6 = createStack();
	S7 = createStack();

	createQueue(Q);
	while(true){
		cout << "========== Antrean Obat ==========" << endl;
		cout << "|   1. Daftar                    |" << endl;
		cout << "|   2. Antrean                   |" << endl;
		cout << "|   3. Stok Obat tersedia        |" << endl;
		cout << "|   4. Panggil                   |" << endl;
		cout << "|   5. Keluar                    |" << endl;
		cout << "==================================" << endl;
		cout << "Pilihan : "; cin >> menu;

		cout << endl;
		if(menu == 1){
			while(true){
				cout << "Masukkan Jumlah Pasien : ";
				cin >> N;

				cout << endl;
				if(N >= 1){
					break;
				}else{
					cout << "Tidak Tersedia" << endl << endl;
				}
			}

			for(i=1; i<=N; i++){
				cout << "Data Pasien ke-" << i << ":" << endl;
				cin.ignore();
				cout << "Masukkan NIK Paisen    : ";
				getline(cin, info.ID);
				cout << "Masukkan Nama Pasien   : ";
				getline(cin, info.nama);
				cout << "Masukkan Alamat Pasien : ";
				getline(cin, info.alamat);

				cout << endl;

				cout << "========= Jenis Obat ==========" << endl;
				cout << "| 1. Obat Bebas Terbatas      |" << endl;
				cout << "| 2. Obat Bebas               |" << endl;
				cout << "| 3. Obat Keras               |" << endl;
				cout << "| 4. Obat Wajib Surat Dokter  |" << endl;
				cout << "| 5. Obat Golongan Narkotika  |" << endl;
				cout << "| 6. Obat Psikotropika        |" << endl;
				cout << "| 7. Obat Herbal              |" << endl;
				cout << "===============================" << endl;

				while(true){
					cout << "Pilihan [1-7] : "; cin >> jenis;

					cout << endl;
					if(jenis < 1 || jenis > 7){
						cout << "[!] Pilihan Tidak Valid!" << endl << endl;
					}else{
						break;
					}
				}

				if(jenis == 1){
					info.obat = "Obat Bebas Terbatas";
					push(S1,5);
					pop(S1,1);
					a = a-1;
					info.prioritas = 5;
				}else if(jenis == 2){
					info.obat = "Obat Bebas";
					push(S2,5);
					pop(S2,1);
					b= b-1;
					info.prioritas = 4;
				}else if(jenis == 3){
					info.obat = "Obat Keras";
					push(S3,5);
					pop(S3,1);
					c = c - 1;
					info.prioritas = 3;
				}else if(jenis == 4){
					info.obat = "Wajib Surat Dokter";
					push(S4,5);
					pop(S4,1);
					d = d - 1;
					info.prioritas = 2;
				}else if(jenis == 5){
					info.obat = "Obat Golongan Narkotika";
					push(S5,5);
					pop(S5,1);
					e = e - 1;
					info.prioritas = 1;
				}else if(jenis == 6){
					info.obat = "Obat Psikotropika";
					push(S6,5);
					pop(S6,1);
					f = f - 1;
					info.prioritas = 1;
				}else if(jenis == 7){
				    info.obat = "Obat Herbal";
					push(S7,5);
					pop(S7,1);
					g = g - 1;
					info.prioritas = 1;
				}else{
					cout<<"error"<<endl;
				}

				createElement(info, pObat);

				enqueue(Q, pObat);
			}

			cout << "Berhasil Mendaftar! Harap Tunggu" << endl;
		}else if(menu == 2){
			if(!isQueueEmpty(Q)){
				showQueue(Q);
			}else{
				cout << "Tidak Ada Antrean Obat" << endl;
			}
		}else if(menu == 4){
			if(!isQueueEmpty(Q)){
				dequeue(Q, pObat);
				cout << "Antrean Obat Atas Nama " << info(pObat).nama << " dengan Penyakit " << info(pObat).obat << " Harap Menuju Kasir!" << endl;
			}else{
				cout << "Tidak Ada Antrean Obat" << endl;
			}
		}else if(menu == 5){
			cout << "Keluar dari program..." << endl;
			break;
		}else if(menu == 3){
		    cout <<  "Obat Bebas Terbatas     : " << a <<endl;
            cout <<  "Obat Bebas              : " << b <<endl;
            cout <<  "Obat Keras              : " << c <<endl;
            cout <<  "Obat Wajib Resep Dokter : " << d <<endl;
            cout <<  "Obat Golongan Narkotika : " << e <<endl;
            cout <<  "Obat Psikotropika       : " << f <<endl;
            cout <<  "Obat Herbal             : " << g <<endl;
        }else{
			cout << "[!] Menu Tidak Valid!" << endl;
		}

		cout << endl;
		system("pause");
		system("cls");
	}

	return 0;
}

// stack untuk mengurangi dan panggilan pasien jumlah obat
// queue untuk antrian obat
