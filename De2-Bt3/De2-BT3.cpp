//BT3-De2
#include <conio.h>
#include <stdio.h>
#include <string.h>

struct Nv {
	char Msnv[10];
	char HoTen[50];
	int HSL;
	char CV[10];
	int HSCV;
	int Thang;
	int Nam;
};

void DocFile( Nv nv[],int &n)
{
	int m;
	FILE *fin = fopen ("input4.txt ","r");
	fscanf(fin,"%d",&m);
	n=m;
	int i=0;
	char ss[5];
	fgets(ss,5,fin);
	while(m--){
	fscanf(fin,"%s",&nv[i].Msnv);
	fscanf(fin,"%s",&nv[i].HoTen);
	fscanf(fin,"%d",&nv[i].HSL);
	fscanf(fin,"%s",&nv[i].CV);
	fscanf(fin,"%d",&nv[i].HSCV);
	fscanf(fin,"%d",&nv[i].Thang);
	fscanf(fin,"%d",&nv[i].Nam);
	i++;
	fgets(ss,5,fin);
	}
	fclose(fin);
}
//Tính luong cho nhân viên theo công thuc: luong = luong CB*(He So luong luong+ he So chuc vu)
int TLuong(Nv nv[] ,int n)
{
	int LCB=2;//Luong co ban
    int L=0;
	
	for( int i=0 ; i < n ; i++)
    {
    L=LCB*(nv[i].HSL+nv[i].HSCV);
	printf("\n--Luong %s:%d",nv[i].Msnv,L);
	}
	return L;
}
//Sap xep ds theo cot luong
  void SapXep( Nv nv[] ,int n)

{
	for( int i=0 ; i < n-1 ; i++)
	for(int j=i+1 ; j< n ; j++)
	if(nv[i].HSL+nv[i].HSCV < (nv[j].HSL+nv[j].HSCV))
	{
		Nv s= nv[i];
		nv[i]=nv[j];
		nv[j]=s;
	}
}

 void Xuat(Nv nv[] ,int n){
	for( int i=0 ;i<n ;i++)
	printf("\n MSNV:%s Hoten:%s HSL:%d CV:%s HSCV:%d %d %d Luong:%d ",nv[i].Msnv,nv[i].HoTen,nv[i].HSL,nv[i].CV,nv[i].HSCV,nv[i].Thang,nv[i].Nam,(nv[i].HSL+nv[i].HSCV)*2 );
}


//tim kiem nhan vien theo ma so
void TimKiem(Nv nv[],int n,char X[10]){
    int i;
    printf("\n\n Nhap msnv can tim:");
    fflush(stdin);
    gets(X);
    for(i=0;i<n;++i){
       if(strcmp(nv[i].Msnv,X)==0){
    printf("\n MSNV:%s Hoten:%s HSL:%d CV:%s HSCV:%d %d %d Luong:%d ",nv[i].Msnv,nv[i].HoTen,nv[i].HSL,nv[i].CV,nv[i].HSCV,nv[i].Thang,nv[i].Nam,(nv[i].HSL+nv[i].HSCV)*2 );
       }
    }
}
//Xoa nhan vien theo msnv
void Xoa(Nv nv[],int &n,char MaSo[10])
{
	printf("\n \nNhap Msnv can xoa:");
	gets(MaSo);
	for(int i=0;i<n;i++)
	{
		if(strcmp(nv[i].Msnv,MaSo)==0)
		{
		nv[i]=nv[i+1];
		printf("Xoa thanh cong");	
		}
		n--;
	}
}
int main()
{
	Nv nv[100];
    int n;
    char X[10],MaSo[10];
    DocFile(nv ,n);
    printf("----Danh Sach Nhan Vien:---\n");
    Xuat(nv,n);
    TLuong(nv,n);
    SapXep(nv ,n);
    printf("\n\n ----Sap Xep DS theo tang dan cot luong:----");
    Xuat(nv ,n);
	TimKiem(nv,n,X);
	Xoa(nv,n,MaSo);
    return 0;

	
}
