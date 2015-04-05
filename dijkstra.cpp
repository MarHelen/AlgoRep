#include <iostream>
#include <queue>
#include <vector>
#include <stdio.h>
#include <set>

using namespace std;

int dej_path(int n, vector < vector <int> > A, vector <int> &v,int l, queue <int> &q)
{
	set <int> buff;
	v[1] = 0;
	if (l == 1) return v[1];
	for (int i = 1; i<=n; i++){  
		if (A[i][l] != 0)
			buff.insert(i); }
	int value;
	v[l] = 100000;
	int vert;
	for (set <int> :: iterator it = buff.begin(); it != buff.end(); ++it ) {
		if (v[*it] == 0 && *it != 1)  v[*it] = dej_path(n,A,v,*it,q);
		value = A[l][*it] + v[*it];
		if (value < v[l]) { v[l] = value; q.push(*it);}
	}
	return v[l];

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
   	 queue <int> q;
   	 q.push(5);
   	 cout<<endl<<dej_path(n,adjMatrix,visit,5,q)<<endl;
   	 while(q.size()){
   	 	cout<<q.front()<<' ';
   	 	q.pop(); }
   	 cout<<'1';
}