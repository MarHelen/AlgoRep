#include <iostream>
#include <stdio.h>
#include <set>
#include <string>

using namespace std;

int main()
{
		freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout); 
	set <string> shop;
	string temp;
	int m;
	int n = 0;
	cin>>m;
	getline(cin,temp);
	for (int i = 0; i < m; i++) {
		getline(cin,temp);
		//cout<<temp<<endl;
		if (shop.find(temp) != shop.end()) { n++;}
		else shop.insert(temp);
	}
	cout<<n;
}