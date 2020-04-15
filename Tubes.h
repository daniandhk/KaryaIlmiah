#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED
#include <iostream>
#include <cstdlib>

#define infoKar(P) (P)->infoKar
#define infoKey(P) (P)->infoKey
#define nextKar(P) (P)->nextKar
#define nextKey(P) (P)->nextKey
#define nextRel(P) (P)->nextRel
#define prevKar(P) (P)->prevKar
#define prevKey(P) (P)->prevKey
#define firstKar(L) L.firstKar
#define firstKey(L) L.firstKey
#define firstRel(L) L.firstRel
#define lastKar(L) L.lastKar
#define lastKey(L) L.lastKey
#define toKar(P) (P)->toKar
#define toKey(P) (P)->toKey
#define NIL NULL

using namespace std;

typedef struct dataKeyword *addressKey;
typedef struct dataKaryaIlmiah *addressKar;
typedef struct listRelasi *addressRel;

struct infotype {
    string judul;
    string penulis;
    string publisher;
    int tahun;
    string abstrak;
};

struct dataKaryaIlmiah {         //sirkular
    infotype infoKar;
    addressKar nextKar;
    addressKar prevKar;
};

struct listRelasi {         //single
    addressRel nextRel;
    addressKar toKar;
    addressKey toKey;
};

struct dataKeyword {          //double
    string infoKey;
    addressKey nextKey;
    addressKey prevKey;
};

struct KaryaIlmiah {
    addressKar firstKar;
    addressKar lastKar;
};

struct Keyword {
    addressKey firstKey;
    addressKey lastKey;
};

struct Relasi {
    addressRel firstRel;
};

bool isEmptyKar(KaryaIlmiah A);     //done
bool isEmptyKey(Keyword B);         //done
bool isEmpty(Relasi C);             //done
void buatListKar(KaryaIlmiah &A);   //done
void buatListKey(Keyword &B);       //done
void buatListRel(Relasi &C);        //done
void buatDataKar(infotype x, addressKar &P);    //done
void buatDataKey(string x, addressKey &P);      //done
void buatRelasi(addressKar x, addressKey y, addressRel &P);     // done
void insertLastRelasi(Relasi &C, addressRel P);                 // done (insert last)
void insertFirstKey(Keyword &B, addressKey P);                  // done (insert first)
void insertKar(KaryaIlmiah &A, addressKar P);                   // done (insert sort)
addressRel searchKeyRel(Relasi C, addressKey P);    //done
addressRel searchKarRel(Relasi C, addressKar P);    //done
addressKey searchKeyword(Keyword B, string x);      //done
addressKar searchJudul(KaryaIlmiah A, string x);    //done
void printKar(Relasi C, KaryaIlmiah A, string x);   //done
void printKey(Relasi C, Keyword B, string x);       //done
void printALLKey(Keyword B);            // done
void printALLKar(KaryaIlmiah A, Relasi C);        // done
void printALL(KaryaIlmiah A, Keyword B, Relasi C);          // done
void printRel(KaryaIlmiah A, Keyword B, Relasi C);
void printKeyTerbanyak(Relasi C); //
void deleteKey(Keyword &B, addressKey &P, Relasi C);        //
void deleteKar(KaryaIlmiah &A, addressKar &P, Relasi C);    //
bool duplicate(KaryaIlmiah A, string x);
bool duplicate(Keyword B, addressKey P);
int jumlahrelasi(Relasi C, addressKar P);
addressRel searchRelasi(Relasi C, addressKar P, addressKey Q);
void deleteRelasi(Relasi &C, addressKar P, addressKey Q);

#endif // TUBES_H_INCLUDED
