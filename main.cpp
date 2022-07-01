//Final Project : Students Data Management
//Source Code : Marlo Duha
#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>
#include <istream>
#include <fstream>
#include <stdlib.h>
#include <string.h>

using namespace std;

string arr1[20],arr2[20],arr3[20],arr4[20],arr5[20];
int total = 0;
void login();
void registr();
void forgot();
void main1();
void header(){
    system("cls");
    system("color 75");
    cout<<"#============================================================================================#"<<endl;
    cout<<"|                                                                                            |"<<endl;
    cout<<"|          |------------------->PROGRAM MANAJEMEN DATA MAHASISWA<------------------|         |"<<endl;
    cout<<"|                                                                                            |"<<endl;
    cout<<"#=========================================================|UNIVERSITAS AMIKOM YOGYAKARTA|====#"<<endl;
}

//menu awal, menu untuk login dan register akun
int main()
{
    //menu awal, program
    header();
    cout<<"\n";
    cout<<"S E L A M A T - D A T A N G..."<<endl;
int choice;
    cout<<"\n1. MASUK"<<endl;
    cout<<"2. REGISTRASI"<<endl;
    cout<<"3. LUPA PASSWORD (atau) USERNAME"<<endl;
    cout<<"4. TUTUP PROGRAM"<<endl;
    cout<<"\nMasukan pilihan anda :";
    cin>>choice;
    cout<<endl;
    switch(choice){
        case 1:
            login();
            break;
        case 2:
            registr();
            break;
        case 3:
            forgot();
            break;
        case 4:
            system("cls");
            system("color 04");
            cout<<"#===============================#"<<endl;
            cout<<"|P R O G R A M - D I T U T U P!!|"<<endl;
            cout<<"#===============================#"<<endl;
            cout<<"\nTerimakasih telah menggunakan program ini\nProgram BY : Pak Ketua tercintaaa\n\n";
            getch();
            exit(0);
            system("cls");
            break;
        default:
            system("cls");
            system("color 06");
            cout<<"##############"<<endl;
            cout<<">PERINGATAN!!<"<<endl;
            cout<<"##############"<<endl;
            cout<<"\nOpss...input salah..."<<endl;
            cout<<"Tekan ENTER untuk kembali ke menu..."<<endl;
            getch();
            system("cls");
            main();
    }
    cin.get();
    return 0;
}

void login()
{
    int count;
    string user,pass,u,p;
    header();
    cout<<"\n                                          @*******@"<<endl;
    cout<<"                                          : LOGIN :"<<endl;
    cout<<"                                          @*******@"<<endl;
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
        if(count==1){
            for(int i = 0; i<=100; i++){
                cout<<"#==================#"<<endl;
                cout<<"| <BERHASIL MASUK> |"<<endl;
                cout<<"#==================#"<<endl;
                cout<<"Hai... "<<user<<endl;
                cout<<"\nMemuat data anda..."<<i<<"%"<<endl;
                system("cls");
            }
            cin.get();
            main1();
        }else{
            system("cls");
            system("color 06");
            cout<<"##############"<<endl;
            cout<<">PERINGATAN!!<"<<endl;
            cout<<"##############"<<endl;
            cout<<"\nOpss..."<<endl;
            cout<<"\n<GAGAL MASUK> Silahkan periksa kembali username dan password yang anda masukan...\n";
            cout<<"\nTekan ENTER untuk kembali ke menu..."<<endl;
            getch();
            system("cls");
            main();
        }
}

void registr()
{
    string reguser,regpass,ru,rp;
    header();
    cout<<"\n                                         @************@"<<endl;
    cout<<"                                         : REGISTRASI :"<<endl;
    cout<<"                                         @************@"<<endl;
    cout<<"Masukan username :";
    cin>>reguser;
    cout<<"\nMasukan password :";
    cin>>regpass;
    ofstream reg("pass&user.txt",ios::app);
    reg<<reguser<<' '<<regpass<<endl;
    system("cls");
    cout<<"\nллллллллллллллллллллллллл"<<endl;
    cout<<"л <Registrasi Berhasil> л"<<endl;
    cout<<"ллллллллллллллллллллллллл"<<endl;
    getch();
    main();
}

