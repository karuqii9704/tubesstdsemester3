#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include "main.h"
#include "parent.h"
#include "child.h"

typedef struct elmlist_rel *address_rel;

struct elmlist_rel {
    address_mhs nextmhs;
    address_buku nextbuku;
    address_rel next;
    address_rel prev;
};

struct list_rel{
    address_rel first;
    address_rel last;
};


address_rel alokasiRel(address_mhs mhs, address_buku buku);
void dealokasiRel(address_rel &P);
void createListRel(list_rel &L);
void insertLastRel(list_rel &L,address_rel P);
void deleteFirstRel(list_rel &L, address_rel &P);
void deleteLastRel(list_rel &L, address_rel &P);
void deleteRel(list_rel &L, address_rel &P);
void printAllInfo(list_mhs Lmhs,list_rel Lrel);
address_rel findElementRel(list_rel L,address_mhs mhs,address_buku buku);
void menentukanRelasi(list_rel &L, address_mhs Pmhs, address_buku Pbuku);
void menghapusRelasi(list_rel &L, address_mhs Pmhs, address_buku Pbuku);
int jumlahBukuKeranjang(list_rel &L, address_mhs Pmhs);
void printKeranjang(list_rel &L, address_mhs Pmhs);

#endif // LIST_RELASI_H_INCLUDED
