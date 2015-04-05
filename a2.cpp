#include <iostream>
#include <vector>
#include <string>

using namespace std;

long long count(long long c, long long hx, long long hy, long long wx, long long wy, int min)
{
		long long sum_h = 0;
	long long kx = c / wx - min;
	if (kx > 0) 
	{ sum_h = hx * kx;
	if (c - kx*wx >= wy) sum_h += ((c-kx*wx)/wy) * hy; }
	else sum_h = (c/wy)*hy;
	return sum_h;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	long long c, hr, hb, wr, wb;
	double hrt, hbt, wrt, wbt;
	cin>>c>>hrt>>hbt>>wrt>>wbt;
	hr = hrt;
	hb = hbt;
	wr= wrt;
	wb = wbt;
	double efr = double(hrt/wrt);
	double efb = double(hbt/wbt);
	//long long sum_h = 0;
	//long long kr = 0;
	//long long kb = 0;
	vector <long long> effort;
	long long buff;
	long long diff = ((wr < wb) ? wb/wr : wr/wb);
	//cout<<diff<<endl;
	for (long long i = 0; i <= diff; i++){
	if (efr <= efb){
		buff = count(c, hb, hr, wb, wr, i);
	}
	else {
		buff = count(c, hr, hb, wr, wb, i);
	}
	effort.push_back(buff);
	}
	for (long long i = 0; i <= diff; i++){
	if (efr > efb){
		buff = count(c, hb, hr, wb, wr, i);
	}
	else {
		buff = count(c, hr, hb, wr, wb, i);
	}
	effort.push_back(buff);
	}

	long long max = 0;
	for (long long i = 0; i < effort.size(); i++){
		cout<<effort[i]<<endl;
		if (effort[i] > max) max = effort[i];
	}
	cout<<max;

}