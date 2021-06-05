#include<iostream>
#include<cmath>
using namespace std;

void find(int num)
{
	double low = 0; double high = num;
	double mid;
	mid = (low + high) / 2;
	while (fabs(mid*mid-num)>=0.00001)
	{
		mid = (low + high) / 2;
		 if (num < mid * mid)high = mid ;
		else low = mid;
	}
	printf("%.3lf\n", mid);
}
int main()
{
	int n,num;
	cin >> n;
	while (n--)
	{
		cin >> num;
		find(num);
	}
}