void forgot()
{
    int ch;
    header();
    cout<<"\n                                         ллллллллллллл"<<endl;
    cout<<"                                         л CARI AKUN л"<<endl;
    cout<<"                                         ллллллллллллл"<<endl;
    cout<<"Anda lupa dengan akun anda? kami disini untuk membantu\n";
    cout<<"\n1. Cari akun dengan username"<<endl;
    cout<<"2. Cari akun dengan password"<<endl;
    cout<<"3. Menu Utama"<<endl;
    cout<<"\nMasukan pilihan anda :";
    cin>>ch;
    switch(ch){
        case 1:{
            int count=0;
            string searchuser,su,sp;
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
                    cout<<"\n\nSelamat, akun anda ditemukan...\n";
                    cout<<"\nPassword anda adalah "<<sp;
                    cin.get();
                    cin.get();
                    system("cls");
                    main();
            }else{
                cout<<"\nMaaf, Akun anda tidak ditemukan...\n";
                cout<<"\nSilahkan menghubungi admin sistem untuk info lebih lanjut... \n";
                cin.get();
                cin.get();
                main();
            }
            break;
        }
        case 2:{
            int count=0;
            string searchpass,su2,sp2;
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
                    cout<<"\nSelamat, password anda ditemukan...\n";
                    cout<<"\nAkun anda adalah : "<<su2;
                    cin.get();
                    cin.get();
                    system("cls");
                    main();
            }else{
                cout<<"\nMaaf, Akun anda tidak ditemukan...\n";
                cout<<"\nSilahkan menghubungi admin sistem untuk info lebih lanjut... \n";
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
            cout<<"##############"<<endl;
            cout<<">PERINGATAN!!<"<<endl;
            cout<<"##############"<<endl;
            cout<<"\nOpss...input salah..."<<endl;
            cout<<"Tekan ENTER untuk kembali ke menu..."<<endl;
            getch();
            system("cls");
            forgot();
        }
}
//menu input data mahasiswa
void inputdata()
{
    int ch=0;
    header();
    cout<<"\n                                         лллллллллллллл"<<endl;
    cout<<"                                        л TAMBAH DATA л"<<endl;
    cout<<"                                        ллллллллллллллл"<<endl;
    cout<<"\nBerapa banyak jumlah data yang ingin di tambah??"<<endl;
    cin>>ch;
    if(total==0){
    total=ch+total;
    for(int i=0;i<ch;i++){
        cout<<"\nMasukan data mahasiswa: "<<i+1<<endl<<endl;
        cout<<"Nama     : ";
        cin>>arr1[i];
        cout<<"NIM      : ";
        cin>>arr2[i];
        cout<<"Kelas    : ";
        cin>>arr3[i];
        cout<<"Prodi    : ";
        cin>>arr4[i];
        cout<<"Nomor Hp : ";
        cin>>arr5[i];
    }
    }else{
        for(int i=total;i<ch+total;i++){
        cout<<"\nMasukan data mahasiswa: "<<i+1<<endl<<endl;
        cout<<"Nama     : ";
        cin>>arr1[i];
        cout<<"NIM      : ";
        cin>>arr2[i];
        cout<<"Kelas    : ";
        cin>>arr3[i];
        cout<<"Prodi    : ";
        cin>>arr4[i];
        cout<<"Nomor Hp : ";
        cin>>arr5[i];
        }
        total=ch+total;
    }
}
//menu menampilkan data mahasiswa
void tampilkandata()
{
    header();
    cout<<"\n                                      лллллллллллллллллл"<<endl;
    cout<<"                                      л TAMPILKAN DATA л"<<endl;
    cout<<"                                      лллллллллллллллллл"<<endl;
	if(total==0){
		cout<<"\nBelum ada Data yang ditambahkan..."<<endl;
	}else{
		for(int i=0;i<total;i++){
	    		cout<<"л Data Mahasiswa л "<<i+1<<endl<<endl;
	    		cout<<"Nama     : "<<arr1[i]<<endl;
	    		cout<<"NIM      : "<<arr2[i]<<endl;
	    		cout<<"Kelas    : "<<arr3[i]<<endl;
	    		cout<<"Prodi    : "<<arr4[i]<<endl;
	    		cout<<"Nomor Hp : "<<arr5[i]<<endl;
	    	    }
	    	}
    getch();
}
//menu mencari data mahasiswa
void caridata()
{
    header();
    cout<<"\n                                        ллллллллллллл"<<endl;
    cout<<"                                        л CARI DATA л"<<endl;
    cout<<"                                        ллллллллллллл"<<endl;
	if(total == 0){
		cout<<"\nBelum ada Data yang ditambahkan..."<<endl;
	}else{
	string nim;
        cout<<"Masuka NIM yang akan dicari :";
        cin>>nim;
        for(int i = 0; i < total; i++){
            if(nim == arr2[i]){
                cout<<"Nama     : "<<arr1[i]<<endl;
	    		cout<<"NIM      : "<<arr2[i]<<endl;
	    		cout<<"Kelas    : "<<arr3[i]<<endl;
	    		cout<<"Prodi    : "<<arr4[i]<<endl;
	    		cout<<"Nomor Hp : "<<arr5[i]<<endl;
            }
        }
    }
    getch();
}
//menu memperbaharui data mahasiswa
void updatedata()
{
    header();
    cout<<"\n                                       ллллллллллллллл"<<endl;
    cout<<"                                       л UPDATE DATA л"<<endl;
    cout<<"                                       ллллллллллллллл"<<endl;
	if(total==0){
		cout<<"\nBelum ada Data yang ditambahkan..."<<endl;
	}else{
		string nim;
        cout<<"Masukan NIM mahasiswa yang ingin di update datanya: ";
        cin>>nim;
        for(int i=0;i<total;i++){
            if(nim==arr2[i]){
                cout<<"\nData lama"<<endl<<endl;
                cout<<"л Data Mahasiswa л "<<i+1<<endl<<endl;
                cout<<"Nama     : "<<arr1[i]<<endl;
                cout<<"NIM      : "<<arr2[i]<<endl;
                cout<<"Kelas    : "<<arr3[i]<<endl;
                cout<<"Prodi    : "<<arr4[i]<<endl;
                cout<<"Nomor Hp : "<<arr5[i]<<endl;
                cout<<"\nMasukan data baru: "<<endl;
                cout<<"Nama     : ";
                cin>>arr1[i];
                cout<<"NIM      : ";
                cin>>arr2[i];
                cout<<"Kelas    : ";
                cin>>arr3[i];
                cout<<"Prodi    : ";
                cin>>arr4[i];
                cout<<"Nomor Hp : ";
                cin>>arr5[i];
            }
        }
    }
    getch();
}
//menu menghapus data mahasiswa
void hapusdata()
{
    header();
    cout<<"\n                                        лллллллллллллл"<<endl;
    cout<<"                                        л HAPUS DATA л"<<endl;
    cout<<"                                        лллллллллллллл"<<endl;
	if(total==0){
		cout<<"\nBelum ada Data yang ditambahkan..."<<endl;
	}else{
    int a;
        cout<<"\nMenu: "<<endl;
        cout<<"\n1. Hapus seluruh data"<<endl;
        cout<<"2. Hapus 1 data"<<endl;
        cin>>a;
        if(a==1){
            total=0;
            cout<<"Seluruh data telah dihapus..!!"<<endl;
        }else if(a==2){
            string nim;
            cout<<"Masukan NIM mahasiswa yang ingin dihapus data nya: ";
            cin>>nim;
            for(int i=0;i<total;i++){
                if(nim==arr2[i]){
                    for(int j=i;j<total;j++){
						arr1[j]=arr1[j+1];
						arr2[j]=arr2[j+1];
					    arr3[j]=arr3[j+1];
						arr4[j]=arr4[j+1];
						arr5[j]=arr5[j+1];
                    }
					total--;
					cout<<"Data mahasiswa berhasil dihapus..."<<endl;
					}
				}
        }else{
            system("cls");
            system("color 06");
            cout<<"##############"<<endl;
            cout<<">PERINGATAN!!<"<<endl;
            cout<<"##############"<<endl;
            cout<<"\nOpss...input salah..."<<endl;
            cout<<"Tekan ENTER untuk kembali ke menu..."<<endl;
            getch();
            system("cls");
        }
    }
    getch();
}
//menu main2, menu manajemen nilai
void main2()
{
int pilihan;
    while(true)
    {
    header();
    cout<<"\n                                         лллллллллллл"<<endl;
    cout<<"                                         л DATABASE л"<<endl;
    cout<<"                                         лллллллллллл"<<endl;
    cout<<"\nMENU: "<<endl;
    }
}
//menu main1, menu manajemen data
void main1()
{
int value;
    //menu manajemen data, menu untuk mengakses data mahasiswa.
	while(true)
	{
    header();
    cout<<"\n                                         лллллллллллл"<<endl;
    cout<<"                                         л DATABASE л"<<endl;
    cout<<"                                         лллллллллллл"<<endl;
    cout<<"\nMENU: "<<endl;
	cout<<"1. MASUKAN DATA BARU"<<endl;
	cout<<"2. TAMPILKAN DATA MAHASISWA"<<endl;
	cout<<"3. CARI DATA MAHASISWA"<<endl;
	cout<<"4. UPDATE DATA MAHASISWA"<<endl;
	cout<<"5. HAPUS DATA"<<endl;
	cout<<"6. TUTUP PROGRAM"<<endl;
    cout<<"\nMasukan pilihan anda :";
	cin>>value;
	switch(value)
	{
		case 1:
			inputdata();
			system("cls");
			break;
		case 2:
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
			system("cls");
            system("color 04");
            cout<<"лВлВлВлВлВлВлВлВлВлВлВлВлВлВлВлВл"<<endl;
            cout<<"ВP R O G R A M - D I T U T U P!!В"<<endl;
            cout<<"лВлВлВлВлВлВлВлВлВлВлВлВлВлВлВлВл"<<endl;
            cout<<"\nTerimakasih telah menggunakan program ini\nProgram BY : Pak Ketua tercintaaa\n\n";
            getch();
            exit(0);
			system("cls");
			break;
		default:
		    system("cls");
            system("color 06");
            cout<<"##############"<<endl;
            cout<<">PERINGATAN!!<"<<endl;
            cout<<"##############"<<endl;
            cout<<"\nOpss...input salah..."<<endl;
            cout<<"Tekan ENTER untuk kembali ke menu..."<<endl;
            getch();
            system("cls");
			break;
    }
    }
}
