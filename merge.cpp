
#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <math.h>
#include <iomanip> 

using namespace std;



void merge(vector < pair <long long, int> > &, int, int, int);

void mergesort (vector < pair <long long, int> > &a, int high, int low)
{
	int mid;
	if (low < high) {
		mid = (high + low)/2;
		mergesort(a, mid ,low);
		mergesort(a,high,mid+1);
		merge(a, low, high, mid);
	}
}

void merge (vector < pair <long long, int> > &a, int low, int high, int mid)
{
        vector < pair <long long, int> > c;
	int i = low;
	int k = low;
	int j = mid + 1;
	while (i <= mid && j <= high) {
		if (a[i].second < a[j].second) {
			c.push_back( a[i]);
			k++;
			i++;
		}
		else {
            c.push_back( a[j]);
			k++;
			j++;
		}
	}
	while (i <= mid) {
                c.push_back( a[i]);
		k++;
		i++;
	}
	while (j <= high) {
                c.push_back(  a[j]);
		k++;
		j++;
	}
	for (i = low; i < k; i++) {
		a[i]= c[i-low];
	}

}



int main()
{
		freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    int n;
     cin>>n;
     vector < pair <long long, int> > table (n);
    for (int i = 0; i < n; i++) {
    	//cin>>table[i].first;
    	scanf("%Ld", &table[i].first);
    	//cin>>table[i].second;
    	scanf("%i", &table[i].second);
    }
    mergesort(table, n-1, 0);
 	 for (int i = n-1; i >= 0; i--) {
    	//cout<<table[i].first<<' ';
    	printf("%Ld ", table[i].first);
    	printf("%i\n", table[i].second);
    	//cout<<table[i].second<<endl; 
    }
}