#include<iostream>
#include<string>
using namespace std;
int searchLong(string str)
{
	int len = str.length();
	int num = 0;//�����ظ��Ӵ��ĳ���
	int num1 = 0;//�����ʱ�ظ��Ӵ��ĳ���
	if (len == 1)return -1;
	for(int i=1;i<len;i++)//�������е���ĸһ������֮ǰ����ĸ�Ƚ�
		for (int j = 0; j <= i - 1; j++)
		{
			if (i == j + 1 && str[i] == str[j]) { num1 += 1; i++; continue; }//������������ظ���ĸ
			else if (num1 != 0&&i == j + 1 && str[i] != str[j]) {//�����������ĸ��ֹ��
					num1 = (num1+1) / 2; if (num < num1)num = num1; i--; break;//������ȾͰѶ�ӵ�i����ȥ��������������ĸ����ظ��Ӵ���Ҫ����2
			}
			if (str[i] == str[j]) { num1 += 1; i++; }//�����������ظ���ĸ����ȾͰ���ʱ�����ȼ�1��iҲ�����һ����ĸ
			else if (num1!=0&&str[i] != str[j]) { if (num < num1)num = num1; num1 = 0; i--; break; }//������ȾͰѶ�ӵ�i����ȥ
		}
	if (num == 0)return -1;
	else return num;
}
int main()
{
	int t;
	string str;
	cin >> t;
	while (t--)
	{
		cin >> str;
		cout << searchLong(str) << endl;
	}
	return 0;
}
//3
//abcaefabcabc
//szu0123szu
//szuabcefg