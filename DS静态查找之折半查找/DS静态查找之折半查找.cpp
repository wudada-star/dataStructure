#include<iostream>
#include<queue>
using namespace std;
struct node
{
	int sum;
	int key;
	int date;
};
int find(node*s,int num)
{
		int low = 1; int high = s->sum;
		int mid;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (s[mid].date == num)return s[mid].key;
			else if (num < s[mid].date)high = mid - 1;
			else low = mid + 1;
		}
	return 0;
}
int main()
{
	int n, t, num;
	cin >> n;
	node *s = new node[n+1];
	s->sum = n;
	for (int i = 1; i <= n; i++)
	{
		cin >> num;
		s[i].date = num;
		s[i].key = i;
	}
	cin >> t;
	while (t--)
	{
		cin >> num;
		int z = find(s,num);
		if (z == 0) cout << "error" << endl;
		else cout << z << endl;
	}
	return 0;
}
