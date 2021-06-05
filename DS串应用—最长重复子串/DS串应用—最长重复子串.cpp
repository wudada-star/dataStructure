#include<iostream>
#include<string>
using namespace std;
int searchLong(string str)
{
	int len = str.length();
	int num = 0;//存放最长重复子串的长度
	int num1 = 0;//存放临时重复子串的长度
	if (len == 1)return -1;
	for(int i=1;i<len;i++)//将主串中的字母一个个与之前的字母比较
		for (int j = 0; j <= i - 1; j++)
		{
			if (i == j + 1 && str[i] == str[j]) { num1 += 1; i++; continue; }//如果是连续的重复字母
			else if (num1 != 0&&i == j + 1 && str[i] != str[j]) {//如果连续的字母终止了
					num1 = (num1+1) / 2; if (num < num1)num = num1; i--; break;//如果不等就把多加的i减回去，由于连续的字母相等重复子串是要除以2
			}
			if (str[i] == str[j]) { num1 += 1; i++; }//不是连续的重复字母，相等就把临时串长度加1，i也变成下一个字母
			else if (num1!=0&&str[i] != str[j]) { if (num < num1)num = num1; num1 = 0; i--; break; }//如果不等就把多加的i减回去
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