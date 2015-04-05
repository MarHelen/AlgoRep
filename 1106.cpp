#include <iostream>
#include <queue>
#include <vector>
#include <stdio.h>

using namespace std;

int amount = 0;
vector <queue <int> > qu(102);

void build_queue(int n, int f, vector < vector <int> > A, vector <int> &v)
{
   for (int i = 1; i <= n; i++)
      if (A[f][i] == 1 && v[i] == 0){
         //cout<<i<<' ';
         qu[f].push(i);}

  // cout<<endl;
}

void dfs(int n, vector < vector <int> > A, int prev, int f, vector <int> &v)
{
	if (v[f] == 0) {
   build_queue(n,f,A,v);
   if (v[prev] > 0) { v[f] = -1; amount++;}
   else { v[f] = 1;  } }
	//cout<<f<<' '<<l<<endl;
   int current;
   while(qu[f].size()){
      current = qu[f].front();
      qu[f].pop();
      dfs(n,A,f,current,v);
   }
   v[f] *= 2;	
}


int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);  
 	int n;
 	int res = 0;
 	cin>>n;
 	vector <int> visit(102);
 	vector < vector <int> > adjMatrix(102, vector <int> (102));
 	int buff, first;
 	for(int i = 1; i <= n; i++){
 		visit[i] = 0;
 		cin>>buff;
 		if (!buff) res = 1;
 		while(buff){
 			adjMatrix[i][buff] = 1;
 			cin>>buff;
 		}
 	}
 	int full = 1;
   	 while (full){
   	 dfs(n,adjMatrix, full, full, visit);
   	 full = 0;
   	 for (int i = 1; i <= n; i++){
   	 	if (visit[i] == 0) {full = i; break;}
   	 }
   	}
   	if (res) cout<<'0';
   	else {
   	cout<<amount<<endl;
   	for (int i = 1; i <= n; i++){
   		if (visit[i] < 0)
   			cout<<i<<' ';
   	}}

}