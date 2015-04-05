#include <iostream>
#include <vector>
#include <iomanip> 

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	vector <long long> dist;
	long long buff;
	double res = 0;
	while(cin>>buff){
		res += buff;
	}
	res /= n;
	cout<<fixed;
	cout<<setprecision(6)<<res;
}