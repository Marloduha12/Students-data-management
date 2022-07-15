//Final Project : Students Data Management
//Source Code   : Marlo Duha
#include <iostream>
#include <conio.h>
#include <string>
#include <istream>
#include <fstream>

using namespace std;

struct data
{
    string nama[10];
    int nim[10];
    string kelas[10];
    int nilai[10];
};

data mhs;
int total = 0;
void masuk();
void registrasi();
void lupaPassword();
void dataMahasiswa();
void header(){
    system("cls");
    system("color 56");
    cout<<"=============================================================================================="<<endl;
    cout<<"                                PROGRAM MANAJEMEN DATA MAHASISWA                              "<<endl;
    cout<<"                                 UNIVERSITAS AMIKOM YOGYAKARTA                                "<<endl;
    cout<<"=============================================================================================="<<endl;
}

//menu awal, menu untuk login dan register akun
int main()
{
    //menu awal, program
    header();
    cout<<"S E L A M A T - D A T A N G..."<<endl;
    cout<<"=============================================================================================="<<endl;

int pilihan;
    cout<<"MENU :"<<endl;
    cout<<"=============================================================================================="<<endl;
    cout<<"1. MASUK"<<endl;
    cout<<"2. REGISTRASI"<<endl;
    cout<<"3. LUPA PASSWORD (atau) USERNAME"<<endl;
    cout<<"4. TUTUP PROGRAM"<<endl;
    cout<<"=============================================================================================="<<endl;
    cout<<"Masukan pilihan anda :";
    cin>>pilihan;
    cout<<endl;
    switch(pilihan){
        case 1:
            masuk();
            break;
        case 2:
            registrasi();
            break;
        case 3:
            lupaPassword();
            break;
        case 4:
            system("cls");
            system("color 04");
            cout<<"=============================================================================================="<<endl;
            cout<<"                                  P R O G R A M - D I T U T U P!!                             "<<endl;
            cout<<"=============================================================================================="<<endl;
            cout<<"\nTerimakasih telah menggunakan program ini\nProgram BY : Marlo Duha\n\n";
            getch();
            exit(0);
            system("cls");
            break;
        default:
            system("cls");
            system("color 06");
            cout<<"                                        ================"<<endl;
            cout<<"                                        > PERINGATAN!! <"<<endl;
            cout<<"                                        ================"<<endl;
            cout<<"\nOpss...input salah..."<<endl;
            cout<<"Tekan ENTER untuk kembali ke menu..."<<endl;
            getch();
            system("cls");
            main();
    }
    cin.get();
    return 0;
}

void masuk()
{
    int count;
    string user,pass,u,p;
    header();
    cout<<"\n                                          ========="<<endl;
    cout<<"                                          : LOGIN :"<<endl;
    cout<<"                                          ========="<<endl;
    cout<<"\nSilahkan masukan username dan password anda..."<<endl;
    cout<<"USERNAME :";
    cin>>user;
    cout<<"PASSWORD :";
    cin>>pass;
        ifstream input("pass&user.txt");
        while(input>>u>>p){
            if(u==user && p==pass){
                count=1;
                system("cls");
            }
        }
        input.close();
        if(count == 1){
            for(int i = 0; i <= 100; i++){
                cout<<"                                     ===================="<<endl;
                cout<<"                                     | <BERHASIL MASUK> |"<<endl;
                cout<<"                                     ===================="<<endl;
                cout<<"Hai... "<<user<<endl;
                cout<<"\nMemuat data anda..."<<i<<"%"<<endl;
                system("cls");
            }
            cin.get();
            dataMahasiswa();
        }else{
            system("cls");
            system("color 06");
            cout<<"                                        ================"<<endl;
            cout<<"                                        > PERINGATAN!! <"<<endl;
            cout<<"                                        ================"<<endl;
            cout<<"\nOpss..."<<endl;
            cout<<"\n<GAGAL MASUK> Silahkan periksa kembali username dan password yang anda masukan...\n";
            cout<<"\nTekan ENTER untuk kembali ke menu..."<<endl;
            getch();
            system("cls");
            main();
        }
}

