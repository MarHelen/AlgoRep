#include <iostream>
#include <queue>
#include <vector>
#include <stdio.h>

using namespace std;

int dfs(int n, vector < vector <int> > A, int f, int l, vector <int> &v)
{
	v[f] = 1;
	cout<<f<<' '<<l<<endl;
	if (f == l) return 1;
	for (int j = f; j <= n; j++) 
			if (A[f][j] == 1 && v[j] == 0)
				dfs(n,A,j,l,v); 
	return 0; 	
}


int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);  
 	int n;
 	cin>>n;
 	vector <int> visit(n+2);
 	vector < vector <int> > adjMatrix(n+2, vector <int> (n+2));
 	for(int i = 1; i <= n; i++){
 		visit[i] = 0;
 		for (int j = 1; j <= n; j++){            
  		cin>>adjMatrix[i][j];}
   	 }
 
   	 cout<<dfs(n,adjMatrix, 1, 6, visit);
}

