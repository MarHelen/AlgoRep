#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string s;
	int n;
	cin>>n;
	cin>>s;
	int counter = 0;
	vector<int> inter(150,0);
	int max = n/5;
	int amount = 0;
	for (int i = 1; i < max; i++){
		int j = 0;
		amount = 0;
		while (s[j]=='.'){j++;}
		if (n - j < 5*i) break;
		while(j < n-i){
			j += i;
			if (s[j] == '*') {amount++;}
			if (amount == 4) {cout<<"yes"; break;}
		}
		if (amount == 4) {break;}
	}
	if (amount < 4) cout<<"no";

}