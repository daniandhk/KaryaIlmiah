#include "Tubes.h"

bool isEmptyKar(KaryaIlmiah A) {
    return(firstKar(A) == NIL && lastKar(A) == NIL);
}

bool isEmptyKey(Keyword B){
    return(firstKey(B) == NIL && lastKey(B) == NIL);
}

bool isEmpty(Relasi C){
    return(firstRel(C) == NIL);
}

void buatListKar(KaryaIlmiah &A){
    firstKar(A) = NIL;
    lastKar(A) = NIL;
}

void buatListKey(Keyword &B){
    firstKey(B) = NIL;
    lastKey(B) = NIL;
}

void buatListRel(Relasi &C){
    firstRel(C) = NIL;
}

void buatDataKar(infotype x, addressKar &P){
    P = new dataKaryaIlmiah;
    infoKar(P).judul = x.judul;
    infoKar(P).penulis = x.penulis;
    infoKar(P).tahun = x.tahun;
    infoKar(P).publisher = x.publisher;
    infoKar(P).abstrak = x.abstrak;
    nextKar(P) = NIL;
    prevKar(P) = NIL;

}
void buatDataKey(string x, addressKey &P) {
    P = new dataKeyword;
    infoKey(P) = x;
    nextKey(P) = NIL;
    prevKey(P) = NIL;
}
void buatRelasi(addressKar x, addressKey y, addressRel &P) {
    P = new listRelasi;
    toKar(P) = x;
    toKey(P) = y;
    nextRel(P) = NIL;
}

void insertLastRelasi(Relasi &C, addressRel P){
    addressRel Q = firstRel(C);
    if(firstRel(C) == NIL){
        firstRel(C) = P;
    }
    else {
        while(nextRel(Q) != NIL) {
            Q = nextRel(Q);
        }
        nextRel(Q) = P;
    }
}

void insertFirstKey(Keyword &B, addressKey P){
    if (firstKey(B) == NIL) {
        firstKey(B) = P;
        lastKey(B) = P;
    }
    else {
        nextKey(P) = firstKey(B);
        prevKey(firstKey(B)) = P;
        firstKey(B) = P;
    }
}

void insertKar(KaryaIlmiah &A, addressKar P){
    addressKar Q = firstKar(A);
    if (Q == NIL){
        nextKar(P) = P;
        prevKar(P) = P;
        firstKar(A) = P;
        lastKar(A) = P;
    } else if (infoKar(Q).judul >= infoKar(P).judul) {
        while (nextKar(Q) != firstKar(A)){
            Q = nextKar(Q);
        }
        nextKar(Q) = P;
        prevKar(P) = Q;
        nextKar(P) = firstKar(A);
        prevKar(Q) = P;
        firstKar(A) = P;
    } else {
        while (nextKar(Q) != firstKar(A) && infoKar(nextKar(Q)).judul < infoKar(P).judul){
            Q = nextKar(Q);
        }
        nextKar(P) = nextKar(Q);
        prevKar(P) = Q;
        prevKar(nextKar(Q)) = P;
        nextKar(Q) = P;
    }
}

addressRel searchKeyRel(Relasi C, addressKey P) {
    addressRel Q = firstRel(C);
    if(firstRel(C)!=NULL){
        while(P != toKey(Q)&&Q!=NULL){
            Q=nextRel(Q);
        }
        if (P!=toKey(Q)){
            Q = NULL;
        }
    }
    return Q;
}

addressRel searchKarRel(Relasi C, addressKar P) {
    addressRel Q = firstRel(C);
    if(firstRel(C)!= NULL){
        while(P != toKar(Q) && Q != NULL){
            Q = nextRel(Q);
        }
        if (P != toKar(Q)) {
            Q = NULL;
        }
    }
    return Q;
}

addressKey searchKeyword(Keyword B, string x){
    addressKey P = firstKey(B);
    if (firstKey(B) != NULL) {
        while ((nextKey(P)!=NULL && infoKey(P) != x)) {
            P = nextKey(P);
        }
        if (infoKey(P) == x) {
            return P;
        }
        else{
            return NULL;
        }
    }
    else{
        return NULL;
    }
}

