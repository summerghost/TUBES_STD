/* AKMAL MUHAMAD F. 1301190436
   MUHAMAD SULTHON A. 1301194008
   IF-43-05
*/

#include "listRelasi.h"

using namespace std;

void createListRelasi(listRelasi& L) {
    L.first = NULL;
    L.last = NULL;
}

relateAddress CreateElmRelasi(address_parent P, addressChild Q) {
    relateAddress R = new Relasi;
    R->warteg = P;
    R->mamin = Q;
    R->next = NULL;
    R->prev = NULL;
    return R;
}

void insertRelasi(listRelasi& L, relateAddress P) {
    if (L.first == NULL) {
        L.first = R;
        L.last = R;
    }
    else {
        L.last->next = R;
        R->prev = L.last;
        L.last = R;
    }
}

void deleteFirstRelasi(listRelasi& L, relateAddress& R) {
    if (L.first != L.last) {
        R = L.first;
        L.first = R->next;
        R->next = NULL;
        L.first->prev = NULL;
    }
    else {
        R = L.first;
        L.first = NULL;
        L.last = NULL;
    }
}

void deleteAfterRelasi(listRelasi& L, relateAddress prec, relateAddress& R) {
    R->next = prec->next;
    Prec->next = R->next;
}

void deleteLastRelasi(listRelasi& L, relateAddress& R) {
    R = L.last;
    L.last = R->prev;
    R->prev = NULL;
    L.last->next = NULL;
}
void deleteSpecificRelasi(listRelasi& L, string warteg, string namaMamin) {
    relateAddress R = L.first;
    if (R != NULL) {
        if (L.first->warteg->info.warteg == namaWarteg && L.first->mamin->info.namaMamin == namaMamin) {
            deleteFirstRelasi(L, R);
        }
        else if (L.last->warteg->info.namaWarteg == namaWarteg && L.last->mamin->info.namaMamin == namaMamin) {
            deleteLastRelasi(L, R);
        }
        else {
            while (R != NULL && R->warteg->info.namaWarteg != namaWarteg && R->mamin->info.namaMamin != namaMamin) {
                R = R->next;
            }
            if (R->warteg->info.namaWarteg == namaWarteg && R->mamin->info.namaMamin == namaMamin) {
                deleteAfterRelasi(L, R->prev, R);
            }
            else {
                cout << "Belum ada relasi." << endl;
            }
        }
    }
    else {
        cout << "Tidak ada relasi saat ini." << endl;
    }
    cout << endl;
}
relateAddress findElmRelasiParent(listRelasi& L, string out) {
    relateAddress R = L.first;
    while (R != NULL) {
        if (R->warteg->info.namaWarteg == out) {
            return R;
        }
        R = R->next;
    }
    return NULL;
}
}

relateAddress findElmRelasiChild(listRelasi& L, string out);
void printInfoRelasi(listRelasi L) {
    relateAddress R = L.first;
    while (R != NULL) {
        cout << R->mamin->info.namaMamin << " tersedia di ";
        cout << R->warteg->info.namaWarteg << endl;
        R = R->next;
    }
    cout << endl;
}

void deleteAllRelasiParent(listRelasi& L, address_parent P);
void deleteAllRelasiChild(listRelasi& L, addressChild Q);
