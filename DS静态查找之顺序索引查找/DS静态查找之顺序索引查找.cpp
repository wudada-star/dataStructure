#include<iostream>
using namespace std;
int main()
{
	int n, k,num,t;
	int sum = 0;//���ҵĴ���
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
			if (num <= ss[i])//Ҫ�ҵ�ֵ�����������ֵС�ͽ���ÿ�
			{
				int low = n / k*i;//���������
				int h = low + n / k;//���������
				int j;
				int jj = 0;//�ҵ��˾ͱ�Ϊ1
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
