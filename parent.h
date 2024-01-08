#ifndef PARENT_H_INCLUDED
#define PARENT_H_INCLUDED

#include "main.h"

struct infotype_mhs{
     string nama;
     int totalHarga;
};

typedef struct elmlist_mhs *address_mhs;

struct elmlist_mhs {
    infotype_mhs info;
    address_mhs next;
    address_mhs prev;
};

struct list_mhs{
    address_mhs first;
    address_mhs last;
};

address_mhs alokasiMhs(infotype_mhs X);
void dealokasiMhs(address_mhs &P);
void createListMhs(list_mhs &L);
void insertLastMhs(list_mhs &L,address_mhs P);
void deleteFirstMhs(list_mhs &L, address_mhs &P);
void deleteLastMhs(list_mhs &L, address_mhs &P);
void deleteMhs(list_mhs &L, address_mhs &P);
void printInfoMhs(list_mhs L);
address_mhs findElementMhs(list_mhs L, infotype_mhs X);

#endif // LIST_MHS_H_INCLUDED
