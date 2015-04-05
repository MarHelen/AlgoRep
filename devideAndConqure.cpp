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

using namespace std;


int merge (vector<int> &, int, int, int);

int count(vector<int> &A, int low, int high)
{
	int x = 0;
	int y = 0;
	int z = 0; 
	int inv = 0;
	if (high > low) {
	int mid = (low + high) /2;
	//cout<<"low-mid"<<' '<<low<<' '<<mid<<endl;
	x = count(A, low, mid);
	//cout<<"mid-high"<<' '<<mid+1<<high<<endl;
	y = count(A, mid+1, high);
	//cout<<"merge"<<' '<<low<<' '<<mid<<' '<<high<<endl;
	z = merge(A, low, mid+1, high);
	}
	inv = x + y + z;
	return inv;
}

int merge (vector <int> &A, int low, int mid, int high)
{
	int i,j,k;
	vector <int> C;
	i = low;
	j = mid;
	//k = mid;
	int inv_count = 0;
	int p = low;
	while ((i < mid) && (j <= high)) {
	if (A[i] <= A[j]){
		//C[p] = A[i];
		C.push_back(A[i]);
		i++;
		p++;
	}
	else {
		C.push_back(A[j]);
		//C[p] = A[j];
		j++;
		p++;
		inv_count += mid - i;
	}
	}
	while (i < mid) {
		C.push_back(A[i]);
		//C[p] = A[i];
		p++; 
		i++;
	}
	while (j <= high) {
		C.push_back(A[j]);
		//C[p] = A[j];
		p++; 
		j++;
	}
	//int l = 0;
	for (int h = low; h < p; h++){
		A[h] = C[h - low];
		//cout<<A[h]<<' ';
		//l++;
	}
	cout<<endl;
	return inv_count;

}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	vector <int> A(100);
	for (int i = 0; i < n; i++){
		cin>>A[i];
	}
	cout<<count(A, 0, n-1);
}