#include<iostream>
#include<cstdlib>
#include<crtime>
#include<sstream>

using name space std;

struct infotypeParent{
    string warteg;
    string IDWarteg;
    int kapasitas;
};
typedef struct parent *address_parent;

struct parent{
    infotypeParent info;
    address_parent next;
};

struct List_Parent{
    address_parent first;
    address_parent last;
};

void inputWarteg(List_Parent L, infotypeParent &in);
string generatorIDParent();

void createListParent(List_Parent &L);
address_parent createElmParent(infotypeParent in);

void insertFirstParent(List_Parent &L, address_parent P);
void insertAfterParent(List_Parent &L, address_parent Prec, address_parent P);
void insertLastParent(List_Parent &L, address_parent P);

void insertSortedParent(List_Parent &L, infotypeParent X);

void deleteFirstParent(List_Parent &L, address_parent &P);
void deleteAfterParent(List_Parent &L, address_parent Prec, address_parent &P);
void deleteLastParent(List_Parent &L, address_parent &P);

address_parent findElmParent(List_Parent &L, string X);
void printInfoParent(List_Parent L);
void deleteSpesifikParent(List_Parent &L, string X);
void deallocateParent(address_parent &P);
