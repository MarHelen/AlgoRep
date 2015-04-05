#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <map>
#include <set>
#include <memory.h>
#include <numeric>
#include <assert.h>

using namespace std;

vector < vector<char> > field(101, vector<char>(101));


void result (int n, int m)
{
	int bomb_amount;
	for (int i=0; i<n;i++)
   		for (int j=0; j<m; j++)
   		{
   			bomb_amount= 0;
   			if (field[i][j] == '.')
   			{
   				if (i-1 >= 0 && j-1 >= 0)  
   					if (field[i-1][j-1] == '*') 
   						bomb_amount++;
   				if (i-1 >= 0)  
   					if (field[i-1][j] == '*') 
   						bomb_amount++;
   				if (i-1 >= 0 && j+1 < m)  
   					if (field[i-1][j+1] == '*')
   						 bomb_amount++;
   				if (j-1 >= 0)  
   					if (field[i][j-1] == '*') 
   						bomb_amount++;
   				if (j+1 < m)  
   					if (field[i][j+1] == '*') 
   						bomb_amount++;
   				if (i+1 < n && j-1 >= 0)  
   					if (field[i+1][j-1] == '*') 
   						bomb_amount++;
   				if (i+1 < n )  
   					if (field[i+1][j] == '*') 
   						bomb_amount++;
   				if (i+1 < n && j+1 < m)  
   					if (field[i+1][j+1] == '*') 
   						bomb_amount++;
   				field[i][j] = char(bomb_amount + (int)'0');
   			}
   		
   		}

}

int main()
{
   
   // Comment next line to read from console.
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);

   int n,m;
   char buf;
   int counter = 1;
   while (cin>>n>>m) {
   	if (n == 0 || m == 0) break;
   	if (counter>1) cout<<endl;
   	for (int i=0; i<n;i++)
   	{
   		for (int j=0; j<m; j++)
   			cin>>field[i][j];
   		//cin>>buf;
   	}
   
   	result(n,m);
   	cout<<"Field #"<<counter<<':'<<endl;
   	for (int i=0; i<n;i++)
   	{
   		for (int j=0; j<m; j++)
   			cout<<field[i][j];
   		cout<<endl;
   	}
   	//cout<<endl;
   	counter++;
  }

   return 0;
}