void registrasi()
{
    string reguser,regpass,ru,rp;
    header();
    cout<<"\n                                         =============="<<endl;
    cout<<"                                         : REGISTRASI :"<<endl;
    cout<<"                                         =============="<<endl;
    cout<<"Masukan username :";
    cin>>reguser;
    cout<<"\nMasukan password :";
    cin>>regpass;
    ofstream reg("pass&user.txt",ios::app);
    reg<<reguser<<' '<<regpass<<endl;
    system("cls");
    cout<<"=============================================================================================="<<endl;
    cout<<"                                       REGISTRASI BERHASIL!!                                  "<<endl;
    cout<<"=============================================================================================="<<endl;
    getch();
    main();
}

void lupaPassword()
{
    int pilihaN;
    header();
    cout<<"\n                                         ============="<<endl;
    cout<<"                                         : CARI AKUN :"<<endl;
    cout<<"                                         ============="<<endl;
    cout<<"Anda lupa dengan akun anda? kami disini untuk membantu\n";
    cout<<"\n1. Cari akun dengan username"<<endl;
    cout<<"2. Cari akun dengan password"<<endl;
    cout<<"3. Menu Utama"<<endl;
    cout<<"\nMasukan pilihan anda :";
    cin>>pilihaN;
    switch(pilihaN){
        case 1:{
            int count=0;
            string searchuser,su,sp;
            cout<<"=============================================================================================="<<endl;
            cout<<"\nMasukan username yang anda ingat :";
            cin>>searchuser;
            ifstream searchu("pass&user.txt");
            while(searchu>>su>>sp){
                if(su==searchuser){
                    count=1;
                }
            }
                searchu.close();
                if(count==1){
                    cout<<"=============================================================================================="<<endl;
                    cout<<"\n\nSelamat, akun anda ditemukan...\n";
                    cout<<"=============================================================================================="<<endl;
                    cout<<"\nPassword anda adalah "<<sp;
                    cin.get();
                    cin.get();
                    system("cls");
                    main();
            }else{
                cout<<"=============================================================================================="<<endl;
                cout<<"\nMaaf, Akun anda tidak ditemukan...\n";
                cout<<"\nSilahkan menghubungi admin sistem untuk informasi lebih lanjut... \n";
                cout<<"=============================================================================================="<<endl;
                cin.get();
                cin.get();
                main();
            }
            break;
        }
        case 2:{
            int count=0;
            string searchpass,su2,sp2;
            cout<<"=============================================================================================="<<endl;
            cout<<"\nMasukan password yang anda ingat :";
            cin>>searchpass;
            ifstream searchp("pass&user.txt");
            while(searchp>>su2>>sp2){
                if(sp2==searchpass){
                    count=1;
                }
            }
                searchp.close();
                if(count==1){
                    cout<<"=============================================================================================="<<endl;
                    cout<<"\nSelamat, password anda ditemukan...\n";
                    cout<<"\nAkun anda adalah : "<<su2;
                    cout<<"=============================================================================================="<<endl;
                    cin.get();
                    cin.get();
                    system("cls");
                    main();
            }else{
                cout<<"=============================================================================================="<<endl;
                cout<<"\nMaaf, Akun anda tidak ditemukan...\n";
                cout<<"\nSilahkan menghubungi admin sistem untuk informasi lebih lanjut... \n";
                cout<<"=============================================================================================="<<endl;
                cin.get();
                cin.get();
                main();
            }
            break;
                }
        case 3:{
            cin.get();
            main();
        }
        default:
            system("cls");
            system("color 06");
            cout<<"                                        ================"<<endl;
            cout<<"                                        > PERINGATAN!! <"<<endl;
            cout<<"                                        ================"<<endl;
            cout<<"\nOpss...input salah..."<<endl;
            cout<<"Tekan ENTER untuk kembali ke menu..."<<endl;
            getch();
            system("cls");
            lupaPassword();
        }
}
//menu input data mahasiswa
void inputdata()
{
    int ch = 0;
    header();
    cout<<"\n                                        ==============="<<endl;
    cout<<"                                        > TAMBAH DATA <"<<endl;
    cout<<"                                        ==============="<<endl;
    cout<<"\nBerapa banyak jumlah data yang ingin di tambah??";
    cin>>ch;
    if(total==0){
    total=ch+total;
    for(int i=0;i<ch;i++){
        cout<<"\nMasukan data mahasiswa: "<<i+1<<endl<<endl;
        cout<<"Nama     : ";
        cin>>mhs.nama[i];
        cout<<"NIM      : ";
        cin>>mhs.nim[i];
        cout<<"Kelas    : ";
        cin>>mhs.kelas[i];
    }
    }else{
        for(int i=total;i<ch+total;i++){
        cout<<"\nMasukan data mahasiswa: "<<i+1<<endl<<endl;
        cout<<"Nama     : ";
        cin>>mhs.nama[i];
        cout<<"NIM      : ";
        cin>>mhs.nim[i];
        cout<<"Kelas    : ";
        cin>>mhs.kelas[i];
        }
        total=ch+total;
    }
}
//input nilai mahasiswa
void nilai()
{
    int ch = 0;
    header();
    cout<<"\n                                        ==============="<<endl;
    cout<<"                                        > INPUT NILAI <"<<endl;
    cout<<"                                        ==============="<<endl;
    if(total == 0){
		cout<<"\nBelum ada Data yang ditambahkan..."<<endl;
	}else{
    cout<<"========================================"<<endl;
    cout<<"NAMA" <<"    "<<"NIM "<<"    "<<"NILAI "<<endl;
    for (int i=0; i<ch+total;i++)
    {

        cout<<mhs.nama[i]<<"   "<<mhs.nim[i]<<"    ";
        cin>>mhs.nilai[i];
    }
    cout<<"========================================"<<endl;
    cout<<endl<<endl;
	}
	getch();
}

