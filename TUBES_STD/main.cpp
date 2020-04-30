/* AKMAL MUHAMAD F. 1301190436
   MUHAMAD SULTHON A. 1301194008
   IF-43-05
*/
#include <iostream>
#include "listRelasi.h"

using namespace std;

int main() {
	string any;
	int pilih;
	List_Parent List_Parent;
	listChild List_Child;
	listRelasi List_Relasi;
	infotypeParent DataWarteg;
	infotypeChild DataMamin;
	address_parent P;
	addressChild Q;
	relateAddress R;
	createListParent(List_Parent);
	createListChild(List_Child);
	createListRelasi(List_Relasi);

	do {
		cout << "======================================" << endl;
		cout << "===                                ===" << endl;
		cout << "===    MENU ADMINISTRASI WARTEG    ===" << endl;
		cout << "===            v0.1a               ===" << endl;
		cout << "===                                ===" << endl;
		cout << "======================================" << endl;

        cout << "[1] Buka Warteg" << endl;
        cout << "[2] Buat Menu Warteg" << endl;
        cout << "[3] Lihat semua Warteg terdaftar" << endl;
        cout << "[4] Lihat semua menu Warteg terdaftar" << endl;
		cout << "[5] Hapus Warteg" << endl;
		cout << "[6] Hapus menu Warteg" << endl;
		cout << "[7] Keluar" << endl;
		cout << "Pilih menu : ";
		cin >> pilih;
		cout << endl << endl;
		system("Closing..");
		switch (pilih){
		case 1 :
			inputDataWarteg(List_Parent, DataWarteg);
			insertSortedParent(List_Parent, DataWarteg);
			break;
		case 2 :
			inputDataMamin(List_Child, DataMamin);
			insertSortedChild(List_Child, DataMamin);
			break;
		case 3 :
			printInfoParent(List_Parent);
			break;
		case 4 :
			printInfoChild(List_Child);
			break;
		case 5 :
			cout << "Nama Warteg : ";
			cin.get();
			getline(cin, DataWarteg.namaWarteg);
			P = findElmParent(List_Parent, DataWarteg.namaWarteg);
			R = findElmRelasiParent(List_Relasi, DataWarteg.namaWarteg);
			if (P != NULL) {
				if (R != NULL) {
					deleteAllRelasiParent(List_Relasi, P);
				}
				deleteSpesifikParent(List_Parent, P->info.namaWarteg);
				deallocateParent(P);
			}
			else {
				cout << "Warteg belum terdaftar." << endl;
			}
			break;
		case 6 :
			cout << "Makanan/Minuman : " << endl;
			cin.get();
			getline(cin, DataMamin.namaMamin);
			Q = findElmChild(List_Child, DataMamin.namaMamin);
			R = findElmRelasiChild(List_Relasi, DataMamin.namaMamin);
			if (Q != NULL) {
				if (R != NULL) {
					deleteAllRelasiChild(List_Relasi, Q);
				}
				deleteSpecificChild(List_Child, Q->info.namaMamin);
				deallocateChild(Q);
			}
			else {
				cout << "Makanan/Minuman belum terdaftar." << endl;
			}
			break;
		}
		system("pause");
	} while (pilih != 0);
	return 0;
}