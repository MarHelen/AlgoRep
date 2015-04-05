#include <iostream>
#include <stdio.h>

using namespace std;

int min(int a, int b)
{
	if (a < b) return a;
	else return b; 
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout); 
	long long i = 1;
	long long n, k;
	long long p = 0;
	cin>>n>>k;
	while(i < k && i < n){
		i += i;
		p++;
	}
	if (k < n) {
	if ((n-i) % k) cout<<p+(n-i)/k+1;
	else cout<<p+(n-i)/k; }
	else cout<<p;
}