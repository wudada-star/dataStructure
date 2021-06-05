#include<iostream>
#include<string>
using namespace std;
int main()
{
	int t,n;
	cin >> t;
	const char* p[12] = { "January" ,"February","March","April","May","June","July","Aguest","September","October","November","December" };
	//string p[12] = { "January" ,"February","March","April","May","June","July","Aguest","September","October","November","December" };
	//string本来就是用来存储字符串的，所以string没有用指针来存储数组的
	while (t--)
	{
		cin >> n;
		if (n > 0 && n < 13)
		{
			cout <<p[n-1] << endl;
		}
		else cout << "error" << endl;
	}

	return 0;
}