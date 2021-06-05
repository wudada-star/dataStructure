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
		k = &a[1][2];//给矩阵的每一行一个指针，然后让它来掉用该行的元素
		for (int j = 0; j < 3; j++)
		{
				cout << *g << " "<<*k<<" ";
				g--,k--;
			cout << endl;
		}
	}
	return 0;
}