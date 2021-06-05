#include<iostream>
using namespace std;
int main()
{
	int n, k,num,t;
	int sum = 0;//查找的次数
	cin >> n;
	int* s = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		s[i] = num;
	}
	cin >> k;
	int* ss = new int[k];
	for (int i = 0; i < k; i++)
	{
		cin >> num;
		ss[i] = num;
	}
	cin >> t;
	while (t--)
	{
		sum = 0;
		cin >> num;
		for (int i = 0; i < k; i++)
		{
			sum += 1;
			if (num <= ss[i])//要找的值比索引的最大值小就进入该块
			{
				int low = n / k*i;//块的最低序号
				int h = low + n / k;//块的最高序号
				int j;
				int jj = 0;//找到了就变为1
				for ( j = low; j < h; j++)
				{
					sum += 1;
					if (num == s[j]) { cout << j + 1 << "-" << sum << endl; jj = 1; break; }
				}
				if (jj == 0)cout << "error" << endl; break;
			}
			if (num > ss[k - 1]) { cout << "error" << endl; break; }
		}
	}
	return 0;
}
