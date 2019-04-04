#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
#include <time.h>
#include <fstream>
#include "type(mls).h"  
#include <thread>

using namespace std;

string map[32]= {
	
	"--------------------------------------------------------------------------------------------------------------------------------",
	"|...........................................................#..................................................................|",
	"|...........................................................#..................................................................|",
	"|...........................................................#..................................................................|",
	"|....................................############...........#...........############...........................................|",
	"|...............................................#...........#...........#......................................................|",
	"|..........###########..........................#.......................#..........................##############..............|",
	"|....................#..........................#.......................#..........................#...........................|",
	"|....................#..........................#.......................#..........................#...........................|",
	"|....................#..........................#.......................#..........................#...........................|",
	"|....................##############....................###########...................###############...........................|",
	"|..............................................................................................................................|",
	"|..............................................................................................................................|",
	"|..............#...................###############....................################..........................#..............|",
	"|..............#................................................................................................#..............|",
	"|...........#######..........................................................................................#######...........|",
	"|..............#................................................................................................#..............|",
	"|..............#................................................................................................#..............|",
	"|..................................###############....................################.........................................|",
	"|..............................................................................................................................|",
	"|..............................................................................................................................|",
	"|....................##############....................###########....................##############...........................|",
	"|....................#..........................#.......................#..........................#...........................|",
	"|....................#..........................#.......................#..........................#...........................|",
	"|....................#..........................#.......................#..........................#...........................|",
	"|..........###########..........................#.......................#..........................##############..............|",
	"|...............................................#...........#...........#......................................................|",
	"|....................................############...........#...........############...........................................|",
	"|...........................................................#..................................................................|",
	"|...........................................................#..................................................................|",
	"|...........................................................#..................................................................|",
	"--------------------------------------------------------------------------------------------------------------------------------"
	};	
	
	
	short speed=0;
	string user;
	bool stop=true;
	int x=3;
	int y=3;
	int s=0;
	short Health=0;
	int g1x=10,g1y=10;
	int g2x=20,g2y=20;
	int g3x=100,g3y=10;

void print_map()
	{
		for(int h=0;h<32;h++)
		{
			for(int j=0;j<128;j++)
			{
				if(map[h][j]=='0')
				{
					cout<<' ';
				}else 
					cout << map[h][j];
			}
			

			cout << '\n';
		}		
	}
	
void move(int dx,int dy)
{
	x+=dx;
	y+=dy;
}

void gotoxy(short x, short y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursorCoord;
	cursorCoord.X=x;
	cursorCoord.Y=y;
	SetConsoleCursorPosition(consoleHandle, cursorCoord);
}
void stopw(int i,int j)
{
	if(map[i][j]=='|' || map[i][j]=='-' || map[i][j]=='#')
		move( 0, 1);
}
void stops(int i,int j)
{
	if(map[i][j]=='|' || map[i][j]=='-' || map[i][j]=='#')
		move( 0,-1);
}
void stopd(int i,int j)
{
	if(map[i][j]=='|' || map[i][j]=='-' || map[i][j]=='#')
		move(-1, 0);
}
void stopa(int i,int j)
{
	if(map[i][j]=='|' || map[i][j]=='-' || map[i][j]=='#')
		move( 1, 0);
}

void score(int x,int y)
{
if(map[y][x]=='.')
	++s;				
}

class Ghost
{
	public:
		int random;
		int di,dj,dx,dy,sa;
		int gobar=0;
		int con=0;

		Ghost(int i,int j,int r)
			{
				di=i;
				dj=j;
				random=r;
			}
		void adress(int &x,int &y)
		{
			dx=x;
			dy=y;
			random=random+x+y	;
		}	
		
		void start()
		{
			srand(random);
			int go=rand()%2;
			if (go==0)
			{
				if(dx>di)
					goxplus();
				if(dx<di)
					goxneg();	
			}else 
			{
				if(dy>dj)
					goyplus();
				if(dy<dj)
					goyneg();	
			}	
		}
		void gotoxy(int x, int y)
		{
			HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
			COORD cursorCoord;
			cursorCoord.X=x;
			cursorCoord.Y=y;
			SetConsoleCursorPosition(consoleHandle, cursorCoord);
		}
		void goxplus()
		{
			if(map[dj][di+1]!='|' && map[dj][di+1]!='-' && map[dj][di+1]!='#' && map[dj][di+1]!='G')
			{
				gotoxy(di,dj);
				cout<<'.';
				map[dj][di]='.';
				di++;
				gotoxy(di,dj);
				cout<<'G';
				map[dj][di]='G';
			}else
				gobar++;
		}
		void goyplus()
		{
			if(map[dj+1][di]!='|' && map[dj+1][di]!='-' && map[dj+1][di]!='#' && map[dj+1][di]!='G')
			{
				gotoxy(di,dj);
				cout<<'.';
				map[dj][di]='.';
				dj++;
				gotoxy(di,dj);
				cout<<'G';
				map[dj][di]='G';
			}else
				gobar++;
		}
		void goxneg()
		{
			if(map[dj][di-1]!='|' && map[dj][di-1]!='-' && map[dj][di-1]!='#' && map[dj][di-1]!='G')
			{
				gotoxy(di,dj);
				cout<<'.';
				map[dj][di]='.';
				di--;
				gotoxy(di,dj);
				cout<<'G';
				map[dj][di]='G';
			}else 
				gobar++;
			
		}
		void goyneg()
		{
			if(map[dj-1][di]!='|' && map[dj-1][di]!='-' && map[dj-1][di]!='#' && map[dj-1][di]!='G')
			{
				gotoxy(di,dj);
				cout<<'.';
				map[dj][di]='.';
				dj--;
				gotoxy(di,dj);
				cout<<'G';
				map[dj][di]='G';
			}else 
				gobar++;
				
		}	
};


