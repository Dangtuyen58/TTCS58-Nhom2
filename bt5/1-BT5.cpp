#include<conio.h>
#include<stdio.h>
#include<math.h>



struct co{
	int tren,duoi;
};

co a[29];  // dl luu tru cac quan co
int tt[29]; // trang thai cac quan co
int n;
int ttluu [29]; // luu cac quan co can tim

int cl=168; //do lech lon nhat
char pathin[50];
FILE *f;
//D:\monhoctap\18-19\TTCS\code\bt5\domino.txt
//doc dl tu file
void nhaptenfile(){
	printf("nhap ten file: ");
 	gets(pathin);
}
void DocDuLieu(char pathin[50]){
	f = fopen(pathin,"r");
	if(f == NULL) printf("\n ko tim thay file");
	else{
	fscanf(f,"%d",&n);
	for(int i = 1; i <= n; i++){
	fscanf(f,"%d",&a[i].tren);
	fscanf(f,"%d",&a[i].duoi);
	}
	}
}
//nhap tay
/*void NhapCo(int &n)
{
	printf("\n Nhap n quan co");
	scanf("%d",&n);
	for( int i=1 ; i<=n ; i++)
	{
		printf("\n Quan co thu %d:",i);
		printf("\n Mat tren:");
		scanf("%d",&a[i].tren);
		printf("\n Mat duoi:");
		scanf("%d",a[i].duoi);
	}
}*/
void ktra()
{
	int k;
	int dochenh;
	int sumt=0; int sumd=0;
	for( k=0 ; k <= n ; k++)
	if(tt[k]==0)
	{
		sumt=sumt+ a[k].tren;
		sumd=sumd + a[k].duoi;
	}
	dochenh= abs(sumt -sumd);
	if( dochenh < cl )
	{
		cl=dochenh;
		for(k=1 ; k<= n ; k++)
		ttluu [k]=tt[k];
	}
}

void thu(int i)
{
    int k;
    for( k = 0 ; k<=1 ; k++)
    {
    	tt[i]=k;
    	if( i < n) thu(i+1);
    	else
    	  ktra();
    	  tt[i]=0;
	}
	
}


//----

void kqua()
{
	int dem=0;
	printf(" \n voi do lech be nhat %d :",cl);
	for (int k =1 ; k<=n ; k++)
	if( ttluu[k]==1)
	{
		dem++;
	}
	printf(" So luong quan  co quay %d",dem);
    printf("\n Trang thai ung voi do lech be nhat");
    for(int k=1 ; k<= n ; k++)
    printf("%2d",ttluu[k]);
    
}
int main()
{
	nhaptenfile();
    DocDuLieu(pathin);
	thu(1);
	kqua();
	getch();
	return 0;
}

