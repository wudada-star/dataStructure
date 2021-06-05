#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main()
{
	int t,k=0;//用k来判断是否出错
	string str;
	cin >> t;
	while (t--)
	{ 
		stack<char>s;
		cin >> str;
		int len = str.length();
		for (int i = 0; i < len; i++)
		{
			//如果不是这些符号则不入栈
			if (str[i] != '(' && str[i] != '[' && str[i] != '{' && str[i] != ')' && str[i] != ']' && str[i] != '}') { continue; }
			else if (str[i] == '(' || str[i] == '[' || str[i] == '{')
			{
				s.push(str[i]); continue;//如果是左边的括号，则入栈
			}
			//特别注意，如果栈为空的话，采用s.top调用栈顶会报错，因为栈顶没有东西，所有s.top要和s.empty配合一起使用
			else if (!s.empty() && str[i] == ')' && s.top() == '(')
			{
				s.pop(); continue;
			}
			else if (!s.empty() && str[i] == ']' && s.top() == '[')
			{
				s.pop(); continue;
			}
			else if (!s.empty() && str[i] == '}' && s.top() == '{')
			{
				s.pop(); continue;
			}
			else
			{
				k = 1;//出现错误时将k赋值为1
				cout << "error" << endl; break;
			}
			
		}
		if (s.empty()&&k!=1)
			cout << "ok" << endl;
		else if (!s.empty() && k != 1)//有可能栈中还剩左括号的情况
		{
			cout << "error" << endl;
		}
		k = 0;//重新使k等于0
		while(!s.empty())
		{
			s.pop();//将栈中的东西清除，避免影响下一次实验
		}
	}
	return 0;
}