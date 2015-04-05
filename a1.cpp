#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	string s;
	int n;
	cin>>n;
	cin>>s;
	int counter = 0;
	vector<int> inter(150,0);
	/*for (int i = 0; i < n; i++){
		if (s[i] == '.') inter[i] = 0;
		else { inter[i] = 1; counter++;} 
	}*/
	//int tries = n - counter;
	int max = n/5;
	int amount = 0;
	//if (counter < 5) cout<<"no";
	//else {
	for (int i = 1; i < max; i++){
		int j = 0;
		amount = 0;
		while(/*!inter[j]*/ s[j]=='.'){j++;}
		if (n - j < 5*i) break;
		while(j < n-i){
			j += i;
			if (/*inter[j]*/ s[j] == '*') {amount++;}
			//else break;
			if (amount == 4) {cout<<"yes"; break;}
		}
		if (amount == 4) {break;}
	}
	if (amount < 4) cout<<"no";
	//}
}