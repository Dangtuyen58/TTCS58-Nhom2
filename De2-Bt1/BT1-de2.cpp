#include<conio.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<algorithm>


void Nhap( int a[][100] , int n)
{
	int i,j;	
	srand(time(NULL)); //thay doi theo thoi gian
	for(i=0 ; i< n ; i++)
	{
		for(j=0 ; j< n ; j++)
		{
			
			a[i][j]=rand()%101;
		}
		
	}
		
	
}

void Xuat(int a[][100] , int n)
{
	for( int i=0 ; i < n ; i++)
	{
		printf("\n");
		for(int j=0 ; j < n ; j++)
		printf("%5d\t",a[i][j]);

	}
}

void XoaD( int a[][100],int &n ,int vtxoa )
{	
      do{
	 	 printf("\n Nhap vao dong muon xoa:");
	     scanf("%d",&vtxoa);
	}while( vtxoa <0 || vtxoa > n);
    		for(int i=vtxoa ; i < n-1; i++)
	  	for(int j=0 ; j < n ; j++ )
	{
      a[i][j]=a[i+1][j];
	}
	n--;
	

}

// Xoa cot 
void XoaC(int a[][100] , int &n , int vtxoa2)
{
	  do{
	 	 printf("\n Nhap vao cot muon xoa: ");
	     scanf("%d",&vtxoa2);
	}while( vtxoa2 <0 || vtxoa2 > n);

	for( int i = 0 ; i < n ; i++)
	   for( int j= vtxoa2 ; j<n-1 ; j++)
	   {
	   	a[i][j]=a[i][j+1];
	   }
	   n--;
}

//ma tran doi xung if a[i][j] = a[j][i]

int  ktra(int a[][100], int n)
{
	for (int i= 0 ; i < n ; i++)
	{
		for(int j= 0 ; j < n ; j ++)
	{
		if(a[i][j]!= a[j][i])
		{
				return 0;
		}
	}
	}
	return 1;
}
//kt so lon nhat cac hang cot
bool ktra1( int a[][100] , int i,int j,int n)
{
	for( int k=0 ; k < n ; k++)	
	{
        if (a[i][j] < a[k][j])
        {
        	return false;
        }
	    if (a[i][j] < a[i][k])
	    {
	    	return false;
		}
	}
	return true;
}
// kt cac duong cheo
bool ktra2( int a[][100] , int i , int j , int n)
{
	int d,c;
	//cheo right duoi
	for( d=i+1 , c=j+1 ; d < n && c < n; d++ , c++)
	{
		if(a[i][j] < a[d][c])
		return false;
	}
	//cheo left duoi
	for( d=i+1 , c=j-1 ; d < n && c >=0 ; d++ , c--)
	{
		if(a[i][j] < a[d][c])
		return false;
	}
	//cheo right tren
	for(d = i-1 , c=j+1 ; d>=0 && c <n ; d -- , c++)
	{
		if(a[i][j] < a[d][c])
		return false;
	}
	// cheo left tren
	for(d= i -1 , c= j -1 ; d>= 0 && c >=0 ; d-- ,c--)
	{
		if(a[i][j] < a[d][c])
		return false;
	}
	return true;
	
}
// tim so hoang hau

  int ktraHH( int a[][100], int n)
{
	bool check=false;
	for(int i=0 ; i< n ; i++)
	{
		for(int j=0 ; j< n ; j++)
		{
			if(ktra1(a,i,j,n)==true && ktra2(a, i , j , n)==true)
			{
				printf("a[%d][%d] = %d \t",i,j,a[i][j]);
				check=true;
			}
		}
	}
	if( check == false)
	{
		printf("Khong co phan tu hoang hau:");
	}
	return 0;
}

int main()
{
	int vtxoa,vtxoa2;
	int n, a[100][100];
    do{
	  printf("Nhap n:");
	  scanf("%d",&n);	
	}while( n < 3 || n >10) ;
	Nhap(a,n);
	printf("\n Ma tran da nhap:");
	Xuat(a,n);
	XoaD(a,n,vtxoa);
	 printf("\n Ma tran sau khi xoa dong ");
	 Xuat(a,n);
	 XoaC(a,n,vtxoa2);
	 printf("\n Ma tran sau khi xoa cot\n ");
	 Xuat(a,n);
	 if(ktra(a,n)==0)
	 printf("\n Ma tran khong doi xung");
	 else
	 printf("\n Ma tran doi xung");
	 printf("\n");
	 printf("\n So hoang hau la:");
	 ktraHH(a,n);
	 getch();
	 return 0;

}
