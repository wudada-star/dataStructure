//主要是学习STL的使用
#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main()
{
	int t;
	string str;
	stack<char>s;
	cin >> t;
	while (t--)
	{
	cin >> str;
	int len = str.length();//测量字符串的长度
	for (int i = 0; i < len; i++)
	{
		s.push(str[i]);//将字符压入栈中
	}
	while (!s.empty())
	{
		char c2 = s.top();//取出栈顶
		cout << c2;
		s.pop();//将栈顶删除
	}
	cout << endl;
	}
	return 0;
}