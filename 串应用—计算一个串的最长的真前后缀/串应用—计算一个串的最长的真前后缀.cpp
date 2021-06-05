#include<iostream>
#include<string>
using namespace std;
string matched_Prefix_Postfix(string str)
{
	int num = 0;
	int num1 = 0;
	string s;//s默认为空
	int n = str.length();
	if (n == 1)return "empty";
	string* sq = new string[n];
	string* sh = new string[n];
	for (int i = 0; i < n-1; i++)
	{
		s = s+str[i];
		sq[i] = s;
	}
	s = "";//让字符串为空
	for (int i = n-1,j=0; i>0,j<n-1; i--,j++)
	{
		s = str[i] + s;
		sh[j] = s;
	}
	 s = "";
	for(int i=0;i<n-1;i++)
		for (int j = 0; j < n - 1; j++)
		{
			if (sq[i] == sh[i]) {
				num1 = sq[i].length();
				if (num1 > num)//存储最长的真前后缀
				{
					num = num1;
				s = sq[i];
				}
			}
		}
	if (s == "")return "empty";
	else return s;



}
int main()
{
	int n;
	string str;
	cin >> n;
	while (n--)
	{
		cin >> str;
		str=matched_Prefix_Postfix(str);
		cout << str << endl;
	}

	return 0;
}
