#include<iostream>
using namespace std;
int main()
{
	int t,n;
	char type;

	cin >> t;
	while (t--)
	{
		cin >> type>>n;
		if (type == 'I')
		{
			int* g;
			int sum = 0;
			int* p = new int[n];
			for (int i = 0; i < n; i++)
			{
				cin >> p[i];
			}
			g = &p[0];
			for (int i = 0; i < n; i++)
			{
				sum += *g;
				g++;
			}
			cout << sum / n << endl;
		}
		if (type == 'C')
		{
			char* g;
			char* p = new char[n];
			char temp;
			for (int i = 0; i < n; i++)
			{
				cin >> p[i];
			}
			g = &p[0];
			temp = p[0];
			for (int i = 0; i < n; i++)
			{
				if (*g < *(g+1))//if (*g < *(++g))����д����ϵͳ����ʾ�и����ã��޷����м��㣬�����ü��������õ�g�ı����ָı���g�ı���
				{
					g++;
					temp = *g;
				}
			}
			g = &temp;
			cout << *g << endl;
		}
		if (type == 'F')
		{
			float temp;
			float* p = new float[n];
			float* g;
			for (int i = 0; i < n; i++)
			{
				cin >> p[i];
			}
			g = &p[0];
			temp = *g;
			for (int i = 0; i < n; i++)
			{
				if (*g > *(g+1))//if (*g > *(g++))
				{
					g++;//g�ĵ�ַ��û�����ж�����м�1
					temp = *g;
				}
			}
			g = &temp;
			cout << *g << endl;
		}

	}
	return 0;
}