#include "main.h"
#include "parent.h"
#include "relasi.h"
#include "child.h"

int main()
{
    list_mhs Lmhs;
    list_buku Lbuku;
    list_rel Lrel;
    address_mhs Pmhs;
    address_buku Pbuku;
    address_rel Prel;
    infotype_mhs Xmhs;
    infotype_buku Xbuku;
    createListMhs(Lmhs);
    createListBuku(Lbuku);
    createListRel(Lrel);

//    =================================================================
    // Buku 1
            Xbuku.judul = "Foto_Alam";
            Xbuku.hargaBuku = 100000;
            Pbuku=alokasiBuku(Xbuku);
            insertLastBuku(Lbuku,Pbuku);
     // Buku 2
            Xbuku.judul = "Mendung";
            Xbuku.hargaBuku = 75000;
            Pbuku=alokasiBuku(Xbuku);
            insertLastBuku(Lbuku,Pbuku);
    // Buku 3
            Xbuku.judul = "Resep_Masak";
            Xbuku.hargaBuku = 50000;
            Pbuku=alokasiBuku(Xbuku);
            insertLastBuku(Lbuku,Pbuku);

    // mahasiswa 1
            Xmhs.nama= "Ali";
            Xmhs.totalHarga = 0;
            Pmhs=alokasiMhs(Xmhs);
            insertLastMhs(Lmhs,Pmhs);
            Pmhs=findElementMhs(Lmhs,Xmhs);
            Xbuku.judul = "Mendung";
            Pbuku=findElementBuku(Lbuku,Xbuku);
            menentukanRelasi(Lrel,Pmhs,Pbuku);
    // mahasiswa 2
            Xmhs.nama= "Becky";
            Xmhs.totalHarga = 0;
            Pmhs=alokasiMhs(Xmhs);
            insertLastMhs(Lmhs,Pmhs);
            Pmhs=findElementMhs(Lmhs,Xmhs);
            Xbuku.judul = "Foto_Alam";
            Pbuku=findElementBuku(Lbuku,Xbuku);
            menentukanRelasi(Lrel,Pmhs,Pbuku);
    // mahasiswa 3
            Xmhs.nama= "Caca";
            Xmhs.totalHarga = 0;
            Pmhs=alokasiMhs(Xmhs);
            insertLastMhs(Lmhs,Pmhs);
            Pmhs=findElementMhs(Lmhs,Xmhs);
            Xbuku.judul = "Resep_Masak";
            Pbuku=findElementBuku(Lbuku,Xbuku);
            menentukanRelasi(Lrel,Pmhs,Pbuku);




//    =================================================================
    bool loop = true;
    char n;
    string x; bool isdeletevalid;
    while(loop){
        cout<<"1.insert last Mahasiswa"<<endl;
        cout<<"2.insert last Buku"<<endl;
        cout<<"3.delete Mahasiswa"<<endl;
        cout<<"4.delete Buku"<<endl;
        cout<<"5.printinfo Mahasiswa"<<endl;
        cout<<"6.printinfo Buku"<<endl;
        cout<<"7.menentukan relasi(Masukkan buku dalam keranjang)"<<endl;
        cout<<"8.menghapus relasi(keluarkan buku dari keranjang)"<<endl;
        cout<<"9.printallinfo"<<endl;
        cout<<"0 keluar"<<endl<<endl;

        cout<<"pil: ";cin>>n;
        switch(n){
        case '1' :
            cout<<"nama mhs: ";cin>>Xmhs.nama;cout<<endl;
            Xmhs.totalHarga = 0;
            Pmhs=alokasiMhs(Xmhs);
            insertLastMhs(Lmhs,Pmhs);
            printInfoMhs(Lmhs);
            cout<<endl<<"tekan enter";_getch();system("cls");break;
        case '2' :
            cout<<"judul buku: ";cin>>Xbuku.judul;cout<<endl;
            cout<<"harga buku: ";cin>>Xbuku.hargaBuku;cout<<endl;
            Pbuku=alokasiBuku(Xbuku);
            insertLastBuku(Lbuku,Pbuku);
            printInfoBuku(Lbuku);
            cout<<endl<<"tekan enter";_getch();system("cls");break;
        case '3' :
            cout<<"nama mhs : ";cin>>Xmhs.nama;
            Pmhs=findElementMhs(Lmhs,Xmhs);
            cout<<endl;
            if(Pmhs==NULL){
                cout<<"mahasiswa tidak ditemukan"<<endl<<endl;
            }
            else{
                Prel=first(Lrel);
                isdeletevalid=true;

                while(Prel!=NULL){
                    if(nextmhs(Prel)==Pmhs){
                        isdeletevalid=false;
                        Prel=NULL;
                    }else{
                        Prel=next(Prel);
                    }
                }
                if(isdeletevalid){
                    deleteMhs(Lmhs,Pmhs);
                    cout<<"delete berhasil"<<endl<<endl;
                }else{
                    cout<<"delete gagal"<<endl<<endl;
                }
            }
            cout<<"tekan enter";_getch();system("cls");break;
        case '4' :
            cout<<"judul buku : ";cin>>Xbuku.judul;
            Pbuku=findElementBuku(Lbuku,Xbuku);
            cout<<endl;
            if(Pbuku==NULL){
                cout<<"Buku tidak ditemukan"<<endl<<endl;
            }
            else{
                Prel=first(Lrel);
                isdeletevalid=true;

                while(Prel!=NULL){
                    if(nextbuku(Prel)==Pbuku){
                        isdeletevalid=false;
                        Prel=NULL;
                    }else{
                        Prel=next(Prel);
                    }
                }
                if(isdeletevalid){
                    deleteBuku(Lbuku,Pbuku);
                    cout<<"delete berhasil"<<endl<<endl;
                }else{
                    cout<<"delete gagal"<<endl<<endl;
                }
            }
            cout<<"tekan enter";_getch();system("cls");break;
        case '5' :
            cout<<endl;
            printInfoMhs(Lmhs);
            cout<<endl<<"tekan enter";_getch();system("cls");break;
        case '6' :
            cout<<endl;
            printInfoBuku(Lbuku);
            cout<<endl<<"tekan enter";_getch();system("cls");break;
        case '7' :
            cout<<"nama mhs : ";cin>>Xmhs.nama;
            Pmhs=findElementMhs(Lmhs,Xmhs);
            cout<<"judul buku : ";cin>>Xbuku.judul;
            Pbuku=findElementBuku(Lbuku,Xbuku);
            cout<<endl;
            menentukanRelasi(Lrel,Pmhs,Pbuku);
            cout<<"buku berhasil dimasukkan kedalam keranjang"<<endl<<endl;
            cout<<endl;
            printAllInfo(Lmhs,Lrel);
            cout<<"tekan enter";_getch();system("cls");break;
        case '8':
            cout<<"nama mhs : ";cin>>Xmhs.nama;
            Pmhs=findElementMhs(Lmhs,Xmhs);
            cout<<"judul buku : ";cin>>Xbuku.judul;
            Pbuku=findElementBuku(Lbuku,Xbuku);
            cout<<endl;
            menghapusRelasi(Lrel,Pmhs,Pbuku);
            cout<<endl;
            printAllInfo(Lmhs,Lrel);
            cout<<"tekan enter";_getch();system("cls");break;
        case '9' :
            cout<<endl;
            printAllInfo(Lmhs,Lrel);
            cout<<endl<<"tekan enter";_getch();system("cls");break;
            break;
        case '0' :
            loop=false;break;
        default :
            cout<<endl<<"pil salah"<<endl;
            cout<<"tekan enter";_getch();system("cls");break;
        }
    }
//=====================================================================
    return 0;
}
