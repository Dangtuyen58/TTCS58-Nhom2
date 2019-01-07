#include<stdio.h>
#include <conio.h>
#include<stdlib.h>
#include<time.h>
#define Max 100
 
int main()
{
   int i,m;
   int a[Max];
   printf("Nhap m:");
   scanf("%d",&m);
   srand(time(NULL));// thay doi theo thoi gian
   for(i=1;i<m;i++)
   {
   a[i]= rand()%m;    
   printf("%5d",a[i]);
   }
   getch();
   return 0;
}

