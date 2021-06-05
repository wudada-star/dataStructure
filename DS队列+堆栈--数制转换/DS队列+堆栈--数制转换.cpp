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
//		int z = n;//取整数部分
//		double x = n - z;//取小数部分
//		while (z != 0)//对整数部分进行进制转换
//		{
//			int itemp = z % k;
//			zs.push(itemp);
//			 z = z / k;
//		}
//		int sum = 0;//小数只要3位
//		while (sum!=3)//对小数部分进行进制转换
//		{
//			int itemp = x * k/1;//取小数乘进制后的整数部分
//			xs.push(itemp);
//			x = x*k - itemp;//取小数部分
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
        int sum = 0;//存储小数点后的位数，3位就停止录入
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
                if (sum != 3)//3位就停止录入
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
            while (sum != 3)//如果小数点不够3位就补0
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
        int a = X.front();//你把这一步写在了循环之外，所以小数输出错误
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