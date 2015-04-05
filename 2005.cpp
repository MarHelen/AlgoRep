#include <iostream>
#include <queue>
#include <vector>
#include <stdio.h>
#include <set>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);  
 	vector < vector <int> > adjMatrix(7, vector <int> (7));
 	for(int i = 1; i <= 5; i++){
 		for (int j = 1; j <= 5; j++){            
  		cin>>adjMatrix[i][j];}
   	 }
   	 int p1 = adjMatrix[1][2] + adjMatrix[2][3] + adjMatrix[3][4] + adjMatrix[4][5];
   	 int p2 = adjMatrix[1][3] + adjMatrix[3][2] + adjMatrix[2][4] + adjMatrix[4][5];
   	 int p3 = adjMatrix[1][4] + adjMatrix[4][3] + adjMatrix[3][2] + adjMatrix[2][5];
   	 int p4 = adjMatrix[1][3] + adjMatrix[3][4] + adjMatrix[4][2] + adjMatrix[2][5];
   	 if (p1 <= p2 && p1 <= p3 && p1 <= p4 ) cout<<p1<<endl<<"1 2 3 4 5";
   	 else if (p2 <= p1 && p2 <= p3 && p2 <= p4 ) cout<<p2<<endl<<"1 3 2 4 5";
   	 else if (p3 <= p2 && p3 <= p1 && p3 <= p4 ) cout<<p3<<endl<<"1 4 3 2 5";
   	 else if (p4 <= p2 && p4 <= p3 && p4 <= p1 ) cout<<p4<<endl<<"1 3 4 2 5";

}