#include<iostream>
#include<queue>
using namespace std;
int main()
{
	int n,num;
	queue<int>q;
	queue<int>a;
	queue<int>b;
	cin >> n;
	while (n--)
	{
		cin >> num;
		q.push(num);
	}
	while (!q.empty())
	{
		if (q.front() % 2 == 1)
		{
			a.push(q.front());
			q.pop();
		}
		else
		{
			b.push(q.front());
			q.pop();
		}
	}
	int flag = 0;
	while (!a.empty() || !b.empty())
	{
		for (int i = 0; i < 2; i++)
		{
			if (!a.empty())
			{
				if (flag++ > 0)cout << " ";
				cout << a.front();
				a.pop();
			}
			else break;
		}
		if (!b.empty())
		{
			if (flag++ > 0)cout << " ";
			cout << b.front();
			b.pop();
		}
	}
	return 0;
}
//8 2 1 3 9 4 11 13 15