void ceknilai()
{
    int ch = 0;
    header();
    cout<<"\n                                       ================"<<endl;
    cout<<"                                       > DAFTAR NILAI <"<<endl;
    cout<<"                                       ================"<<endl;
    if(total == 0){
        cout<<"\nBelum ada Data yang ditambahkan..."<<endl;
	}else{
	    cout<<"========================================"<<endl;
        cout<<"NAMA" <<"    "<<" NIM"<<"   "<<"GRADE "<<endl;
        for (int i=0; i<ch+total;i++){
            cout<<mhs.nama[i]<<"    "<<mhs.nim[i]<<"    ";
            if (mhs.nilai[i] >= 90){
            cout<<"A"<<endl;
            }
            if (mhs.nilai[i] >= 80 && mhs.nilai[i] < 90){
            cout<<"B"<<endl;
            }
            if (mhs.nilai[i] >= 70 &&mhs.nilai[i] < 80){
            cout<<"C"<<endl;
            }
            if (mhs.nilai[i] >= 60 &&mhs.nilai[i] < 70){
            cout<<"D"<<endl;
            }
            if (mhs.nilai[i] >= 50 &&mhs.nilai[i] < 60){
            cout<<"E"<<endl;
            }
        }
        cout<<"========================================"<<endl;
	}
    getch();
    system("cls");
}

