#include<iostream>
#include<queue>
using namespace std;
int main()
{
	int n,t,ta,tb,tc,na,nb,nc;
	char z;
	cin >> n;
	queue<char>myQA;
	queue<char>time;
	na = 0; nb = 0; nc = 0;
	ta = 0; tb = 0; tc = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> z;
		myQA.push(z);
	}
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		time.push(t);
	}
	while (!myQA.empty())
	{
		char itemp = myQA.front();
		if (itemp == 'A')
		{
			ta += time.front();
			na += 1;
			time.pop();
			myQA.pop();
		}
		if (itemp == 'B')
		{
			tb += time.front();
			nb += 1;
			time.pop();
			myQA.pop();
		}
		if (itemp == 'C')
		{
			tc += time.front();
			nc += 1;
			time.pop();
			myQA.pop();
		}
	}
	int av = ta / na;
	int bv = tb / nb;
	int cv = tc / nc;
	cout << av << endl;
	cout << bv << endl;
	cout << cv << endl;
	
	return 0;
}
//8
//A B C B C A A A
//10 20 30 40 50 60 70 80