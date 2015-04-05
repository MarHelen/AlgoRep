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
int nx[] = {-1,-2,-2,-1,1,2,2,1};
int ny[] = {-2,-1,1,2,-2,-1,1,2};
string chess = "abcdefgh";

int amount(pair <char,int> position)
{
	int count = 0;
	int first = chess.find(tolower(position.first)) + 1;
	for(int i = 0; i < 8; i++)
	{
		if ( first + ny[i] < 9 && first + ny[i] > 0 && position.second + nx[i] < 9 && position.second + nx[i] > 0)
			{count++;}
	}
	return count;
}

int main()
{
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    pair <char,int> position;
    int n;
    string s;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
    	cin>>s;
    	position.first = s[0];
    	position.second =  int(s[1] - '0');
    	cout<<amount(position)<<endl;
    }

	return 0;
}