//menu menampilkan data mahasiswa
void tampilkandata()
{
    int ch = 0;
    header();
    cout<<"\n                                      =================="<<endl;
    cout<<"                                      > TAMPILKAN DATA <"<<endl;
    cout<<"                                      =================="<<endl;
	if(total == 0){
		cout<<"\nBelum ada Data yang ditambahkan..."<<endl;
	}else{
		for(int i=0;i<ch+total;i++){\
                cout<<"\n======================="<<endl;
	    		cout<<"# Data Mahasiswa # No."<<i+1<<endl;
	    		cout<<"======================="<<endl;
	    		cout<<"Nama     : "<<mhs.nama[i]<<endl;
	    		cout<<"NIM      : "<<mhs.nim[i]<<endl;
	    		cout<<"Kelas    : "<<mhs.kelas[i]<<endl;
                cout<<"======================="<<endl;
	    	    }
	    	    cout<<endl;
	    	}
    getch();
}
//menu mencari data mahasiswa
void caridata()
{
    header();
    cout<<"\n                                        ============="<<endl;
    cout<<"                                        > CARI DATA <"<<endl;
    cout<<"                                        ============="<<endl;
	if(total == 0){
		cout<<"\nBelum ada Data yang ditambahkan..."<<endl;
	}else{
	int nim;
        cout<<"Masuka NIM yang akan dicari :";
        cin>>nim;
        for(int i = 0; i < total; i++){
            if(nim == mhs.nim[i]){
                cout<<"======================="<<endl;
	    		cout<<"Nama     : "<<mhs.nama[i]<<endl;
	    		cout<<"NIM      : "<<mhs.nim[i]<<endl;
	    		cout<<"Kelas    : "<<mhs.kelas[i]<<endl;
                cout<<"======================="<<endl;
            }
        }
    }
    getch();
}
//menu memperbaharui data mahasiswa
void updatedata()
{
    header();
    cout<<"\n                                       ==============="<<endl;
    cout<<"                                       > UPDATE DATA <"<<endl;
    cout<<"                                       ==============="<<endl;
	if(total==0){
		cout<<"\nBelum ada Data yang ditambahkan..."<<endl;
	}else{
		int nim;
        cout<<"Masukan NIM mahasiswa yang ingin di update datanya: ";
        cin>>nim;
        for(int i=0;i<total;i++){
            if(nim==mhs.nim[i]){
                cout<<"\nData lama"<<endl;
                cout<<"======================="<<endl;
	    		cout<<"# Data Mahasiswa # No."<<i+1<<endl;
	    		cout<<"======================="<<endl;
	    		cout<<"Nama     : "<<mhs.nama[i]<<endl;
	    		cout<<"NIM      : "<<mhs.nim[i]<<endl;
	    		cout<<"Kelas    : "<<mhs.kelas[i]<<endl;
                cout<<"======================="<<endl;
                cout<<"\nMasukan data baru: "<<endl;
                cout<<"======================="<<endl;
                cout<<"Nama     : ";
                cin>>mhs.nama[i];
                cout<<"NIM      : ";
                cin>>mhs.nim[i];
                cout<<"Kelas    : ";
                cin>>mhs.kelas[i];
            }
        }
    }
    getch();
}
//menu menghapus data mahasiswa
void hapusdata()
{
    header();
    cout<<"\n                                        =============="<<endl;
    cout<<"                                        > HAPUS DATA <"<<endl;
    cout<<"                                        =============="<<endl;
	if(total==0){
		cout<<"\nBelum ada Data yang ditambahkan..."<<endl;
	}else{
    int a;
        cout<<"\nMenu: "<<endl;
        cout<<"======================="<<endl;
        cout<<"1. Hapus seluruh data"<<endl;
        cout<<"2. Hapus 1 data"<<endl;
        cout<<"3. Kembali Ke menu"<<endl;
        cout<<"======================="<<endl;
        cin>>a;
        if(a==1){
            system("cls");
            system("color 06");
            cout<<"                                        ================"<<endl;
            cout<<"                                        > PERINGATAN!! <"<<endl;
            cout<<"                                        ================"<<endl;
            cout<<"\n(seluruh data tidak dapat di pulihkan setelah anda mengapus nya!!)"<<endl;
                total=0;
                cout<<"Seluruh data telah dihapus..!!"<<endl;
                cout<<"\nTekan ENTER untuk kembali ke menu..."<<endl;
        }else if(a==2){
            int nim;
            system("cls");
            system("color 06");
            cout<<"                                        ================"<<endl;
            cout<<"                                        > PERINGATAN!! <"<<endl;
            cout<<"                                        ================"<<endl;
            cout<<"\n(Data tidak dapat di pulihkan setelah anda mengapus nya!!"<<endl;
                cout<<"Masukan NIM mahasiswa yang ingin dihapus data nya: ";
                cin>>nim;
                for(int i=0;i<total;i++){
                    if(nim==mhs.nim[i]){
                        for(int j=i;j<total;j++){
                            cout<<"======================="<<endl;
                            cout<<"Nama     : "<<mhs.nama[i]<<endl;
                            cout<<"NIM      : "<<mhs.nim[i]<<endl;
                            cout<<"Kelas    : "<<mhs.kelas[i]<<endl;
                            cout<<"======================="<<endl;
                        }
                        total--;
                        cout<<"Data mahasiswa berhasil dihapus..."<<endl;
					}
				}
                cout<<"\nTekan ENTER untuk kembali ke menu..."<<endl;
        }else if(a==3){
            header();
            cout<<"Tekan ENTER untuk kembali ke menu..."<<endl;
            getch();
            system("cls");
        }else{
            system("cls");
            system("color 06");
            cout<<"                                        ================"<<endl;
            cout<<"                                        > PERINGATAN!! <"<<endl;
            cout<<"                                        ================"<<endl;
            cout<<"\nOpss...input salah..."<<endl;
            cout<<"Tekan ENTER untuk kembali ke menu..."<<endl;
            getch();
            system("cls");
            hapusdata();
        }
    }
    getch();
}

