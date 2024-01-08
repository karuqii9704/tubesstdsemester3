#include "parent.h"

address_mhs alokasiMhs(infotype_mhs X){
    address_mhs P=new elmlist_mhs;
    info(P)=X;
    next(P)=NULL;
    prev(P)=NULL;
    return P;
}
void dealokasiMhs(address_mhs &P){
    delete P;
    P=NULL;
}
void createListMhs(list_mhs &L){
    first(L)=NULL;
    last(L)=NULL;
}
void insertLastMhs(list_mhs &L,address_mhs P){
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
void deleteFirstMhs(list_mhs &L, address_mhs &P){
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
void deleteLastMhs(list_mhs &L, address_mhs &P){
    if (first(L)!=NULL && last(L)!=NULL){
        if(first(L)==last(L)){
            deleteFirstMhs(L,P);
        }
        else{
            P=last(L);
            last(L)=prev(P);
            prev(P)=NULL;
            next(last(L))=NULL;
        }
    }
}
void deleteMhs(list_mhs &L, address_mhs &P){
    if(P!=NULL){
        if (P==first(L)){
            deleteFirstMhs(L,P);
        }
        else if (P==last(L)){
            deleteLastMhs(L,P);
        }
        else {
            next(prev(P))=next(P);
            prev(next(P))=prev(P);
            next(P)=NULL;
            prev(P)=NULL;
        }
    }
}
void printInfoMhs(list_mhs L){
    address_mhs P;

    if(first(L)==NULL && last(L)==NULL){
        cout<<"< Data anggota tidak ditemukan >"<<endl;
    }
    else{
        P=first(L);
        int i=1;
        do{
            cout<<i<<".)\tNama Mahasiswa : "<<info(P).nama<<endl;
            cout<<"\tTotal Belanja : "<<info(P).totalHarga<<endl;
            P=next(P);
            i++;
        }while(P!=NULL);
    }
}
address_mhs findElementMhs(list_mhs L, infotype_mhs X){
    address_mhs P=first(L);

    while(P!=NULL){
        if (X.nama==info(P).nama){
            return P;
        }
        P=next(P);
    }
    return P;
}
