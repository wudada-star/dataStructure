#include<iostream>
using namespace std;
int main()
{
	int t;
	int a[2][3];
	int* g;
	int* k;
	cin >> t;
	while (t--)
	{
		for(int i=0;i<2;i++)
			for (int j = 0; j < 3; j++)
			{
				cin >> a[i][j];
		}
		g = &a[0][2];
		k = &a[1][2];//�������ÿһ��һ��ָ�룬Ȼ�����������ø��е�Ԫ��
		for (int j = 0; j < 3; j++)
		{
				cout << *g << " "<<*k<<" ";
				g--,k--;
			cout << endl;
		}
	}
	return 0;
}