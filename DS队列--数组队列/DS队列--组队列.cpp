#include<iostream>
#include<string>
#include<queue>
using namespace std;
bool find(queue<int> q,int num)//�ж��ܲ����ڶ������ҵ�Ҫ�ҵ�Ԫ��
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
	queue<int>* q;//��������������ڴ���ʼ�Ķ���
	queue<int>* q1;//����������ڴ��ȡ������Ķ���
	//��һ������������Ѿ����ڵ�ȡ���е���������
	int xl[200];
	int z = 0;//q1�д�ŵĶ�����q�е����
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
		for (int i = 1; i <= t; i++)//��q������û����һ����
		{
			if (find(q[i], num))//����ҵ���
			{
				
				//���q1��ʲô��û�У�ֱ�Ӱ����ŵ�q1
				if (q1[1].empty()) { q1[1].push(num); xl[z] = i; z++; break; }//xl[z]���������ԭ���������ҵ��������ڵڼ������У������������ǲ����Ѿ������������ջ
					for (int k = 0; k < z; k++)//����ҵ�����q1���Ѿ����ڶ��У���ֱ�ӷ���ö���
					{
						int kk = xl[k];
						if (find(q[kk], num))
						{
							gg += 1;
							q1[k+1].push(num); break;
						}
					}
					if (gg == 0) {
					q1[z+1].push(num); xl[z] = i; z++; break;//q1���Ҳ����������·�һ������
					}
			}
			if (i == t)q1[i+1].push(num);//�Ҳ������ͷ��ڶ��е����һ��
		}
	}
	else if (str == "DEQUEUE")
	{
		sum += 1;
	}
	}
	return 0;
}
