/* AKMAL MUHAMAD F. 1301190436
   MUHAMAD SULTHON A. 1301194008
   IF-43-05
*/

#include "listChild.h"

void createListChild(listChild& L) {
	L.first = NULL;
}

addressChild createElmChild(infotypeChild A) {
	addressChild P = new child;
	P->info = A;
	P->next = NULL;
	return P;
}

void insertFirstChild(listChild& L, addressChild P) {
	if (L.first == NULL) {
		L.first = P;
		L.first = P;
	}
	else {
		P->next = L.first;
		L.first = P;
	}
}

void insertAfterChild(listChild& L, addressChild Prec, addressChild P) {
	P->next = Prec->next;
	Prec->next = P;
}

void insertLastChild(listChild& L, addressChild P) {
	if (L.first == NULL) {
		insertLastChild(L, P);
	}
	else {
		L.last->next = P;
		L.last = P;
	}
}

void insertSortedChild(listChild& L, infotypeChild A) {
	if ( L.first != NULL ) {
		if ( findElmChild(L, A.namaMamin) == NULL) {
			if (A.namaMamin > L.first->info.namaMamin) {
				insertFirstChild(L, createElmChild(A));
			}
			else if (A.namaMamin < L.last->info.namaMamin) {
				insertLastChild(L, createElmChild(A));
			}
			else {
				addressChild P = L.first;
				while (P != NULL && A.namaMamin > P->info.namaMamin) {
					P = P->next;
				}
				insertAfterChild(L, P, createElmChild(A));
			}
		}
		else {
			cout << "Makanan/minuman sudag terdaftar" << endl;
		}
	}
	else {
		insertFirstChild(L, createElmChild(A));
	}
}

void deleteFirstChild(listChild& L, addressChild& P) {
	if (L.first != L.last) {
		P = L.first;
		L.first = P->next;
		P->next = NULL;
	}
	else {
		P = L.first;
		L.first = NULL;
		L.last = NULL;
	}
}

void deleteAfterChild(listChild& L, addressChild Prec, addressChild& P) {
	P->next = Prec->next;
	Prec->next = P->next;
}

void deleteLastChild(listChild& L, addressChild& P) {
	addressChild Q = L.first;
	while (Q->next->next != NULL) {
		Q = Q->next;
	}
	P = Q->next;
	Q->next = NULL;
}

void deleteSpecificChild(listChild& L, string A) {
	addressChild P = findElmChild(L, A);
	if (L.first != NULL && P != NULL) {
		if (L.first->info.namaMamin == A) {
			deleteFirstChild(L, P);
		}
		else if (L.last->info.namaMamin == A) {
			deleteLastChild(L, P);
		}
		else {
			P = L.first;
			addressChild Q = 0;
			while (P->info.namaMamin != A) {
				Q = P;
				P = P->next;
			}
			deleteAfterChild(L, Q, P);
		}
		cout << "Penghapusan Makanan/Minuman " << A << " telah berhasil." << endl;
	}
	else {
		cout << "Makanan/minuman sudah tidak ada. " << endl;
	}
	cout << endl;
}

addressChild findElmChild(listChild& L, string A) {
	addressChild P = L.first;
	while (P != NULL && P->info.namaMamin != A && P->info.IDMamin != A) {
		P = P->next;
	}
	return P;
}

void printInfoChild(listChild L) {
	addressChild P = L.first;
	while (P != NULL) {
		cout << "Makanan/minuman: " << P->info.namaMamin << endl;
		cout << "Harga: " << P->info.hargaMamin << endl;
		cout << "ID: " << P->info.IDMamin << endl;
		P = P->next;
		cout << endl;
	}
	cout << endl;
}

void inputDataMamin(listChild L, infotypeChild& A) {
	cout << "Tambah menu makan/minum: ";
	cin.get();
	getline(cin, A.namaMamin);
	while (findElmChild(L, A.namaMamin) != NULL) {
		cout << "Makanan/minuman sudah ada. Input kembali." << endl;
		cout << "Tambah menu makan/minum: ";
		cin.get();
		getline(cin, A.namaMamin);
	}
	cout << "Harga makanan: ";
	cin >> A.hargaMamin;
	A.IDMamin = generatorIDChild();
	while (findElmChild(L, A.IDMamin) != NULL) {
		A.IDMamin = generatorIDChild();
	}
	cout << "ID makanan/minuman: " << A.IDMamin;
	A.countMamin = 0;
}

string generatorIDChild() {
	int r;
	stringstream sss;
	srand((int)time(0));
	r = (rand() % 850) + 1;
	sss << r;
	string s;
	sss >> s;
	return s;
}

void deallocateChild(addressChild& P) {
	delete P;
}