void main_I()
{
		system("cls");
	int speed;
	if(::speed==1)
		speed=3;
	if(::speed==3)
		speed=2;
	if(::speed==3)
		speed=1;		
		
	for(int i=0;i<31;i++)
			map[i][128]='\n';
	
	Sleep(2000);
	print_map();
	
	gotoxy(135,9);
	cout<<"you score is : "	;
	char con;
	char go;
	short xsa=0;
	
	int b=0;
	
	Ghost G1(g1x,g1y,324);
	Ghost G2(g2x,g2y,234);
	Ghost G3(g3x,g3y,944);

	int red=0;
	int g1=0,g2=0,g3=0;
	do
	{
		red++;
		int ddx=x;
		int ddy=y;
		
		
		if(G1.gobar==10)
		{
			ddx+=10;
			ddy+=10;
			G1.adress(ddx,ddy);
			g1++;
			if(g1==120)
			{
				g1=0;
				G1.gobar=0;
			}
				
		}else 
		{
			G1.adress(ddx,ddy);
		}

			
			G2.adress(ddx,ddy);
			G3.adress(ddx,ddy);

	if(red%speed==0)
	{
			
	if(GetAsyncKeyState(38)& (0x8000 != 0))	
		con='w';
	if(GetAsyncKeyState(40)& (0x8000 != 0))	
		con='s';
	if(GetAsyncKeyState(39)& (0x8000 != 0))	
		con='d';
	if(GetAsyncKeyState(37)& (0x8000 != 0))	
		con='a';
	if(GetAsyncKeyState(0x53)& (0x8000 != 0))
		{	
			g1x=G1.di;
			g1y=G1.dj;
			g2x=G2.di;
			g2y=G2.dj;
			g3x=G3.di;
			g3y=G3.dj;		
			ofstream save;
			save.open(user);
			save<<::speed<<'\n';
			save<<x<<'\n'<<y;
			save<<'\n'<<g1x<<'\n'<<g1y;
			save<<'\n'<<g2x<<'\n'<<g2y;
			save<<'\n'<<g3x<<'\n'<<g3y;
			save<<'\n'<<s<<'\n';
			for (int i=0;i<32;i++)
			{
				for(int j=0;j<128;j++)
					save<<map[i][j];
					save<<'\n';
			}	
			save.close();
		}
	
	
	
switch(con)
	{
		case 'w' :gotoxy( x, y);cout<<' ';map[y][x]='0';move( 0,-1);stopw(y,x);gotoxy( x, y);cout<<'V';score(x,y);break;		
		case 's' :gotoxy( x, y);cout<<' ';map[y][x]='0';move( 0, 1);stops(y,x);gotoxy( x, y);cout<<'h';score(x,y);break;
		case 'd' :gotoxy( x, y);cout<<' ';map[y][x]='0';move( 1, 0);stopd(y,x);gotoxy( x, y);cout<<'<';score(x,y);break;
		case 'a' :gotoxy( x, y);cout<<' ';map[y][x]='0';move(-1, 0);stopa(y,x);gotoxy( x, y);cout<<'>';score(x,y);break;	
	}
	
	Sleep(100);
	if (xsa==0)
	{
		Sleep(1000);
		xsa++;
	}
	gotoxy(140,10);
	cout<<"  ";
	gotoxy(140,10);
	cout<<s;
	}
		G1.start();
		G2.start();
		G3.start();	

	if((x==G1.di && y==G1.dj) || (x==G2.di && y==G2.dj) || (x==G3.di && y==G3.dj) )
		exit(0);	
	}while(stop==true);
}



int main()
{
	bool sav;
	int a=8;
	do
	{	
		system("cls");
	typem m0("Sadra Zadeh Khameneh PAC MAN\n|");
	typem m1("1.NEW Game\n|");
	typem m2("2.LOAD Game\n|");
	typem m3("0.EXIT\n|");
	m0.printmls(16);
	m1.printmls(16);
	m2.printmls(16);
	m3.printmls(16);
	cin>>a;
	system("cls");
	}while(a!=0 && a!=1 && a!=2);
		
	switch(a)
	{
		case 0 : cout<< "Thank you !";exit(0);
		case 1 :
		do
		{
		cout<<"create username please\nusername: ";cin>>user;cout<<"\nselect Game speed: 1.Hard 2.Normal 3.Easy\n";cin>>speed;
		if(speed==1 || speed==2 || speed==3)
			break;
		else 
			system("cls");	
		}while(true);
		main_I();
		break;
		
		case 2 :
		do
		{
		sav=false;
		cout<<"Enter username: ";cin>>user;
		ifstream save(user);
		if (!save)
			sav = true;system("cls");
		}while(sav);
		ifstream save(user);
		save>>::speed;
		save>>x;
		save>>y;
		save>>g1x;
		save>>g1y;
		save>>g2x;
		save>>g2y;
		save>>g3x;
		save>>g3y;
		save>>s;
	
		for (int i=0;i<32;i++)
		{
			for(int j=0;j<128;j++)
				save>>map[i][j];	
		}
		save.close();	
		
		main_I();break;
		}			
			return 0;			
}
