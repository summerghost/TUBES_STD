#include "listChild.h"

void createListChild(listChild& L) {
	L.first = NULL;
}

addressChild createElmChild(infotypeChild in) {
	addressChild P = new child;
	P->info = x;
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
	Prev->next = P;
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
	if (L.first != NULL) {
		if (findElmChild(L, in.namaMamin) == NULL) {
			if (in.namaTahanan > L.first->info.namaMamin) {
				insertFirstChild(L, CreateElmChild(in));
			}
			else if (in.namaMamin < L.last->info.namaMamin) {
				insertLastChild(L, createElmChild(in));
			}
			else {
				addressChild P = L.first;
				while (P != NULL && in.namaMamin > P->info.namaMamin) {
					P = P->next;
				}
				insertAfterChild(L, P, createElmChild(in));
			}
		}
		else {
			cout << "Makanan/minuman sudag terdaftar" << endl;
		}
	}
	else {
		insertFirstChild(L, createElmChild(in));
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
			addressChild Q;
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

address_child findElmChild(listChild& L, string A) {
	addressChild P = L.first;
	while (P != NULL && P->info.namaMamin != A && P->info.IDMamin != A) {
		p = P->next;
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

void inputDataMamin(listChild L, infotypeChild& in) {
	cout << "Tambah menu makan/minum: ";
	cin.get();
	getline(cin, in.namaMamin);
	while (findElmChild(L, in.namaMamin) != NULL) {
		cout << "Makanan/minuman sudah ada. Input kembali." << endl;
		cout << "Tambah menu makan/minum: ";
		cin.get();
		getline(cin, in.namaMamin);
	}
	cout << "Harga makanan: ";
	cin >> in.hargaMamin;
	in.IDMamin = generatorIDChild();
	while (findElmChild(L, in.IDMamin) != NULL) {
		in.IDMamin = generatorIDChild();
	}
	cout << "ID makanan/minuman: " << in.IDMamin;
	in.countMamin = 0;
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