addressKar searchJudul(KaryaIlmiah A, string x){
    addressKar P = firstKar(A);
    if (firstKar(A) != NULL){
        while(infoKar(P).judul != x && nextKar(P) != firstKar(A)){
            P = nextKar(P);
        }

        if(infoKar(P).judul == x) {
            return P;
        } else {
            return NULL;
        }
    } else {
        return NULL;
    }
}

void printKar(Relasi C, KaryaIlmiah A, string x) {
    addressRel Q = searchKarRel(C,searchJudul(A,x));
    if(Q!= NULL) {
        cout<<"     Judul        : "<<infoKar(toKar(Q)).judul<<endl;
        cout<<"     Penulis      : "<<infoKar(toKar(Q)).penulis<<endl;
        cout<<"     Publisher    : "<<infoKar(toKar(Q)).publisher<<endl;
        cout<<"     Tahun        : "<<infoKar(toKar(Q)).tahun<<endl;
        cout<<"     Abstark      : "<<infoKar(toKar(Q)).abstrak<<endl;
        cout<<"     Keyword      : ";
        while (Q != NULL) {
            if(infoKar(toKar(Q)).judul == x) {
                cout<<infoKey(toKey(Q));
                if(nextRel(Q)!= NULL){
                    cout<<" - ";
                }
            }
            Q=nextRel(Q);
        }
    }
    else {
        cout<<"     Judul        : "<<infoKar(searchJudul(A,x)).judul<<endl;
        cout<<"     Penulis      : "<<infoKar(searchJudul(A,x)).penulis<<endl;
        cout<<"     Publisher    : "<<infoKar(searchJudul(A,x)).publisher<<endl;
        cout<<"     Tahun        : "<<infoKar(searchJudul(A,x)).tahun<<endl;
        cout<<"     Abstark      : "<<infoKar(searchJudul(A,x)).abstrak<<endl;
        cout<<"     Keyword      : - "<<endl;
    }
}

void printKey(Relasi C, Keyword B, string x) {
    addressRel Q = searchKeyRel(C,searchKeyword(B,x));
    if(Q!= NULL) {
        cout<<"     Keywoard     : "<<infoKey(toKey(Q))<<endl;
        cout<<endl;
        while(Q!= NULL) {
            if(infoKey(toKey(Q))==x){
                cout<<"     Judul        : "<<infoKar(toKar(Q)).judul<<endl;
                cout<<"     Penulis      : "<<infoKar(toKar(Q)).penulis<<endl;
                cout<<"     Publisher    : "<<infoKar(toKar(Q)).publisher<<endl;
                cout<<"     Tahun        : "<<infoKar(toKar(Q)).tahun<<endl;
                cout<<"     Abstark      : "<<infoKar(toKar(Q)).abstrak<<endl;
                cout<<"     Keyword      : ";
                addressRel Z = firstRel(C);
                while (Z != NULL) {
                    if(infoKar(toKar(Z)).judul == infoKar(toKar(Q)).judul) {
                        cout<<infoKey(toKey(Z));
                        if(nextRel(Z)!= NULL){
                            cout<<" - ";
                        }
                    }
                    Z=nextRel(Z);
                }
            }
            Q = nextRel(Q);
        }
    }
    else {
        cout<<"     Keywoard     : "<<infoKey(searchKeyword(B,x))<<endl;
        cout<<endl;
        cout<<"     Judul        : -"<<endl;
        cout<<"     Penulis      : -"<<endl;
        cout<<"     Publisher    : -"<<endl;
        cout<<"     Tahun        : -"<<endl;
        cout<<"     Abstark      : -"<<endl;
        cout<<"     Keyword      : -"<<endl;
    }
}

void printALLKey(Keyword B) {
    addressKey Q = firstKey(B);
    if(firstKey(B) != NULL) {
        cout<<"\n     Keyword      : ";
        while(Q!= NULL) {
            cout<<infoKey(Q);
            if(nextKey(Q)!= NULL){
                cout<<" - ";
            }
            Q = nextKey(Q);
        }
    }
    else {
        cout<<"\nKeyword tak ada!"<<endl;
    }
    cout<<endl;
}


