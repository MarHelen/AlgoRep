#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool search_bi(const vector <int> &a, int key, int i, int j)
{
	int buf;
	if (a[i] == key || a[j] == key) return 1;
	if (key < a[i] || key > a[j]) return 0;
	while(j - i > 1){
		if (a[(i+j)/2] != key){
			if (a[(i+j)/2] < key) { i = (i+j)/2; }
			else { j = (i+j)/2; }
		}
		else return 1;
		//cout<<i<<' '<<j<<' ';
		search_bi(a,key,i,j);
	}
	return 0;
}

int pred(int a, int b)
{
	return a < b;
}


int main()
{
	freopen("input.txt","r",stdin);
	vector <int> a;
	int buff;
	int key;
	cin>>key;
	while(cin>>buff){
		a.push_back(buff);
	}
	sort(a.begin(),a.end(), pred);
	cout<<search_bi(a,key,0,a.size()-1)<<endl;
	/*for (vector <int> :: iterator it = a.begin(); it != a.end(); ++it ){
		cout<<*it<<' ';
	}*/
}