#include <iostream>
#include <cstdlib>
#include <sstream>
#include <ctime>

using namespace std;

struct infotypeChild {
	string namaMamin;
	string IDMamin;
	int hargaMamin;
	int countMamin;
};

typedef struct child* addressChild;

struct child {
	infotypeChild info;
	addressChild next;
};

struct listChild {
	addressChild first;
	addressChild last;
};

void createListChild(listChild& L);
addressChild createElmChild(infotypeChild in);
void insertFirstChild(listChild& L, addressChild P);
void insertAfterChild(listChild& L, addressChild Prec, addressChild P);
void insertLastChild(listChild& L, addressChild P);

void insertSortedChild(listChild& L, infotypeChild A);
void deleteFirstChild(listChild& L, addressChild& P);
void deleteAfterChild(listChild& L, addressChild Prec, addressChild& P);
void deleteLastChild(listChild& L, addressChild& P);
void deleteSpecificChild(listChild& L, string A);
addressChild findElmChild(listChild& L, string A);
void printInfoChild(listChild L);

void inputDataMamin(listChild L, infotypeChild& A);

string generatorIDChild();
void deallocateChild(addressChild& P);