void printALLKar(KaryaIlmiah A, Relasi C) {
    addressKar Q = firstKar(A);
    if (firstKar(A) == NIL){
        cout<<"Data Karya Ilmiah Kosong"<<endl;
    } else {
        while(nextKar(Q)!= firstKar(A)) {
            cout<<"     Judul        : "<<infoKar(Q).judul<<endl;
            cout<<"     Penulis      : "<<infoKar(Q).penulis<<endl;
            cout<<"     Publisher    : "<<infoKar(Q).publisher<<endl;
            cout<<"     Tahun        : "<<infoKar(Q).tahun<<endl;
            cout<<"     Abstark      : "<<infoKar(Q).abstrak<<endl;
            cout<<"     Keyword      : ";
                addressRel Z = firstRel(C);
                while (Z != NULL) {
                    if(infoKar(toKar(Z)).judul == infoKar(Q).judul) {
                        cout<<infoKey(toKey(Z));
                        if(nextRel(Z)!= NULL){
                            cout<<" - ";
                        }
                    }
                    Z=nextRel(Z);
                }
            cout<<endl;
            Q = nextKar(Q);
        }
        cout<<"     Judul        : "<<infoKar(Q).judul<<endl;
        cout<<"     Penulis      : "<<infoKar(Q).penulis<<endl;
        cout<<"     Publisher    : "<<infoKar(Q).publisher<<endl;
        cout<<"     Tahun        : "<<infoKar(Q).tahun<<endl;
        cout<<"     Abstark      : "<<infoKar(Q).abstrak<<endl;
        cout<<"     Keyword      : ";
        addressRel Z = firstRel(C);
        while (Z != NULL) {
            if(infoKar(toKar(Z)).judul == infoKar(Q).judul) {
                cout<<infoKey(toKey(Z));
                if(nextRel(Z)!= NULL){
                    cout<<" - ";
                }
            }
            Z=nextRel(Z);
        }
        cout<<endl;
    }
}

void printRel(KaryaIlmiah A, Keyword B, Relasi C){
    addressRel Q = firstRel(C);
    if(Q!= NULL) {
        while(Q!= NULL) {
            cout<<"     Judul        : "<<infoKar(toKar(Q)).judul<<endl;
            cout<<"     Penulis      : "<<infoKar(toKar(Q)).penulis<<endl;
            cout<<"     Publisher    : "<<infoKar(toKar(Q)).publisher<<endl;
            cout<<"     Tahun        : "<<infoKar(toKar(Q)).tahun<<endl;
            cout<<"     Abstark      : "<<infoKar(toKar(Q)).abstrak<<endl;
            cout<<"     Keywoard     : "<<infoKey(toKey(Q))<<endl;
            cout<<endl;
            Q = nextRel(Q);
        }
    }
    else {
        cout<<"\n       Belum ada Data yang di Relasikan\n"<<endl;
    }
}

