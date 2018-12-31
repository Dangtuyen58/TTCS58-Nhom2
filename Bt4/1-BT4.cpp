#include<math.h>
#include<iostream>
#include<conio.h>
#include<time.h>
#include <algorithm> 
#define max 100
using namespace std;
////Nhap Mang random
void NhapMang(int a[],int n)
{
   int i;
   srand(time(NULL));// thay doi theo thoi gian
   for(i=0;i<n;i++)
   a[i]=rand()%51;
}
//Xuat Mang
void XuatMang(int a[],int n)
{
   int i;
   for(i=0;i<n;i++)
   printf("%5d",a[i]);
}

//Hoan vi
void Swap(int &a,int &b){
 int temp = a;
 a = b;
 b =  temp;
}
//Hoan vi nut cha i > nut con
void Heapify(int A[],int n, int i) {
  int vt; //root
 int cl =  (2*i)+1; // con trai
 int cr = (2*i)+2;   //con phai
 if(cl<n && A[cl]>A[i]) //Nut con trai > root
  vt = cl;
 else
  vt = i;
 if(cr<n && A[cr]>A[cl]) 
 vt=cr;
 // root khong lon nhat
 if(i!=vt) {
  Swap(A[i],A[vt]);
  Heapify(A,n,vt);
 }
}
//Xay heap moi nut cha lon hon nut con
void BuildHeap(int A[], int n) {
 for(int i = n/2-1; i>=0; i--)
  Heapify(A,n,i);
}

//
void HeapSort(int A[], int n) {
 BuildHeap(A,n);
 for(int i = n-1; i>=0; i--){ //nut la n-1
  Swap(A[0],A[i]); // Di chuyen ve root cuoi cung
  Heapify(A,i,0);
 }
}
//Chuong trình chính
int main(){
 int A[max],i,n;
 cout<<"Nhap so phan tu:"; cin>>n;
 NhapMang(A,n);
 cout<<"\nMang vua nhap la:";
 XuatMang(A,n);
 cout<<"\n mang sau khi chinh:";
  Heapify(A,n,i);
 XuatMang(A,n);
 cout<<"\nSap xep theo Heap Sort:";
 HeapSort(A,n);
 XuatMang(A,n);
 getch();
 return 0;
}
