#include <iostream>
#include <map>
#include <vector>
#include <stdio.h>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	map <int,int> cab;
	int n;
	int buff;
	cin>>n;
	map <int, int> :: iterator it;
	for (int i = 0; i < n; i++){
		cin>>buff;
		it = cab.find(buff);
		if (it != cab.end()) {
		it->second++; }
		else cab.insert(buff, 1);
	}
	int counter = 0; 
	for (auto: i){
		if (cab(i) == 4)
			counter++;
	}
	cout<<counter;
}