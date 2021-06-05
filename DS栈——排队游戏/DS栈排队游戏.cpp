#include<iostream>
#include<stack>
#include<string>
using namespace std;
struct data1
{
	int i;
	char str;
};
int main()
{
	stack<data1>sta;
	string dui;
	cin >> dui;
	int n = dui.length();
	for (int i = 0; i < n; i++)
	{
		if (sta.empty()) {
			sta.push({ i, dui[i] });
		}
		else if (dui[i] != sta.top().str)
		{
			cout << sta.top().i << " " << i << endl;
			sta.pop();
		}
		else
		{
			sta.push({ i, dui[i] });
		}
	}
	return 0;
}
//((()(())())(()))