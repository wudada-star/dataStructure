#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main()
{
	int t,k=0;//��k���ж��Ƿ����
	string str;
	cin >> t;
	while (t--)
	{ 
		stack<char>s;
		cin >> str;
		int len = str.length();
		for (int i = 0; i < len; i++)
		{
			//���������Щ��������ջ
			if (str[i] != '(' && str[i] != '[' && str[i] != '{' && str[i] != ')' && str[i] != ']' && str[i] != '}') { continue; }
			else if (str[i] == '(' || str[i] == '[' || str[i] == '{')
			{
				s.push(str[i]); continue;//�������ߵ����ţ�����ջ
			}
			//�ر�ע�⣬���ջΪ�յĻ�������s.top����ջ���ᱨ����Ϊջ��û�ж���������s.topҪ��s.empty���һ��ʹ��
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
				k = 1;//���ִ���ʱ��k��ֵΪ1
				cout << "error" << endl; break;
			}
			
		}
		if (s.empty()&&k!=1)
			cout << "ok" << endl;
		else if (!s.empty() && k != 1)//�п���ջ�л�ʣ�����ŵ����
		{
			cout << "error" << endl;
		}
		k = 0;//����ʹk����0
		while(!s.empty())
		{
			s.pop();//��ջ�еĶ������������Ӱ����һ��ʵ��
		}
	}
	return 0;
}