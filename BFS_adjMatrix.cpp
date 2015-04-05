#include <iostream>
#include <queue>
#include <vector>
#include <stdio.h>

using namespace std;

int queue_build(int n, vector < vector <int> > A, vector <int> &v, queue <int> &q, int f)
{
	for (int j = 1; j <= n; j++) 
			if (A[f][j] == 1 && v[j] == 0){
				q.push(j);
				v[j] = f; }
}

int bfs(int n, vector < vector <int> > A, int f, int l, vector <int> &v)
{
	queue <int> q;
	if (f == l) return 1;
	v[f] = -1;
	int next, prev;
	queue_build(n,A,v,q,f);
	cout<<f<<endl;
	while(q.size()) {
		next = q.front();
		q.pop();
		cout<<next<<endl;
		if (next == l) {return 1;}
		queue_build(n,A,v,q,next);
	}

	return 0; 	
}

void path (int n, vector < vector <int> > A, int f, int l, vector <int> &v)
{
	if (l < f) swap(l,f);
	//int prev = 10;
	int current = l;
	cout<<l<<' ';
	while (current != f && current != -1) {
		current = v[current]; 
		cout<<current<<' ';
	}
	if (current == -1) cout<<"No route";
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
   	 cout<<bfs(n,adjMatrix, 1, 5, visit)<<endl;
   	 path(n,adjMatrix,2,4,visit);
}

