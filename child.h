#ifndef CHILD_H_INCLUDED
#define CHILD_H_INCLUDED


#include "main.h"

struct infotype_buku{
     string judul;
     int hargaBuku;
};

typedef struct elmlist_buku *address_buku;

struct elmlist_buku{
    infotype_buku info;
    address_buku next;
    address_buku prev;
};

struct list_buku{
    address_buku first;
    address_buku last;
};

address_buku alokasiBuku(infotype_buku X);
void dealokasiBuku(address_buku &P);
void createListBuku(list_buku &L);
void insertLastBuku(list_buku &L,address_buku P);
void deleteFirstBuku(list_buku &L, address_buku &P);
void deleteLastBuku(list_buku &L, address_buku &P);
void deleteBuku(list_buku &L, address_buku &P);
void printInfoBuku(list_buku L);
address_buku findElementBuku(list_buku L, infotype_buku X);

#endif // LIST_BUKU_H_INCLUDED
