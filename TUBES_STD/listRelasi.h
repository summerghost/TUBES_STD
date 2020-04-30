/* AKMAL MUHAMAD F. 1301190436
   MUHAMAD SULTHON A. 1301194008
   IF-43-05
*/

#include <iostream>
#include "listParrent.h"
#include "listChild.h"

using namespace std;

typedef struct Relasi* relateAddress;

struct Relasi {
	address_parent warteg;
	addressChild mamin;
	relateAddress next;
	relateAddress prev;
};

struct listRelasi {
	relateAddress first;
	relateAddress last;
};

void createListRelasi(listRelasi& L);
relateAddress CreateElmRelasi(address_parent P, addressChild Q);
void insertRelasi(listRelasi& L, relateAddress P);
void deleteFirstRelasi(listRelasi& L, relateAddress& R);
void deleteAfterRelasi(listRelasi& L, relateAddress prec, relateAddress& R);
void deleteLastRelasi(listRelasi& L, relateAddress& R);
void deleteSpecificRelasi(listRelasi& L, string warteg, string namaMamin);
relateAddress findElmRelasiParent(listRelasi& L, string out);
relateAddress findElmRelasiChild(listRelasi& L, string out);
void printInfoRelasi(listRelasi L);

void deleteAllRelasiParent(listRelasi& L, address_parent P);
void deleteAllRelasiChild(listRelasi& L, addressChild Q);

