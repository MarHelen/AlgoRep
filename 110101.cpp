#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <map>
#include <set>
#include <memory.h>
#include <numeric>
#include <assert.h>

using namespace std;

vector<int> results(1000001);

void all_cycle ()
{
	for (int i = 0; i < 1000001; i++)
	{
		int counter = 1;
		int j = i;
		while (j > 1)
		{
			if (j % 2)
				j = j * 3 + 1;
			else j = j / 2;
			counter++;
		}
		results [i] = counter;
	}
}

int search (int a, int b)
{
	int max = 0;
	if (a < b)
	{for (int i = a; i <= b; i++)
	{
		if (results[i] > max)
			max = results[i];
	}}
	else
	for (int i = b; i <= a; i++)
	{
		if (results[i] > max)
			max = results[i];
	}	
	
	return max;
}


int main()
{
   
   // Comment next line to read from console.
   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);

   all_cycle();
   int a,b;
   
   while (cin>>a>>b) {
       cout<<a<<" "<<b<<" "<<search(a,b)<<endl;
   }

   return 0;
}