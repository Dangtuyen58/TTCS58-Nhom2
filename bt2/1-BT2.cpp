#include<stdio.h>
#include<conio.h>
#include<string.h>
//khai bao cau truc du lieu
// con
struct nut2{
	char msnk[3];
	char hotennk[15];
	char gioitinh[3];
	nut2 *sau;
	
};
//xe
struct nut3{
	char soxe[5];
	char loaixe[10];
	char hieuxe[10];
	
	nut3 *ke;
};
//ql
struct nut1{
	char sohokhau[3];
	char hotench[15];

	nut2 *con;
	nut3 *xe;
	nut1 *tiep;
};
//viet thu tuc nhap danh sach xe
void nhapxe(nut3 *&dau){
      char soxetam[5];
      nut3 *p,*q;
      do{
      	  printf("\n nhap vao so xe");
      	  fflush(stdin);
      	  gets(soxetam);
      	  if(strcmp(soxetam,"\0")!=0)
      	  {
      	  	p=new nut3 ;
      	  	strcpy(p->soxe,soxetam);
      	  	printf("\n nhap vao loai xe");
      	  	gets(p->loaixe);
      	  	printf("hieu xe: ");
            fflush(stdin);
            gets(p->hieuxe);
      	  	p->ke=NULL;
      	  	if(dau==NULL)
      	  	  dau=p;
      	    else
      	    q->ke=p;
      	    q=p;
      	    }
      	
	  }while(strcmp(soxetam,"\0")!=0);
}
//nhap vao danh sach con
void nhapcon(nut2 *&dau)
{
	char msnktam[3];
	nut2 *p,*q;
	do{
		printf("\n nhap vao danh sach da lien ket");
		fflush(stdin);
		gets(msnktam);
		if(strcmp(msnktam,"\0")!=0)
		{
			p=new nut2;
			strcpy(p->msnk,msnktam);
			printf("\n nhap ho ten nhan khau ");
			gets(p->hotennk);
			p->sau=NULL;
			if(dau==NULL)
		     	dau=p;
			else
		    	q->sau=p;
			    q=p;
		}
	}while(strcmp(msnktam,"\0")!=0);

}
//
void nhaphk(nut1 *&dau)
{
	char sohokhautam[3];
	nut1 *p,*q;
	do{
		printf("nhap vao so ho khau ");
		gets(sohokhautam);
		if(strcmp(sohokhautam,"\0")!=0)
		{
			p=new nut1;
			strcpy(p->sohokhau,sohokhautam);
			printf("\n nhap ten chu ho");
			gets(p->hotench);
			p->con=NULL;
			nhapcon(p->con);
			p->xe=NULL;
			nhapxe(p->xe);
			p->tiep=NULL;
			if(dau==NULL)
			  dau=p;
			else 
			  q->tiep=p;
			  q=p;
			  }
		}while(strcmp(sohokhautam,"\0")!=0);
	
	}
//viet thu thuc hen thi danh sach 
void hienthink(nut1 *dau)
{
	if(dau!=NULL)
	{
		printf("%5s",dau->sohokhau);
		printf("%s",dau->hotench);
		hienthink(dau->tiep);
		}
	}
//in hieu xe 	
   int yamaha(nut3 *dau)
{
    if(dau==NULL)
     return 0;
  else
    if(strcmp(dau->hieuxe,"yamaha")==0)
     return 1;
  else
     return yamaha(dau->ke);
}
void duyetxe(nut1 *dau)
{
	if(dau!=NULL)
{
if(yamaha(dau->xe)==1)
printf("\n %s %s",dau->sohokhau,dau->hotench);
duyetxe(dau->tiep);
}
}
//xoa 

int main()
{
	int i;
		
   printf("Nhap muc i: " ); 
     scanf("%d",&i) ;
     printf("\n ");
	nhapxe(dau);
	nhapcon(dau);
	nhaphk(dau);
	hienthink(dau);
	duyetxe(dau);
	getch();
	return 0;
	
    
	
	
}




