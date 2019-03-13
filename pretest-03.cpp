/**
 * Author   : Prayudha Adhitia Libramawan
 * NPM      : 140810180008
 * Kelas    : B
 * Tanggal  : 13-03-2019
 * Deskripsi: Program ini berisi input data mahasiswa yang dapat disorting lalu dicetak
*/
#include<iostream>
#include <string.h>
using namespace std;

struct r_mhs{
	char npm[14];
	char nama[50];
	float ipk;
};

typedef r_mhs larikMhs[30];

void banyakData(int& n);
void inputMhs(larikMhs& mhs, int& n);
void sortNPM(larikMhs& mhs, int& n);
void cetakMhs(larikMhs mhs, int& n);

int main()
{
	larikMhs mhs;
	int n;
	banyakData(n);
	inputMhs(mhs, n);
	sortNPM(mhs, n);
	cetakMhs(mhs, n);
}

void banyakData(int& n)
{
	cout<<"Masukkan Jumlah Data	: ";cin>>n;
}

void inputMhs(larikMhs& mhs, int& n)
{
	system("cls");
	for(int i=0;i<n;i++)
	{
		cout<<"========"<<"Masukkan Input Data Mahasiswa ke-"<<i+1<<"========"<<endl;
		cout<<"Masukkan NPM Mahasiswa	: ";cin>>mhs[i].npm;
		cout<<"Masukkan Nama Mahasiswa	: ";cin.ignore(); cin.getline(mhs[i].nama,50);
		cout<<"Masukkan IPK Mahasiswa	: ";cin>>mhs[i].ipk;
		cout<<endl;
	}
}

void sortNPM(larikMhs& mhs, int& n)
{
	int index;  
	r_mhs temp;
  	for(int i=0; i<n; i++)
	{
		for(int j=i; j<n-1; j++)
		{
			index=strcmp(mhs[i].npm, mhs[j+1].npm);
			if(index>0)
			{
				temp=mhs[i];
				mhs[i]=mhs[j+1];
				mhs[j+1]=temp;
			}
		}  
 	}  
}

void cetakMhs(larikMhs mhs, int& n)
{
	cout<<"**************************************************"<<endl;
	cout<<"DATA MAHASISWA YANG TELAH DISORTING\n\n";
	for(int i=0;i<n;i++)
	{
		cout<<"NPM Mahasiswa	: "<<mhs[i].npm<<endl;
		cout<<"Nama Mahasiswa	: "<<mhs[i].nama<<endl;
		cout<<"IPK Mahasiswa	: "<<mhs[i].ipk<<endl;
		cout<<"=================================================="<<endl;
	}
}
