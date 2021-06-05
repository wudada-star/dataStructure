#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main()
{
	stack<char>s;
	stack<char>s1;
	int t;
	string str;
	cin >> t;
	while (t--)
	{
		cin >> str;
		int len = str.length();
		for (int i = 0; i < len; i++)
		{
			if (!s.empty()&&str[i] == '#')s.pop();//Èç¹ûÕ»²»Îª¿ÕÇÒÎª·ûºÅ#£¬ÔòÉ¾³ýµôÕ»¶¥
			else if(s.empty() && str[i] == '#')continue;
			else s.push(str[i]);
		}
		if (s.empty())
			cout << "NULL" << endl;
		else {

			while (!s.empty())
			{
				char c2 = s.top();
				s1.push(c2);
				s.pop();
			}
			while (!s1.empty())
			{
				char c2 = s1.top();
				cout << c2;
				s1.pop();
			}
			cout << endl;
		}
	}
	return 0;
}