bool duplicate(KaryaIlmiah A, string x){
    addressKar Q = firstKar(A);
    if(Q != NULL){
        while(Q!= lastKar(A)&&(infoKar(Q).judul != x)){
            Q=nextKar(Q);
        }
        if(infoKar(Q).judul == x){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

bool duplicate(Keyword B, addressKey P){
    addressKey Q = firstKey(B);
    if(Q!= NULL){
        while(Q!= lastKey(B)&&(infoKey(Q)!=infoKey(P))){
            Q=nextKey(Q);
        }
        if(infoKey(Q)== infoKey(P)){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

void printKeyTerbanyak(Relasi C) {
    addressRel P = firstRel(C);
    addressRel Max = P;
    addressRel Min = P;
    addressRel Z;
    if(firstRel(C)!= NULL){
        while(P!= NULL){
            if(jumlahrelasi(C,toKar(P))>jumlahrelasi(C,toKar(Max))){
                Max = P;
            }
            if(jumlahrelasi(C,toKar(P))<jumlahrelasi(C,toKar(Min))){
                Min = P;
            }
            P = nextRel(P);
        }
    }
    cout<<"\n     Artikel Ilmiah dengan Keyword Terbanyak\n"<<endl;
    cout<<"     Judul        : "<<infoKar(toKar(Max)).judul<<endl;
    cout<<"     Penulis      : "<<infoKar(toKar(Max)).penulis<<endl;
    cout<<"     Publisher    : "<<infoKar(toKar(Max)).publisher<<endl;
    cout<<"     Tahun        : "<<infoKar(toKar(Max)).tahun<<endl;
    cout<<"     Abstark      : "<<infoKar(toKar(Max)).abstrak<<endl;
    cout<<"     Keyword      : ";
    Z = firstRel(C);
        while (Z != NULL) {
            if(infoKar(toKar(Z)).judul == infoKar(toKar(Max)).judul) {
                cout<<infoKey(toKey(Z));
                if(nextRel(Z)!= NULL){
                    cout<<" - ";
                }
            }
            Z=nextRel(Z);
        }
    cout<<endl;
    cout<<"\n     Artikel Ilmiah dengan Keyword Terkecil\n"<<endl;
    cout<<"     Judul        : "<<infoKar(toKar(Min)).judul<<endl;
    cout<<"     Penulis      : "<<infoKar(toKar(Min)).penulis<<endl;
    cout<<"     Publisher    : "<<infoKar(toKar(Min)).publisher<<endl;
    cout<<"     Tahun        : "<<infoKar(toKar(Min)).tahun<<endl;
    cout<<"     Abstark      : "<<infoKar(toKar(Min)).abstrak<<endl;
    cout<<"     Keyword      : ";
    Z = firstRel(C);
        while (Z != NULL) {
            if(infoKar(toKar(Z)).judul == infoKar(toKar(Max)).judul) {
                cout<<infoKey(toKey(Z));
                if(nextRel(Z)!= NULL){
                    cout<<" - ";
                }
            }
            Z=nextRel(Z);
        }
}

int jumlahrelasi(Relasi C, addressKar P){
    int jumlah = 0;
    addressRel Q = firstRel(C);
    while(Q!= NULL){
        if(toKar(Q)==P){
            jumlah++;
        }
        Q=nextRel(Q);
    }
    return jumlah;
}

addressRel searchRelasi(Relasi C, addressKar P, addressKey Q){
    addressRel R = firstRel(C);
    while(R!= NULL&&toKar(R)!=P&&toKey(R)!=Q){
        R = nextRel(R);
    }
    if(R!= NULL){
        return R;
    }
    else{
        return NULL;
    }
}

void deleteRelasi(Relasi &C, addressKar P, addressKey Q) {
    addressRel Z = firstRel(C);
    addressRel R;
    while(Z!=NULL&&(toKar(Z)!=P && toKey(Z)!=Q)){
        R=Z;
        Z=nextRel(Z);
    }
    if(Z!= NULL){
        if(Z==firstRel(C)){
            firstRel(C)=NULL;
        }
        else{
            nextRel(R)=nextRel(Z);
            nextRel(Z)=NULL;
        }
    }
    toKar(Z)=NULL;
    toKey(Z)==NULL;
}

void deleteKar(KaryaIlmiah &A, addressKar &P, Relasi C) {
    addressRel Q = searchKarRel(C,P);
    addressKey Z;
    if(Q!=NULL){
    while(Q!= NULL){
        Z = toKey(Q);
        deleteRelasi(C,P,Z);
        Q = searchKarRel(C,P);
    }
    }
    if(firstKar(A)==lastKar(A)){
        firstKar(A)=NULL;
        lastKar(A)=NULL;
    }
    else{
        prevKar(nextKar(P))=prevKar(P);
        nextKar(prevKar(P))=nextKar(P);
        if(P==lastKar(A)){
            lastKar(A)=prevKar(P);
        }
        if(P==firstKar(A)){
            firstKar(A)= nextKar(P);
        }
        prevKar(P)=NULL;
        nextKar(P)=NULL;
    }
}

void deleteKey(Keyword &B, addressKey &P, Relasi C){
    addressRel Q = searchKeyRel(C,P);
    addressKar Z;
    while(Q!= NULL){
        Z = toKar(Q);
        deleteRelasi(C,Z,P);
        Q = searchKeyRel(C,P);
    }
    if(firstKey(B)==lastKey(B)){
        firstKey(B)=NULL;
        lastKey(B)=NULL;
    }
    else{
        if(P==firstKey(B)){
            prevKey(nextKey(P))=NULL;
            firstKey(B)=nextKey(P);
            nextKey(P)=NULL;
        }
        else if(P==lastKey(B)){
            lastKey(B)=prevKey(P);
            nextKey(prevKey(P))=NULL;
            prevKey(P)=NULL;
        }
        else{
            prevKey(nextKey(P))=prevKey(P);
            nextKey(prevKey(P))=nextKey(P);
            prevKey(P)=NULL;
            nextKey(P)=NULL;
        }
    }
}
