#include<iostream>//这道题是层次建树,先序遍历输出
using namespace std;
class biTree
{
public:
	int nn;
	int* ss;
	biTree(int n,int*s)
	{
		nn = n;
		ss = new int[nn];
		for (int i = 0; i < nn; i++)
		{
			ss[i] = s[i];
		}
	}
	void display(int pos)//这道题使用的是下一层左节点是上一层的两倍
	{
		if (pos < nn)
		{
			if (ss[pos] != 0)
				cout << ss[pos] << " ";
			display(pos * 2 + 1);
			display(pos * 2 + 2);
		}
	}
};
int main()
{
	int t, n,num;
	cin >> t;
	while (t--)
	{
		cin >> n;
		int* s = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> num;
			s[i] = num;
		}
		biTree b(n, s);
		b.display(0);
		cout << endl;
	}
	return 0;
}