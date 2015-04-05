
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

int partition(vector <int> &, int, int);

void sort(vector <int> &A, int low, int high)
{
	if (high > low){
	int s = partition(A,low,high);
	sort(A,low, s-1);
	sort(A, s, high);
	}
}

int partition(vector <int> &A, int low, int high) 
{
	int i = low;
	int j = high;
	int p = A[(low+high)/2];
	while (i <= j){
		while (A[i] < p){
			i++;
		}
		while (p < A[j]) {
			j--;
		}
		if (i<=j) {
			swap(A[i],A[j]);
			i++;
			j--;
		}
	}
	return i;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	vector <int> A(100);
	int n;
	cin>>n;
	for (int i = 0; i< n; i++) {
		cin>>A[i];
	}
	sort(A,0,n-1);
		for (int i = 0; i< n; i++) {
		cout<<A[i]<<' ';
	}
}