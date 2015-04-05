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
vector < vector<char> > chess(8, vector<char>(8));
int px[] = {-1,1};
int rx[] = { 1, 2, 3, 4, 5, 6, 7,-1,-2,-3,-4,-5,-6,-7};
int bx[] = { 1, 2, 3, 4, 5, 6, 7,-1,-2,-3,-4,-5,-6,-7, 1, 2, 3, 4, 5, 6, 7,-1,-2,-3,-4,-5,-6,-7};
int by[] = { 1, 2, 3, 4, 5, 6, 7,-1,-2,-3,-4,-5,-6,-7,-1,-2,-3,-4,-5,-6,-7, 1, 2, 3, 4, 5, 6, 7};
int nx[] = {-1,-2,-2,-1,1,2,2,1};
int ny[] = {-2,-1,1,2,-2,-1,1,2};




bool valid(int i, int j)
{
	if (i >= 0 && j >= 0 && i < 8 && j < 8)
		return 1;
	else return 0;
}

int P(int i, int j)
{
	int res = 0, color = 0;
	if (isupper(chess[i][j])) color = -1; //black is 1, white is -1
   		else if (islower(chess[i][j])) color = 1;
	for (int k = 0; k<2; k++)
	{
		if (valid(i+color,j+px[k]))
		{
		if (toupper(chess[i+color][j+px[k]]) == 'K')
		{
			if ((color == 1 && isupper(chess[i+color][j+px[k]]) )) { res = 1; break; }
			if ((color == -1 && islower(chess[i+color][j+px[k]]) )) { res = -1; break; } 
		if (res != 0) return res;
		}}
	}
	return res;
}

int R(int i, int j)
{
	int res = 0, color = 0;
	int flag[] = {0,0,0,0};
	if (isupper(chess[i][j])) color = -1; //black is 1, white is -1
   		else if (islower(chess[i][j])) color = 1;
   	for (int k = 0; k < 14; k++)
   	{
   		if (valid(i+rx[k], j))
   			if (toupper(chess[i+rx[k]][j]) == 'K' )
   		{
   			if ((color == 1 && isupper(chess[i+rx[k]][j])  ) )
              {if ((rx[k]>0 && flag[0] == 0) || (rx[k] < 0 && flag[1] ==0) ) { return 1; }}
			if ((color == -1 && islower(chess[i+rx[k]][j])))  
            {if ((rx[k]>0 && flag[0] == 0) || (rx[k] < 0 && flag[1] ==0) ) { return -1; }}
		}
			else 
            {if (chess[i+rx[k]][j] != '.' && rx[k] > 0) flag[0] = 1; 
               if (chess[i+rx[k]][j] != '.' && rx[k] < 0) flag[1] = 1;}

		if (valid(i, j+rx[k]))
			if (toupper(chess[i][j+rx[k]]) == 'K' )
		{
			if ((color == 1 && isupper(chess[i][j+rx[k]]) ) ) 
            {if ((rx[k]>0 && flag[2] == 0) || (rx[k] < 0 && flag[3] ==0) ) { return 1; }}
			if ((color == -1 && islower(chess[i][j+rx[k]]) ))
            {if ((rx[k]>0 && flag[2] == 0) || (rx[k] < 0 && flag[3] ==0) ) { return -1; }}
		}
			else 
            {if (chess[i][j+rx[k]] != '.' && rx[k]>0) flag[2] = 1; 
               if (chess[i][j+rx[k]] != '.' && rx[k]<0) flag[3] = 1; }
   	}
   	return res;

}

int B(int i, int j)
{
   int res = 0, color = 0;
   int flag[] = {0,0,0,0};
   if (isupper(chess[i][j])) color = -1; //black is 1, white is -1
         else if (islower(chess[i][j])) color = 1;
   for (int k = 0; k < 28; k++)
   {
   if (valid(i+bx[k],j+by[k]))
   {
      if (toupper(chess[i+bx[k]][j+by[k]]) == 'K' && ((bx[k] > 0 && by[k] > 0 && flag[0] == 0) || (bx[k] > 0 && by[k] < 0 && flag[1] == 0) || (bx[k] < 0 && by[k] > 0 && flag[2] == 0) || (bx[k] < 0 && by[k] < 0 && flag[3] == 0)))
      {
         if ((color == 1 && isupper(chess[i+bx[k]][j+by[k]]) ) )  { return 1; }
         if ((color == -1 && islower(chess[i+bx[k]][j+by[k]]) )) { return -1; }
      }
      else if (chess[i+bx[k]][j+by[k]] != '.')
      {
         if (bx[k] > 0 && by[k] > 0) flag[0] = 1;
         if (bx[k] > 0 && by[k] < 0) flag[1] = 1;
         if (bx[k] < 0 && by[k] > 0) flag[2] = 1;
         if (bx[k] < 0 && by[k] < 0) flag[3] = 1;
      }
   }
   }
   return res;
}

int N(int i, int j)
{
   int res = 0, color = 0;
   if (isupper(chess[i][j])) color = -1; //black is 1, white is -1
         else if (islower(chess[i][j])) color = 1;
   for (int k = 0; k < 8; k++)
   {
   if (valid(i+nx[k],j+ny[k]))
   {
      if (toupper(chess[i+nx[k]][j+ny[k]]) == 'K')
      {
         if ((color == 1 && isupper(chess[i+nx[k]][j+ny[k]]) ) )  { return 1; }
         if ((color == -1 && islower(chess[i+nx[k]][j+ny[k]]) )) { return -1; }
      }
   }}
   return 0;
}

int check()
{
	int result = 0;
	bool color = 0;
	char buf = ' ';
	for (int i = 0; i < 8; i++)
   		for (int j = 0; j<8; j++)
   		{
   			buf = toupper(chess[i][j]);
   			switch (buf)
   			{
   				case 'P': result = P(i, j); break;
   				case 'R': result = R(i, j); break;
   				case 'B': result = B(i, j); break;
   				case 'Q': result = B(i, j); if (result == 0) result = R(i, j);  break;
   				case 'N': result = N(i, j); break;
   				default: break;
   			}
   			if (result != 0)  return result;
   		}
	return result;
}

int main()
{
   // Comment next line to read from console.
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   bool flag = 1;
   int indicator, counter = 0;
   while (flag) 
   {  
   		flag = 0;
   		for (int i = 0; i < 8; i++)
   			for (int j = 0; j<8; j++)
   			{
   				cin>>chess[i][j];
   				if (chess[i][j] != '.') flag = 1; 
   			}
   			if (flag != 0) 

   			{
   				indicator = check();
   				counter++;
   				cout<<"Game #"<<counter<<' ';
   				if (indicator == 1) cout<<"white king is in check."<<endl;
   				if (indicator == -1) cout<<"black king is in check."<<endl;
   				if (indicator == 0) cout<<"no king is in check."<<endl;
   			}        
   }
   return 0;
}