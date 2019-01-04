/* 
graphics in Dev-C++ - nguyenvanquan7826 
*/
#include <iostream>
#include <stdio.h>
#include <winbgim.h> 
#include <math.h>
#include <string.h>

using namespace std;
int Mx, My;//Max x ,Max y;
class Diem{
	protected:
		float x, y;
		friend class DuongThang;
		friend class TamGiac;
		friend class ChuNhat;
		friend class Vuong;
		friend class Tron;
		
	public:
		void Nhap(){
			cout<<endl<<"Toa do x: ";
			cin>>x;
			cout<<"Toa do y: ";
			cin>>y;
		}
		float TinhKhoangCach(Diem d2)
		{
			return sqrt(pow(x-d2.x,2)+pow(y -d2.y,2));
		}
};
class DuongThang{
	private:
		Diem a,b;
	public:
		void NhapDT(){
			cout<<"Toa do diem A: ";
			a.Nhap();
			cout<<"Toa do diem B: ";
			b.Nhap();
		}
		void DrawDT(){			
			line(a.x+Mx/2, -a.y+My/2, b.x+Mx/2, -b.y+My/2);
		}
};

class TamGiac{
	private:
		Diem a, b, c;
	public:
		void NhapTG()
		{
		bool Check;
         	do{
	          Check=true;//khoi tao
	          cout<<"\n Nhap diem A";
	          a.Nhap();
	          cout<<"\nNhap diem B";
	          b.Nhap();
	          cout<<"\nNhap diem B";
	          c.Nhap();
	          Check=KiemTraTamGiacHopLe();
	          if(Check==false)
	            {
		          cout<<"\n 3 diem khong tao thanh tam giac!";
	            }
	         }while(Check==false);
	   	}

		bool KiemTraTamGiacHopLe()
		{
			float AB=a.TinhKhoangCach(b);
        	float AC=a.TinhKhoangCach(c);
	        float BC=b.TinhKhoangCach(c);
	        if(AB +AC<=BC ||AB+BC<=AC||BC+AC<=AB)
	          {
		       return false;
	          }
               return true;	
		}
		void DrawTG(){			
			line(a.x+Mx/2, -a.y+My/2, b.x+Mx/2, -b.y+My/2);
			line(a.x+Mx/2, -a.y+My/2, c.x+Mx/2, -c.y+My/2);
			line(b.x+Mx/2, -b.y+My/2, c.x+Mx/2, -c.y+My/2);
		}	
};


class ChuNhat{
	private:
		Diem a, b; //a:topleft b:bottomright
	public:
		void NhapCN(){
			cout<<"Toa do diem a: ";
			a.Nhap();
			cout<<"Toa do diem b: ";
			b.Nhap();
		}
		void DrawCN(){			
			rectangle(a.x+Mx/2, -a.y+My/2, b.x+Mx/2, -b.y+My/2);
		}
};
class Vuong{
	private:
		Diem a, b; //a:topleft b:bottomright
	public:
		void NhapV(){
			do
			{
				cout<<"Nhap toa do diem a: ";
				a.Nhap();
				cout<<"Nhap toa do diem b: ";
				b.Nhap();
				if (abs(a.x-b.x) != abs(a.y-b.y))
					cout<<"Khong phai hinh vuong"<<endl;
			}
			while (abs(a.x-b.x) != abs(a.y-b.y));
		}
		void DrawVuong(){			
			rectangle(a.x+Mx/2, -a.y+My/2, b.x+Mx/2, -b.y+My/2);
		}
};
class Tron{
	private:
		Diem a;
		int r;
	public:
		void NhapTron(){
				cout<<"Nhap toa do tam hinh tron: ";
				a.Nhap();
				cout<<"Nhap ban kinh hinh tron: ";
				cin>>r;
		}
		void DrawTron(){			
			circle(a.x+Mx/2,-a.y+My/2,r);
		}
};

int main(){
	Mx = getmaxx(), My = getmaxy();
	DuongThang dt;
	Vuong v;
	Tron t;
	TamGiac tg;
	ChuNhat cn;
	initwindow(1280, 700);      // init window graphics
    cleardevice();
    

 int choice;
   cout<<"---------Menu------------\n";
    cout<<"1. Ve duong thang\n";
    cout<<"2. Ve tam giac\n";
    cout<<"3. Ve hinh chu nhat\n";
    cout<<"4. Ve hinh vuong\n";
    cout<<"5. Ve hinh tron\n";
    cout<<"6. End program\n";
    do
    {
	    cout<<endl<<"Nhap lua chon: ";
	    cin>>choice;
		switch(choice)
		{
			case 1:
				setcolor(14);
				dt.NhapDT();
				dt.DrawDT();
				break;
			case 2:
				setcolor(10);
				tg.NhapTG();
				tg.DrawTG();
				break;
			case 3:
				setcolor(4);
				cn.NhapCN();
				cn.DrawCN();
				break;
			case 4:
				setcolor(13);
				v.NhapV();
				v.DrawVuong();
				break;
			case 5:
				setcolor(12);
				t.NhapTron();
				t.DrawTron();
				break;
			case 0:
				break;
		}
		delay(1000);
	}
    while (choice != 6);	
    while(!kbhit()) delay(1);	// pause screen	
    return 0;
}





