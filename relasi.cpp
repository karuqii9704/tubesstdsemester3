#include "relasi.h"

address_rel alokasiRel(address_mhs mhs, address_buku buku){
    address_rel P=new elmlist_rel;
    nextmhs(P)=mhs;
    nextbuku(P)=buku;
    next(P)=NULL;
    prev(P)=NULL;
    return P;
}

void dealokasiRel(address_rel &P){
    delete P;
    P=NULL;
}

void createListRel(list_rel &L){
    first(L)=NULL;
    last(L)=NULL;
}
void insertLastRel(list_rel &L,address_rel P){
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
void deleteFirstRel(list_rel &L, address_rel &P){
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
void deleteLastRel(list_rel &L, address_rel &P){
    if (first(L)!=NULL && last(L)!=NULL){
        if(first(L)==last(L)){
            deleteFirstRel(L,P);
        }
        else{
            P=last(L);
            last(L)=prev(P);
            prev(P)=NULL;
            next(last(L))=NULL;
        }
    }
}
void deleteRel(list_rel &L, address_rel &P){
    if(P!=NULL){
        if (P==first(L)){
            deleteFirstRel(L,P);
        }
        else if (P==last(L)){
            deleteLastRel(L,P);
        }
        else {
            next(prev(P))=next(P);
            prev(next(P))=prev(P);
            next(P)=NULL;
            prev(P)=NULL;
        }
    }
}

void printAllInfo(list_mhs Lmhs, list_rel Lrel){
    address_mhs Pmhs;
    address_rel Prel;
    address_buku Pbuku;
    int i = 0;
    bool status;

    Pmhs=first(Lmhs);
    if(Pmhs==NULL){
        cout<<"< Data Mahasiswa tidak ditemukan >"<<endl;
    }
    while(Pmhs!=NULL){
        Prel=first(Lrel);
        status=false;
        cout<<"Nama Anggota\t : "<<info(Pmhs).nama<<endl;
        while(Prel!=NULL){
            if(nextmhs(Prel)==Pmhs){
                cout<<"status\t\t : Judul buku :"<<info(nextbuku(Prel)).judul<<endl;
                cout<<"status\t\t : Harga buku :"<<info(nextbuku(Prel)).hargaBuku<<endl;
                cout<<i<<"status\t\t :Total Harga :"<<info(nextmhs(Prel)).totalHarga<<endl;
                status=true;
            }
            Prel=next(Prel);
        }
        if(!status){
            cout<<"Status\t\t : Keranjang Kosong"<<endl;
        }
        cout<<endl;
        Pmhs=next(Pmhs);

    }
}
address_rel findElementRel(list_rel L,address_mhs mhs,address_buku buku){
    address_rel P=first(L);

    while (P!=NULL){
        if (nextmhs(P)==mhs && nextbuku(P)==buku){
            return P;
        }
        P=next(P);
    }
    return P;
}
void menentukanRelasi(list_rel &L, address_mhs Pmhs, address_buku Pbuku){
    address_rel Prel;
    bool duplikat=false;

    if(Pmhs==NULL && Pbuku==NULL){
        cout<<"mahasiswa & buku tidak ditemukan"<<endl;
    }else if(Pbuku==NULL){
        cout<<"buku tidak ditemukan"<<endl;
    }else if(Pmhs==NULL){
        cout<<"Mahasiswa tidak ditemukan"<<endl;
    }else{
        Prel=first(L);
        while(Prel!=NULL){
            if(nextmhs(Prel)==Pmhs && nextbuku(Prel)==Pbuku){
            }
            Prel=next(Prel);
            }
            Prel=alokasiRel(Pmhs,Pbuku);
            insertLastRel(L,Prel);
            info(Pmhs).totalHarga = info(Pmhs).totalHarga+info(Pbuku).hargaBuku;

    }
}

void menghapusRelasi(list_rel &L, address_mhs Pmhs, address_buku Pbuku){
    address_rel Prel;
    bool found=false;

    if(Pmhs==NULL && Pbuku==NULL){
        cout<<"mahasiswa & buku tidak ditemukan"<<endl;
    }else if(Pbuku==NULL){
        cout<<"buku tidak ditemukan"<<endl;
    }else if(Pmhs==NULL){
        cout<<"Mahasiswa tidak ditemukan"<<endl;
    }else{
        Prel=first(L);
        while(Prel!=NULL){
            if(nextmhs(Prel)==Pmhs && nextbuku(Prel)==Pbuku){
                found=true;
                info(Pmhs).totalHarga = info(Pmhs).totalHarga-info(Pbuku).hargaBuku;
                deleteRel(L,Prel);
                dealokasiRel(Prel);
                Prel=NULL;
            }else{
                Prel=next(Prel);
            }
        }
        if(found){
            cout<<"buku berhasil dikeluarkan dari keranjang"<<endl<<endl;
        }else{
            cout<<"buku tidak terdapat dikeranjang"+info(Pbuku).judul<<endl;
        }
    }
}


