#include "child.h"

address_buku alokasiBuku(infotype_buku X){
    address_buku P= new elmlist_buku;
    info(P)=X;
    next(P)=NULL;
    prev(P)=NULL;
    return P;
}
void dealokasiBuku(address_buku &P){
    delete P;
    P=NULL;
}
void createListBuku(list_buku &L){
    first(L)=NULL;
    last(L)=NULL;
}
void insertLastBuku(list_buku &L,address_buku P){
    if (first(L)==NULL && last(L)==NULL){
        first(L)=P;
        last(L)=P;
    }
    else{
        next(last(L))=P;
        prev(P)=last(L);
        last(L)=P;
    }
}
void deleteFirstBuku(list_buku &L, address_buku &P){
    if (first(L) != NULL && last(L)!=NULL) {
        P = first(L);
        if (first(L)==last(L)){
            first(L)=NULL;
            last(L)=NULL;
        }
        else {
            first(L)=next(P);
            prev(first(L))=NULL;
            next(P)=NULL;
        }
    }
}
void deleteLastBuku(list_buku &L, address_buku &P){
    if (first(L)!=NULL && last(L)!=NULL){
        if(first(L)==last(L)){
            deleteFirstBuku(L,P);
        }
        else{
            P=last(L);
            last(L)=prev(P);
            prev(P)=NULL;
            next(last(L))=NULL;
        }
    }
}
void deleteBuku(list_buku &L, address_buku &P){
    if(P!=NULL){
        if (P==first(L)){
            deleteFirstBuku(L,P);
        }
        else if (P==last(L)){
            deleteLastBuku(L,P);
        }
        else {
            next(prev(P))=next(P);
            prev(next(P))=prev(P);
            next(P)=NULL;
            prev(P)=NULL;
        }
    }
}
void printInfoBuku(list_buku L){
    address_buku P;

    if(first(L)==NULL && last(L)==NULL){
        cout<<"< Data buku tidak ditemukan >"<<endl;
    }
    else{
        P=first(L);
        int i=1;
        do{
            cout<<i<<".)\tJudul buku : "<<info(P).judul<<endl;
            cout<<".)\tHarga buku : "<<info(P).hargaBuku<<endl;
            P=next(P);
            i++;
        }while(P!=NULL);
    }
}
address_buku findElementBuku(list_buku L, infotype_buku X){
    address_buku P=first(L);

    while(P!=NULL){
        if (X.judul==info(P).judul){
            return P;
        }
        P=next(P);
    }
    return P;
}
