#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <math.h>
#include <map>
#include <set>
#include <memory.h>
#include <numeric>
#include <ctype.h>

using namespace std;

int m, n;
vector < vector<char> > field(250, vector<char>(250));
char col = ' ';
int dx[] = {-1,0,0,1,-1,1,-1,1};
int dy[] = {0,-1,1,0,-1,1,1,-1};

void I()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			field[i][j] = 'O';
}

void C()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			field[i][j] = 'O';
}

void L (int x1, int y1, char c)
{
	  field[y1-1][x1-1] = c;
}

void V (int x1, int y1, int y2, char c)
{
   if (y1 > y2) swap(y1,y2);
	  for (int j = y1 - 1; j < y2; j++)
	  field[j][x1-1] = c;
}

void H (int x1, int x2, int y1, char c)
{
   if (x1 > x2) swap(x1,x2);
	for (int j = x1 - 1; j < x2; j++)
	     field[y1 - 1][j] = c; 
}

void K (int x1, int x2, int y1, int y2, char c)
{
   if (y1 > y2) swap(y1,y2);
   if (x1 > x2) swap(x1,x2);
	for (int i = y1 - 1; i < y2; i++)
			for (int j = x1 - 1; j < x2; j++)
				field[i][j] = c;
}

void F (int x1, int y1, char c)
{
      if (field[y1-1][x1-1] == col)
      {
       field[y1-1][x1-1] = c;
         for (int i = 0; i < 8; i++)
         {
            if (x1+dx[i] > 0 && x1+dx[i] <= m && y1+dy[i] >0 && y1+dy[i] <= n)
                F(x1+dx[i],y1+dy[i],c);
         }
      }
}

void S(string name)
{
   cout<<name;
   cout<<endl;
     for (int i = 0; i < n; i++)
      {
         for (int j = 0; j < m; j++)
            cout<<field[i][j];
         cout<<endl;
      }
}

int main()
{
   // Comment next line to read from console.
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   int x1, x2, y1, y2;
   char command, color;
   string name;
   while (cin>>command) 
   {  
   	  if (command == 'X') break;
      switch (command)
      {
      	case 'I': cin>>m>>n; I(); break;
      	case 'C': C(); break;
      	case 'L': cin>>x1>>y1>>color; color = toupper(color); 
         if (x1 > 0 && x1 < m+1 && y1 > 0 && y1 < n+1) L(x1,y1,color); break;
      	case 'V': cin>>x1>>y1>>y2>>color; color = toupper(color); 
         if (x1 > 0 && x1 < m+1 && y1 > 0 && y1 < n+1 && y2 > 0 && y2 < n+1) V(x1,y1,y2,color); break;
      	case 'H': cin>>x1>>x2>>y1>>color; color = toupper(color); 
         if (x1 > 0 && x1 < m+1 && y1 > 0 && y1 < n+1 && x2 > 0 && x2 < m+1) H(x1,x2,y1,color); break;
      	case 'K': cin>>x1>>x2>>y1>>y2>>color; color = toupper(color);
         if (x1 > 0 && x1 < m+1 && y1 > 0 && y1 < n+1 && x2 > 0 && x2 < m+1 && x2 > 0 && x2 < n +1) K(x1,x2,y1,y2,color); break;
      	case 'F': cin>>x1>>y1>>color; color = toupper(color); col = field[y1-1][x1-1];
         if (x1 > 0 && x1 < m+1 && y1 > 0 && y1 < n+1) F(x1,y1,color); break;
      	case 'S': cin>>name; S(name); break;
      	default: break;
      }  
   }
   return 0;
}
