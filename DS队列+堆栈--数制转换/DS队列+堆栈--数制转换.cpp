//#include<iostream>
//#include<stack>\
//#include<iomanip>
//#include<queue>
//using namespace std;
//int main()
//{
//	int t,k;
//	double n;
//	stack<int>zs;
//	queue<int>xs;
//	cin >> t;
//	while (t--)
//	{
//		cin >> n >> k;
//		int z = n;//ȡ��������
//		double x = n - z;//ȡС������
//		while (z != 0)//���������ֽ��н���ת��
//		{
//			int itemp = z % k;
//			zs.push(itemp);
//			 z = z / k;
//		}
//		int sum = 0;//С��ֻҪ3λ
//		while (sum!=3)//��С�����ֽ��н���ת��
//		{
//			int itemp = x * k/1;//ȡС���˽��ƺ����������
//			xs.push(itemp);
//			x = x*k - itemp;//ȡС������
//			sum += 1;
//		}
//		while (!zs.empty())
//		{
//			if (zs.top() == 10)cout << 'A';
//			else if (zs.top() == 11)cout << 'B';
//			else if (zs.top() == 12)cout << 'C';
//			else if (zs.top() == 13)cout << 'D';
//			else if (zs.top() == 14)cout << 'E';
//			else if (zs.top() == 15)cout << 'F';
//			else cout << zs.top();
//			zs.pop();
//		}
//		cout << '.';
//		while (!xs.empty())
//		{
//			if(xs.front() == 10)cout << 'A';
//			else if (xs.front() == 11)cout << 'B';
//			else if (xs.front() == 12)cout << 'C';
//			else if (xs.front() == 13)cout << 'D';
//			else if (xs.front() == 14)cout << 'E';
//			else if (xs.front() == 15)cout << 'F';
//			else cout << xs.front();
//			xs.pop();
//		}
//		cout << endl;
//	}
//	return 0;
//}
//2
//19.125 2
//15.125 16
#include <iostream>
#include <queue>
#include <string>
#include<iomanip>
#include<stack>
#include<math.h>
#include<cmath>
using namespace std;
class exchange
{
public:
    void test()
    {
        stack<int>Z;
        queue<int>X;
        double n;
        int k;
        int sum = 0;//�洢С������λ����3λ��ֹͣ¼��
        cin >> n >> k;
        int z;
        double x;
        z = floor(n);
        x = n - z;
        if (z == 0)
        {
            Z.push(0);
        }
        else
        {
            while (z)
            {
                Z.push(z % k);
                z = z / k;
            }
        }
        if (x == 0)
        {
            X.push(0);
            X.push(0);
            X.push(0);
            sum = 3;
        }
        else
        {
            while (x)
            {
                if (sum != 3)//3λ��ֹͣ¼��
                {
                    X.push(floor(x * k));
                    if (x * k > 1)
                    {
                        x = x * k - int(x * k);
                    }
                    else
                    {
                        x = x * k;
                    }
                    sum += 1;
                }
                else break;
            }
            while (sum != 3)//���С���㲻��3λ�Ͳ�0
            {
                X.push(0);
                sum += 1;
            }
        }
        while (!Z.empty())
        {
            display(Z.top());
            Z.pop();
        }
        cout << ".";
        while (!X.empty()&&sum!=0)
        {
        int a = X.front();//�����һ��д����ѭ��֮�⣬����С���������
            display(a);
            X.pop();
            sum--;
        }
        cout << endl;

    }
    void display(int j)
    {
        if (j < 10)
            cout << j;
        else if (j == 10)
            cout << "A";
        else if (j == 11)
            cout << "B";
        else if (j == 12)
            cout << "C";
        else if (j == 13)
            cout << "D";
        else if (j == 14)
            cout << "E";
        else if (j == 15)
            cout << "F";
    }
};
int main()
{
    int t;
    cin >> t;
    class exchange s;
    while (t--)
    {
        s.test();
    }
    return 0;
}