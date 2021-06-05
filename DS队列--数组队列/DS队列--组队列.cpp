#include<iostream>
#include<string>
#include<queue>
using namespace std;
bool find(queue<int> q,int num)//判断能不能在队列中找到要找的元素
{
	int n = q.size();
	for (int i = 0; i < n; i++)
	{
	if (q.front() == num)
		return true;
	q.pop();
	}
	 return false;
}
int main()
{
	int t,n,num,sum,k;
	sum = 0;
	string str;
	queue<int>* q;//这个队列数组用于存放最开始的对象
	queue<int>* q1;//这个队列用于存放取操作后的对象
	//用一个数组来存放已经存在的取队列的数组序列
	int xl[200];
	int z = 0;//q1中存放的队列在q中的序号
	cin >> t;
	q = new queue<int>[t+1];
	q1 = new queue<int>[t + 3];
	for (int i = 1; i <= t; i++)
	{
		cin >> n;
		while (n--)
		{
			cin >> num;
			q[i].push(num);
		}
	}
	while (1)
	{
	cin >> str;
	if (str == "STOP")
	{	
		k = 0;
			int flag = 0;
		while (sum--)
		{
			for (int i = 1; i <= t+1; i++)
			{
				while (!q1[i].empty())
				{
					int temp=q1[i].front();
					if (flag > 0)cout << " ";
					cout << temp;
					flag++;
					q1[i].pop();
					k = 1; break;
				}
				if (k == 1) { k = 0; break; }
			}
		}
			cout << endl;
			
			break;
	}
	else if (str == "ENQUEUE")
	{
	int gg = 0;
		cin >> num;
		for (int i = 1; i <= t; i++)//在q中找有没有这一个数
		{
			if (find(q[i], num))//如果找到了
			{
				
				//如果q1中什么都没有，直接把数放到q1
				if (q1[1].empty()) { q1[1].push(num); xl[z] = i; z++; break; }//xl[z]用来存放在原来队列中找到的数属于第几个队列，方便后面查找是不是已经将这个队列入栈
					for (int k = 0; k < z; k++)//如果找的数在q1中已经存在队列，则直接放入该队列
					{
						int kk = xl[k];
						if (find(q[kk], num))
						{
							gg += 1;
							q1[k+1].push(num); break;
						}
					}
					if (gg == 0) {
					q1[z+1].push(num); xl[z] = i; z++; break;//q1中找不到，就重新放一个队列
					}
			}
			if (i == t)q1[i+1].push(num);//找不到，就放在队列的最后一行
		}
	}
	else if (str == "DEQUEUE")
	{
		sum += 1;
	}
	}
	return 0;
}
