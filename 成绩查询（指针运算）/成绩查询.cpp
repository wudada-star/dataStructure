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
		cout << *(--g) <<" ";//--֮��g��λ�û�䣬����ָ��Ҫ����ָ���м�
		g = &p[n / 2];
		cout << *(++g) << endl;
		g = &p[n / 2];
		cin >> k;
		d = k - (n / 2+1);//d��ʾ��Ŀ�е�����Ԫ�غ��м�Ԫ�صľ���
		cout << *(g+d) << endl;//g����ֱ�Ӽ�����Ҫ�䶯�ĵ�ַλ��
		cout << *g << endl;
	}
	return 0;
}