//sorting data mahasiswa
void sortData()
{
    int ch = 0;
    if(total==0){
		cout<<"\nBelum ada Data yang ditambahkan..."<<endl;
	}else{
    for(int i = 0; i < ch+total; i++)
    {
        for(int j = 0; j < ch+total - 1; j++)
        {
            if(mhs.nama[j].compare(mhs.nama[j+1])>0)
            {
            swap(mhs.nama[j], mhs.nama[j+1]);
            swap(mhs.nim[j], mhs.nim[j+1]);
            swap(mhs.kelas[j], mhs.kelas[j+1]);
            swap(mhs.nilai[j], mhs.nilai[j+1]);
            }
        }
    }
	}
}

//menu main1, menu manajemen data
void dataMahasiswa()
{
int value;
int ch;
    //menu manajemen data, menu untuk mengakses data mahasiswa.
	while(true)
	{
    header();
    cout<<"\n                                         ============"<<endl;
    cout<<"                                         : DATABASE :"<<endl;
    cout<<"                                         ============"<<endl;
    cout<<"\nMENU: "<<endl;
    cout<<"=============================================================================================="<<endl;
	cout<<"1. MASUKAN DATA BARU"<<endl;
	cout<<"2. TAMPILKAN DATA MAHASISWA"<<endl;
	cout<<"3. CARI DATA MAHASISWA"<<endl;
	cout<<"4. UPDATE DATA MAHASISWA"<<endl;
	cout<<"5. HAPUS DATA"<<endl;
	cout<<"6. INPUT NILAI MAHASISWA"<<endl;
	cout<<"7. DAFTAR NILAI MAHASISWA"<<endl;
	cout<<"8. TUTUP PROGRAM"<<endl;
	cout<<"=============================================================================================="<<endl;
    cout<<"Masukan pilihan anda :";
	cin>>value;
	switch(value)
	{
		case 1:
			inputdata();
			system("cls");
			break;
		case 2:
		    sortData();
			tampilkandata();
			system("cls");
			break;
		case 3:
			caridata();
			system("cls");
			break;
		case 4:
			updatedata();
			system("cls");
			break;
		case 5:
			hapusdata();
			system("cls");
			break;
        case 6:
            nilai();
			system("cls");
			break;
        case 7:
            ceknilai();
			system("cls");
			break;
		case 8:
			system("cls");
            system("color 04");
            cout<<"=============================================================================================="<<endl;
            cout<<"                                  P R O G R A M - D I T U T U P!!                             "<<endl;
            cout<<"=============================================================================================="<<endl;
            cout<<"\nTerimakasih telah menggunakan program ini\nProgram BY : Marlo Duha\n\n";
            getch();
            exit(0);
			system("cls");
			break;
		default:
		    system("cls");
            system("color 06");
            cout<<"                                        ================"<<endl;
            cout<<"                                        > PERINGATAN!! <"<<endl;
            cout<<"                                        ================"<<endl;
            cout<<"\nOpss...input salah..."<<endl;
            cout<<"Tekan ENTER untuk kembali ke menu..."<<endl;
            getch();
            system("cls");
            dataMahasiswa();
    }
    }
}
