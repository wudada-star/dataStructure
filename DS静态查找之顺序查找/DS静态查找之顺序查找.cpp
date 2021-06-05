#include<iostream>
#include<queue>
using namespace std;
int find(queue<int>q, int num)//利用传值不改变原来地址中的值来做到队列遍历
{
	int n = q.size();
	for (int i = 1; i <= n; i++)
	{
		if (num == q.front())
		{
			return i;
		}
		q.pop();
	}
	return 0;
}
int main()
{
	int n, t,num;
	queue<int> q;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		q.push(num);
	}
	cin >> t;
	while (t--)
	{
		cin >> num;
		int z=find(q, num);
		if (z == 0) cout << "error" << endl;
		else cout << z << endl;
	}
	return 0;
}
