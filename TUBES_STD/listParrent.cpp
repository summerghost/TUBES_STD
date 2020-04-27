#include <iostream>>
#include "listParent.h"



void createListParent(List_Parent &L){
    first(L) = NULL;
}
address_parent createElmParent(infotypeParent in){
    address_parent P = new parent;
    info(P) = X;
    next(P) = NULL;
    return P;
}

void insertFirstParent(List_Parent &L, address_parent P){
    if(first(L) == NULL){
        first(L) = P;
        last(L) = P;
    }else{
        next(P) = first(L);
        first(L) = P;
    }
}
void insertAfterParent(List_Parent &L, address_parent Prec, address_parent P){
    next(P) = next(Prec);
    next(Prec) = P;
}
void insertLastParent(List_Parent &L, address_parent P){
    if(first(L) == NULL){
        insertLastparent(L,P);
    }else{
        next(last(L)) = P;
        last(L) = P;
    }
}

void insertSortedParent(List_Parent &L, infotypeParent X){
    if(first(L) != NULL){
        if(findElmParent(L, in.warteg) == NULL){
            if(in.warteg > info.warteg(first(L))){
                insertFirstParent(L, createElmParent(in));

            }else if(in.warteg < info.warteg(last(L))){
                insertLastparent(L, createElmParent());
            }else{
                address_parent P = first(L);
                while(P != NULL && in.warteg > info.warteg(P)){
                    P = next(P);
                }
                insertAfterParent(L, createElmParent(in))'
            }
        }else{
            cout <<"warteg telah terdaftar"<<endl;
        }
    }else{
        insertFirstParent(L, createElmParent(in));
    }
}

void deleteFirstParent(List_Parent &L, address_parent &P){}
void deleteAfterParent(List_Parent &L, address_parent Prec, address_parent &P){}
void deleteLastParent(List_Parent &L, address_parent &P){}

address_parent findElmParent(List_Parent &L, string X){}
void printInfoParent(List_Parent L);
void deleteSpesifikParent(List_Parent &L, string X){}
