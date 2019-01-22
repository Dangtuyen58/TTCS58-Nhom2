#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct edge
{
	char v1[100]; //dinh 1
	char v2[100]; // dinh 2
	float weight; //trong so
}edge;
edge edges[100];  //mang chua cac canh cua do thi
edge spanningTree[100]; //mang chua cay khung nho nhat
int numberOfEdges=0; // so luong canh
int numberOfEdgesOfSpanningTree = 0; // so luong canh cua cay khung nho nhat

typedef struct state
{
	char name[100]; // chua cac dinh 
}state;
state CoveredStates[100]; //mang chua cac dinh duoc them vao cay khung
int numberOfStates=0;   // so luong states
// Doc do thi tu file
void getGraph() 
{
	FILE *input;
	input =fopen("graph.txt","r");
	while(!feof(input)) //ham giup doc tu dau den cuoi
	{
		fscanf(input,"%s %s %f", edges[numberOfEdges].v1,edges[numberOfEdges].v2,&edges[numberOfEdges].weight);
		numberOfEdges++;
	}
}

//Xuat ket qua vao file output.txt
void out()
{
	FILE *SpanningTree;
	SpanningTree= fopen("output.txt","w");
	for(int i=0 ; i<numberOfEdgesOfSpanningTree;i++)
	{
		fprintf(SpanningTree,"%s %s %0.2f \n",spanningTree[i].v1,spanningTree[i].v2,spanningTree[i].weight);
	}
	fclose(SpanningTree);
}

//ham in mo phong qua trinh thuc hien
 void printfTheSystem()
 {
 	printf("\n --------------------------\n");
 	printf("\n Our Edges:\n"); // Do thi ban dau
 	for(int i=0 ; i<numberOfEdges ; i++)
 	{
 		printf("\n [%d]%s %s %0.2f",i,edges[i].v1,edges[i].v2,edges[i].weight);
	 }
	 printf("\n Marked States:\n");// in ra dinh duoc chon
	 for(int i=0 ; i< numberOfStates ; i++)
	 {
	 	printf("\n %s",CoveredStates[i].name);
	 }
	 printf("\n Spanning tree Edges:\n"); //in ra canh cua spanning va trong so
	 for(int i=0 ; i<numberOfEdgesOfSpanningTree; i++)
	 {
	 	printf("\n %s %s %0.2f",spanningTree[i].v1,spanningTree[i].v2,spanningTree[i].weight);
	 }
 	
 }
//ham tim canh co chi so nho nhat 
int indexOfLowestMarkedEdge()
{
	//nhan tat ca cac canh duoc danh dau
	int b1,b2;
	int markedEdgesIndexes[100],numberOf_markedEdgesIndexes=0;
	for( int i=0; i<numberOfEdges ; i++)
	{
		b1=1;b2=1; // gan b1 = 1 tuc chua co
		for(int j=0 ; j<numberOfStates; j++)
		{
			if(strcmp(CoveredStates[j].name,edges[i].v1)==0)
			{
				b1=0; // tra gia tri b1 ve 0 tuc da ton tai
			}
			if(strcmp(CoveredStates[j].name,edges[i].v2)==0)
			{
				b2=0;
			}
			
		}
		if((b1==0 && b2 ==1) || (b1==1 && b2 == 0))
		{
			markedEdgesIndexes[numberOf_markedEdgesIndexes]=i;
			numberOf_markedEdgesIndexes++;
		}
	}
	if(numberOf_markedEdgesIndexes==0)
	{
		return -1;
	}
	//thiet lap chi so cua cac canh khong duoc danh dau nho nhat
	float min= edges[markedEdgesIndexes[0]].weight;
	int TheLowesmarkedEdge=markedEdgesIndexes[0];
	for( int i=0 ; i<numberOf_markedEdgesIndexes ; i++)
	{
		if(edges[markedEdgesIndexes[i]].weight<min)
		{
			min=edges[markedEdgesIndexes[i]].weight;
			TheLowesmarkedEdge = markedEdgesIndexes[i];
		}
	}
	return TheLowesmarkedEdge;
}
//ham them cay duoc danh dau thap nhat vao cay khung do thi nho nhat (cay spanning)
void addLowestMarkedToSpanningTree(int indexOfEdgeToAdd)
{
	strcpy(spanningTree[numberOfEdgesOfSpanningTree].v1,edges[indexOfEdgeToAdd].v1);
	strcpy(spanningTree[numberOfEdgesOfSpanningTree].v2,edges[indexOfEdgeToAdd].v2);
	spanningTree[numberOfEdgesOfSpanningTree].weight=edges[indexOfEdgeToAdd].weight;
	numberOfEdgesOfSpanningTree++;
	
}
//ham them state 
void addNewState(int indexOfEdgeToAdd)
{
  int b1=1 ,b2=1;
  for(int i=0 ; i<numberOfStates ; i++)
  {
  	if(strcmp(CoveredStates[i].name,edges[indexOfEdgeToAdd].v1)==0) //ham kiem tra ky tu trung nhau 
  	{
  		b1=0;
	  }
	  if(strcmp(CoveredStates[i].name,edges[indexOfEdgeToAdd].v2)==0)
  	{
  		b2=0;
	  }
  	
  }	
  if(b1==1)
  {
  		strcpy(CoveredStates[numberOfStates].name,edges[indexOfEdgeToAdd].v1);
  		numberOfStates++;
  	
  }
  if(b2==1)
  {
  	strcpy(CoveredStates[numberOfStates].name,edges[indexOfEdgeToAdd].v2); // ham sao chep 
  		numberOfStates++;
  }
    
}

void prim()
{
	int indexOfEdgeToAdd = indexOfLowestMarkedEdge();
	if(indexOfEdgeToAdd==-1) // kiem tra canh duoc danh dau
	{
		out();
		return;
	}
	addLowestMarkedToSpanningTree(indexOfEdgeToAdd);
	addNewState(indexOfEdgeToAdd);
	printfTheSystem();
	prim();
}

 int main()
{
	printf("\t \t prim's algorithm ...\n'");
	getGraph();
	strcpy(CoveredStates[numberOfStates].name, edges[0].v1);numberOfStates++;
	prim();
	getchar();
	getch();
	return 0;
}
