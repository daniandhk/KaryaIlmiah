#include "Tubes.h"

using namespace std;

int main()
{
    int menu = 1;
    char submenu = 'Y';
    KaryaIlmiah A;
    Keyword B;
    Relasi C;
    buatListKar(A);
    buatListKey(B);
    buatListRel(C);
    addressKar P;
    addressKey Q;
    addressRel R;
    addressRel Z;
    infotype infoKar;

    infoKar.abstrak = "Belajar berhitung dengan mudah";
    infoKar.judul = "Matematika Dasar";
    infoKar.penulis = "Dani Andhika";
    infoKar.publisher = "PT. Telyu";
    infoKar.tahun = 2019;
    buatDataKar(infoKar,P);
    insertKar(A,P);

    string infoJudul;
    string infoKey;

    infoKey = "Berhitung";
    buatDataKey(infoKey,Q);
    insertFirstKey(B,Q);

    infoKey = "Berfikir";
    buatDataKey(infoKey,Q);
    insertFirstKey(B,Q);

    while(menu != 0) {
        system("CLS");
        cout<<"\n      DATA ARTIKEL ILMIAH\n"<<endl;
        cout<<"     1.  insert Karya Ilmiah"<<endl;
        cout<<"     2.  insert Keyword"<<endl;
        cout<<"     3.  Relasi Artikel Ilmiah ke Keyword"<<endl;
        cout<<"     4.  Relasi Keyword ke Artikel Ilmiah"<<endl;
        cout<<"     5.  Delete Karya Ilmiah"<<endl;
        cout<<"     6.  Delete Keyword"<<endl;
        cout<<"     7.  Tampilan Semua Data Artikel Ilmiah & Keyword"<<endl;
        cout<<"     8.  print Karya Ilmiah berdasarkan Keyword"<<endl;
        cout<<"     9.  print Keyword berdasarkan Judul"<<endl;
        cout<<"     10. print berdasarkan relasi"<<endl;
        cout<<"     11. print Bidang Kajian terbanyak"<<endl;
        cout<<"     12. Delete Relasi"<<endl;
        cout<<"     0.  Exit"<<endl;
        cout<<"     Pilihan: ";
        cin>>menu;
        while(cin.fail()){
            cin.clear();
            cin.ignore(10000,'\n');
            cout<<"     Pilihan: ";
            cin>>menu;
        }
        switch(menu) {
        case 1:
            submenu = ' ';
            while(submenu!= 'N') {
                system("CLS");
                cout<<"\n       Masukan Data Artikel\n"<<endl;
                cout<<"     Judul     : ";
                cin.ignore();
                getline(cin,infoKar.judul);
                while(duplicate(A,infoKar.judul)){
                    cout<<"     Maaf, judul yang sama sudah ada. Silahkan input ulang"<<endl;
                    cout<<"     Judul     : ";
                    //cin.ignore();
                    getline(cin,infoKar.judul);
                }
                cout<<"     Penulis   : ";
                //cin.ignore();
                getline(cin,infoKar.penulis);
                cout<<"     Publisher : ";
               // cin.ignore();
                getline(cin,infoKar.publisher);
                cout<<"     Tahun     : ";
                cin>>infoKar.tahun;
                while(infoKar.tahun>2020 ||infoKar.tahun<=0 || cin.fail()){
                    cout<<"\r     Tahun tidak tersedia"<<endl;
                    cout<<"     Tahun     : ";
                    cin.clear();
                    cin.ignore(10000,'\n');
                    cin>>infoKar.tahun;
                }
                cout<<"     Abstrak   : ";
                cin.ignore();
                getline(cin,infoKar.abstrak);
                cout<<endl;
                buatDataKar(infoKar,P);
                insertKar(A,P);
                cout<<"Ingin menambahkan lagi?(Y/N): ";
                cin>>submenu;
                cout<<endl;
            }
            break;
        case 2:
            submenu = ' ';
            while(submenu!= 'N'){
                system("CLS");
                cout<<"\n       Masukan Keyword\n"<<endl;
                cout<<"     Keyword     : ";
                cin>>infoKey;
                cin.ignore();
                buatDataKey(infoKey,Q);
                if(!duplicate(B,Q)){
                    insertFirstKey(B,Q);
                }
                else{
                    cout<<"Maaf, data sudah ada"<<endl;
                }
                cout<<"\nIngin menambahkan lagi?(Y/N): ";
                cin>>submenu;
                cout<<endl;
            }
            break;
        case 3:
            submenu = ' ';
            while(submenu!= 'N') {
                system("CLS");
                cout<<"\n       Relasi dari Judul\n"<<endl;

                cout<<"     ( Judul yang tersedia: ";
                if(!isEmptyKar(A)){
                    P = firstKar(A);
                    while(nextKar(P)!=firstKar(A)){
                        cout<<infoKar(P).judul<<" - ";
                        P = nextKar(P);
                        }
                    cout<<infoKar(P).judul<<" )"<<endl;
                }
                else{
                    cout<<" - "<<endl;
                }

                cout<<"     Judul       : ";
                cin.ignore();
                getline(cin,infoJudul);
                P = searchJudul(A,infoJudul);
                cout<<endl;

                cout<<"     ( Keyword yang tersedia: ";
                if(!isEmptyKey(B)){
                    Q = firstKey(B);
                    while(Q!=lastKey(B)){
                        cout<<infoKey(Q)<<" - ";
                        Q=nextKey(Q);
                        }
                    cout<<infoKey(Q)<<" )"<<endl;
                }
                else{
                    cout<<" - )"<<endl;
                }

                cout<<"     Keyword     : ";
                cin>>infoKey;
                Q = searchKeyword(B,infoKey);
                if(P != NULL && Q != NULL) {
                    if(searchRelasi(C,P,Q)==NULL){
                        buatRelasi(P,Q,R);
                        insertLastRelasi(C,R);
                        cout<<"\n Berhasil Merelasikan \n"<<endl;
                    }
                    else{
                        cout<<"\n Relasi sudah ada\n"<<endl;
                    }
                }
                else {
                    cout<<"\nJudul/Keyword tak ada\n"<<endl;
                }
                cout<<"Relasi Karya Ilmiah ke Keyword lagi?(Y/N): ";
                cin>>submenu;
                cout<<endl;
            }
            break;
        case 4:
            submenu = ' ';
            while(submenu!= 'N') {
                system("CLS");
                cout<<"\n       Relasi dari Keyword\n"<<endl;

                cout<<"     ( Keyword yang tersedia: ";
                if(!isEmptyKey(B)){
                    Q = firstKey(B);
                    while(Q!=lastKey(B)){
                        cout<<infoKey(Q)<<" - ";
                        Q=nextKey(Q);
                        }
                    cout<<infoKey(Q)<<" )"<<endl;
                }
                else{
                    cout<<" - )"<<endl;
                }

                cout<<"     Keyword       : ";
                cin>>infoKey;
                Q = searchKeyword(B,infoKey);
                cout<<endl;

                cout<<"     ( Judul yang tersedia: ";
                if(!isEmptyKar(A)){
                    P = firstKar(A);
                    while(nextKar(P)!=firstKar(A)){
                        cout<<infoKar(P).judul<<" - ";
                        P = nextKar(P);
                        }
                    cout<<infoKar(P).judul<<" )"<<endl;
                }
                else{
                    cout<<" - )"<<endl;
                }

                cout<<"     Judul         : ";
                cin.ignore();
                getline(cin,infoJudul);
                P = searchJudul(A,infoJudul);
                if(P != NULL && Q != NULL) {
                    if(searchRelasi(C,P,Q)==NULL){
                        buatRelasi(P,Q,R);
                        insertLastRelasi(C,R);
                        cout<<"\n Berhasil Merelasikan \n"<<endl;
                    }
                    else{
                        cout<<"\n Relasi sudah ada\n"<<endl;
                    }
                }
                else {
                    cout<<"\nKeyword/Judul tak ada\n"<<endl;
                }
                cout<<"Relasi Keyword ke Karya Ilmiah lagi?(Y/N): ";
                cin>>submenu;
                cout<<endl;
            }
            break;
        case 5:
            submenu = ' ';
            while(submenu!= 'N') {
                system("CLS");
                cout<<"\n       Hapus Karya Ilmiah\n"<<endl;

                cout<<"     ( Judul yang tersedia: ";
                if(!isEmptyKar(A)){
                    P = firstKar(A);
                    while(nextKar(P)!=firstKar(A)){
                        cout<<infoKar(P).judul<<" - ";
                        P = nextKar(P);
                        }
                    cout<<infoKar(P).judul<<" )"<<endl;
                }
                else{
                    cout<<" - )"<<endl;
                }

                cout<<"     Judul yg ingin di del: ";
                cin.ignore();
                getline(cin,infoJudul);
                P = searchJudul(A,infoJudul);
                if (P != NULL) {
                    deleteKar(A,P,C);
                    cout<<"deleted"<<endl;
                }
                else{
                    cout<<"Judul tak ada beb"<<endl;
                }
                cout<<"Hapus Karya Ilmiah lagi?(Y/N): ";
                cin>>submenu;
                cout<<endl;
            }
            break;
        case 6:
            submenu = ' ';
            while(submenu!= 'N') {
                system("CLS");
                cout<<"\n       Hapus Keyword\n"<<endl;

                cout<<"     ( Keyword yang tersedia: ";
                if(!isEmptyKey(B)){
                    Q = firstKey(B);
                    while(Q!=lastKey(B)){
                        cout<<infoKey(Q)<<" - ";
                        Q=nextKey(Q);
                        }
                    cout<<infoKey(Q)<<" )"<<endl;
                }
                else{
                    cout<<" - )"<<endl;
                }

                cout<<"     Keyword yg ingin di del: ";
                cin>>infoKey;
                Q = searchKeyword(B,infoKey);
                if (Q != NULL){
                    deleteKey(B,Q,C);
                    cout<<"deleted"<<endl;
                }
                else{
                    cout<<"Keyword tek ade"<<endl;
                }
                cout<<"Hapus Keyword lagi?(Y/N): ";
                cin>>submenu;
                cout<<endl;
            }
            break;
        case 7:
            submenu = ' ';
            while(submenu!= 'Y'){
                system("CLS");
                cout<<"\n       Data Artikel Ilmiah & Keyword\n"<<endl;
                cout<<"\n     Semua Data Artikel Ilmiah yang Tersedia : "<<endl;
                cout<<endl;
                printALLKar(A,C);
                cout<<"\n     Semua Data Keyword yang Tersedia : "<<endl;
                printALLKey(B);
                cout<<"\nKembali ke Menu Utama?(Y/N): ";
                cin>>submenu;
                cout<<endl;
            }
            break;
        case 8:
            submenu = ' ';
            while(submenu!= 'Y'){
                system("CLS");
                cout<<"\n       Print Karya Ilmiah berdasarkan Keyword\n"<<endl;

                cout<<"     ( Keyword yang tersedia: ";
                if(!isEmptyKey(B)){
                    Q = firstKey(B);
                    while(Q!=lastKey(B)){
                        cout<<infoKey(Q)<<" - ";
                        Q=nextKey(Q);
                        }
                    cout<<infoKey(Q)<<" )"<<endl;
                }
                else{
                    cout<<" - "<<endl;
                }

                cout<<"     Keyword yg ingin ditampilkan Karya Ilmiahnya: ";
                cin>>infoKey;
                Q = searchKeyword(B,infoKey);
                if(Q!= NULL){
                    cout<<endl;
                    printKey(C,B,infoKey);
                }
                else{
                    cout<<"\n   Keyword tak ada"<<endl;
                }
                cout<<"\nKembali ke Menu Utama?(Y/N): ";
                cin>>submenu;
                cout<<endl;
            }
            break;
        case 9:
            submenu = ' ';
            while(submenu!= 'Y'){
                system("CLS");
                cout<<"\n     Print Keyword berdasarkan Judul\n"<<endl;

                cout<<"     ( Judul yang tersedia: ";
                if(!isEmptyKar(A)){
                    P = firstKar(A);
                    while(nextKar(P)!=firstKar(A)){
                        cout<<infoKar(P).judul<<" - ";
                        P = nextKar(P);
                        }
                    cout<<infoKar(P).judul<<" )"<<endl;
                }
                else{
                    cout<<" - )"<<endl;
                }

                cout<<"     Judul yang ingin ditampilkan Keywordnya: ";
                cin.ignore();
                getline(cin,infoJudul);
                P = searchJudul(A,infoJudul);
                if(P != NULL){
                    cout<<endl;
                    printKar(C,A,infoJudul);
                }
                else{
                    cout<<"\n   Judul tidak ada"<<endl;
                }
                cout<<"\nKembali ke Menu Utama?(Y/N): ";
                cin>>submenu;
                cout<<endl;
            }
            break;
        case 10:
            system("CLS");
            if(firstRel(C)==NULL){
                printRel(A,B,C);
            }
            else{
                cout<<"\n       Semua Data Yang Berhasil Di Relasi\n"<<endl;
                printRel(A,B,C);
            }
            system("pause");
            cout<<endl;
            break;
        case 11:
            submenu = ' ';
            while(submenu!= 'Y'){
                system("CLS");
                printKeyTerbanyak(C);
                cout<<"\nKembali ke Menu Utama?(Y/N): ";
                cin>>submenu;
                cout<<endl;
            }
            break;
        case 12:
            submenu = ' ';
            while(submenu!= 'N') {
                system("CLS");
                cout<<"\n       Hapus Relasi\n"<<endl;

                cout<<"     Relasi yang tersedia: "<<endl;
                if(firstRel(C)!=NULL){
                    R = firstRel(C);
                    while(nextRel(R)!=NULL){
                        cout<<"     ( "<<infoKar(toKar(R)).judul<<": ";
                        Z = firstRel(C);
                        while(nextRel(Z)!=NULL){
                            if(toKar(Z)==toKar(R)){
                                cout<<infoKey(toKey(Z))<<" - ";
                            }
                            Z=nextRel(Z);
                        }
                        cout<<infoKey(toKey(Z))<<" )"<<endl;
                        P = nextKar(P);
                        }
                    cout<<"( "<<infoKar(toKar(R)).judul<<": ";
                    Z = firstRel(C);
                    while(nextRel(Z)!=NULL){
                        if(toKar(Z)==toKar(R)){
                            cout<<infoKey(toKey(Z))<<" - ";
                        }
                        Z=nextRel(Z);
                    }
                    cout<<infoKey(toKey(Z))<<" )"<<endl;
                }
                else{
                    cout<<"     ( - )"<<endl;
                }

                cout<<"     Judul: ";
                cin.ignore();
                getline(cin,infoJudul);
                cout<<"     Keyword: ";
                cin>>infoKey;
                R = searchRelasi(C,searchJudul(A,infoJudul),searchKeyword(B,infoKey));
                if (R != NULL){
                    deleteRelasi(C,P,Q);
                    cout<<"deleted"<<endl;
                }
                else{
                    cout<<"Relasi antara Judul dan Keyword tek ade"<<endl;
                }
                cout<<"Hapus Relasi lagi?(Y/N): ";
                cin>>submenu;
                cout<<endl;
            }
        }
    }
    return 0;
}
