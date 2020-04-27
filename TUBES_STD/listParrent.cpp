#include <iostream>>
#include "listParent.h"



void inputWarteg(List_Parent L, infotypeParent &in){
    cout<<"nama warteg :";
    cin.get();
    getline(cin, in.Warteg);
    while(findElmParent(L, in.Warteg) != NULL){
        cout<<"nama warteg sudah ada dimohon input kembali"<<endl;
        cout<<"nama warteg : ";
        cin.get();
        getline(cin, in.Warteg);
    }
    cout<<"kapasitas warteg : " ;
    cin>> in.kapasitas;
    in.IDWarteg = generatorIDParent();
    while(findElmParent(L, in.IDWarteg) != NULL){
        in.IDWarteg = generatorIDParent();
    }
    cout<<"ID warteg : "<<in.IDWarteg;
    in.countWarteg = 0;
}

string generatorID(){
    int r
    stringstream sss;
    srand((int)time(0));
    r = (rand() % 850) + 1;
    sss<<r;
    string s;
    sss>>s;
    return s;
}


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
void deleteFirstParent(List_Parent &L, address_parent &P){
    if(first(L) != last(L)){
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
    }else{
        P + first(L);
        first(L) = NULL;
        last(L) = NULL;
    }
}
void deleteAfterParent(List_Parent &L, address_parent Prec, address_parent &P){
    next(P) = next(Prec);
    next(Prec) = next(P);
}
void deleteLastParent(List_Parent &L, address_parent &P){
    address_parent Q = first(L);
    while(next(next(Q)) != NULL){
        Q = next(Q);
    }
    P = next(Q);
    next(Q) = NULL;
}
address_parent findElmParent(List_Parent &L, string X){
    address_parent P = first(L);
    while(P != NULL && info.Warteg(P) != X && info.IDWarteg != X){
        P = next(P);
    }
    return P;
}
void printInfoParent(List_Parent L){
    address_parent P = first(L);
    while(P != NULL){
        cout<<"nama warteg : "<< info.Warteg<<endl;
        cout<<"ID warteg : "<< info.IDWarteg<<endl;
        cout<<"kapasitas warteg : "<<info.Kapasitas<<endl;
        P = next(P);
        cout<<endl;
        cout<<endl;
    }
    cout<<endl;
    cout<<endl;
}
void deleteSpesifikParent(List_Parent &L, string X){
    address_parent P = findElmParent(L, X);
    if(first(L) != NULL && P != NULL){
        if(info.Warteg first(L) == X){
            deleteFirstParent(L, P);
        }else if(info.Warteg last(L) == X){
            deleteLastParent(L, p);
        }else {
            P = first(L);
            address_parent Q;
            while(info.Warteg (P) != X){
                Q = P;
                P = next(P);
            }
            deleteAfterParent(L, Q, P);
        }
        cout<<"hapus warteg "<<X<<" berhasil"<<endl;
    }else{
        cout<<"warteg ga ada bangkrut"<<endl;
    }
    cout<<endl;
}

void deallocateParent(address_parent &P){
    delete P;
}

