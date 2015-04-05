#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <math.h>
#include <map>
#include <set>
#include <memory.h>
#include <numeric>
#include <assert.h>
#include <iomanip>

using namespace std;

int congr(vector<int> num, int n)
{
	while () {
		
	}
}

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	vector <int> num;
	char c;
	//getchar(cin, c);
	int n = 0;
	while (cin>>c) {
		//cin.get(c);
		num.push_back(int(c-'0'));
		n++;
	}
	cout<<congr(num, n);
	return 0;
}
