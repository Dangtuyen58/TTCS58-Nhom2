#include <iostream>
#include <stdlib.h>
using namespace std;
// khai bao cau truc
struct node{
    int Data;
    struct node *pLeft;
    struct node *pRight;
};
typedef struct node NODE;
typedef NODE *Tree, *Tree1;


// khoi tao cay
void Init(Tree &t){
    t=NULL;
}

// Tao Node tren cay
NODE *makeNode(int x){
    NODE *p = new NODE;
    if(p==NULL) return NULL;
    else{
        p->Data = x;
        p->pLeft = p->pRight = NULL;
    }
    return p;
}

// Insert Node vao cay
void insertNode(Tree &t, int x){

    if(t==NULL){ // cay rong => x la Node goc
        NODE *p = new NODE;
        p=makeNode(x);
        t=p;
    }
    else {
        if(t->Data > x){
            insertNode(t->pLeft,x);
        }
        else if(t->Data < x){
         insertNode(t->pRight,x);
        }
    }
}

// Nhap du lieu cho cay
void inputTree(Tree &t){
    Init(t);// phai khoi tao cay truoc thi moi co the nhap du lieu cho cay
    cout<<"Nhap du lieu cho cay\n";
    cout<<"An phim 0 de det thuc \n";
    int x;
    do{
        //int x;
        cout<<"Nhap Node: ";
        cin>>x;
        if(x!=0) {
            insertNode(t,x);
        }
       // else break;
    }while(x!=0);
}

// Xuat du lieu
void output(Tree &t){
    if(t!=NULL){
        cout<<t->Data<<" ";
        output(t->pLeft);
        output(t->pRight);
    }
}

// Duyet theo LNR

void duyetLNR(Tree &t){
	if(t!= NULL){
		duyetLNR(t->pLeft);
		printf("%3d",t->Data);
		duyetLNR(t->pRight);
	}
}





//Tich chieu cao
int max(int a, int b){
	if( a >= b ) 
	return a;
	return b;
}
int chieuCao(Tree &t){
	if(t == NULL) return 0;
	else return 1 + max(chieuCao(t->pLeft),chieuCao(t->pRight));
}
//in muc
void inMuci(Tree &t, int i, int muc = 1){
	if(t != NULL){
		if(muc == i) 
		printf("%3d",t->Data);
	else {
		inMuci(t->pLeft,i,muc + 1);
		inMuci(t->pRight,i,muc + 1);
	}
	}
}

/*Sao chep
void saoChep(Tree *t, Tree *&t1)
{
     if(t == NULL)
       t1 = NULL;
     else
       {
          t1 = new Node;
          t1->Data = t->Data;
          saoChep(t->pLeft, t1->pLeft);
           saoChep(t->pRight, t1->pRight);
       }
}*/

// Tim phan tu q bi xoa, cho phan tu p len thay the
void thaythe(Tree &q, Tree &p){
    // tim phan tu trai nhat cua cay ben phai
    //if(t==NULL) return;
    if(p->pLeft!=NULL){
        thaythe(q,p->pLeft);
    }
    else {
        q->Data = p->Data;
        q=p;
        p=p->pRight;
    }

}
// xoa mot nut thuoc cay
void delTree(Tree &t, int x){
    if(t==NULL) return;
    if(t->Data > x) delTree(t->pLeft,x);
    if(t->Data < x) delTree(t->pRight,x);
    if(t->Data == x) { // khi tim ra phan tu do roi
        // xoa Node la hoac Node co 1 phan tu
        NODE *q = t;// xoa phan tu bang con tro
        if(t->pLeft==NULL) { // neu ma ben traiphan tu do bang NULL
            t=t->pRight; // cho t tro toi t->pRight
        }
        else if(t->pRight==NULL){
            t=t->pLeft;
        }
        // xoa Node co 2 phan tu Trai va Phai
       else thaythe(q,t->pRight);
        delete q;
    }
}
int main()
{
    Tree t;
    int k,x;
    inputTree(t);
    output(t);
    cout<<endl<<"Duyet theo LNR:";
    duyetLNR(t);
    printf("\n Chieu cao cua cay: %d \n ",chieuCao(t));
    cout<<endl<<"In muc:";
    inMuci(t,3,1);
    //Init(t1);
    //printf("Sao chep:");
    //saoChep(t, t1);
    cout<<endl<<"Nhap phan tu can xoa:";
    cin>>k;
    delTree(t,k);
    output(t);
    return 0;
}
