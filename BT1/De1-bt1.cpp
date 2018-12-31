#include <iostream>
#include <fstream>
using namespace std;

void inxoanoc (int a[5][5],int m,int n)
{
	 int i;
	 if(m==n)
	  {
	    printf("%3d\n",&a[m][m]);
      }
      else
      //in hang dau k
      {
	  for(int i=m;i<=n;i++)
       printf("%3d\n",&a[m][i]);
       //in cot n (top-down)
      for(int i=m+1; i <= n ; i++ )
      printf("/%3d \n",&a[i][n]);
      // in hang n (in nguoc)
      for(int i=n-1; i>=m ; i--)
      printf("%3d \n ",&a[n][i]);
      //in cot k
      for(int i=n-1 ; i>=m+1; i--)
      printf("%3d ",&a[i][m]);
    inxoanoc(a,m+1,n-1);
}
}
int main ()
{
    int m, n, a[5][5];
    ifstream ReadFile ("Matran.txt");
    if(ReadFile.fail()){
        cout << "Kiem tra lai file dau vao!";
        system("pause");
        return 0;
    }
   
    ReadFile >> m;
    ReadFile >> n;
    for (int i = 0; i < m; i ++)
    {
        for (int j = 0; j < n; j ++)
        {
            ReadFile >> a[i][j];
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    
     printf("\n Ma tran xoan oc");
	inxoanoc(a,0,4);
    ReadFile.close();
    system ("pause");
    return 0;
}
