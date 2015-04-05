#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool pred(int a, int b)
{
	return a < b;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	vector<int> amount;
	int buff;
	while(cin>>buff){
		amount.push_back(buff);
	}
	sort(amount.begin(), amount.end(), pred);
	int median  = n / 2 + 1;
	int sum = 0;
	for (int i = 0; i < median; i++){
		sum += amount[i]/2 + 1;
	}
	cout<<sum;

}