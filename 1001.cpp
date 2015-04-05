#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <climits>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    vector <double> result;
	long long c;
	while (cin>>c)
	{
		//cout<<(floor((sqrt(c))*pow(10,4))/pow(10,4))<<endl;
		//cout.setf(ios::4,ios::sqrt(c))<<endl;
		result.push_back(sqrt(c));
		//cout<<sqrt(c)<<endl;
	}
	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(4); 
	int size = result.size();
	for (int i = size-1; i >= 0; i--)
	{
		cout.setf(ios::fixed, ios::floatfield);
		cout.precision(4); 
		cout<<result[i]<<endl;
	}
	return 0;
}