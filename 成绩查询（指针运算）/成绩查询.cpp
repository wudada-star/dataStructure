#include<iostream>
using namespace std;
int main()
{
	int t,n,k,d;
	cin >> t;
	while (t--)
	{
		cin >> n;
		int* p = new int[n];
		int* g;
		for (int i = 0; i < n; i++)
		{
			cin >> p[i];
		}
		g = &p[n / 2];
		cout << *(--g) <<" ";//--之后g的位置会变，所以指针要重新指回中间
		g = &p[n / 2];
		cout << *(++g) << endl;
		g = &p[n / 2];
		cin >> k;
		d = k - (n / 2+1);//d表示题目中的输入元素和中间元素的距离
		cout << *(g+d) << endl;//g可以直接加上想要变动的地址位数
		cout << *g << endl;
	}
	return 0;
}