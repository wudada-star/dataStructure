#include<iostream>
#include <iomanip>
#include<cmath>
using namespace std;
class Point
{
	double x, y;
public:
	Point()
	{
		cout << "Constructor." << endl;
	}
	~Point()
	{
		cout << "Distructor." << endl;
	}
	Point(double x_value, double y_value)
	{
		x = x_value; y = y_value;
	}
	Point(const Point& p)
	{
		x = p.x;
		y = p.y;
	}
	double getX()
	{
		return x;
	}
	double getY()
	{
		return y;
	}
	void setXY(double x1, double y1)
	{
		x = x1; y = y1;
	}
	void setX(double x_value)
	{
		x = x_value;
	}
	void setY(double y_value)
	{
		y = y_value;
	}
	double getDisTo(const Point& p)
	{
		return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
	}
};
int main()
{
	int t, n,index1,index2;
	double x, y,max;
	float dis;
	cin >> t;
	while (t--)
	{
		cin >> n;
		Point* p = new Point[n];//构建类的数组
		for (int i = 0; i < n; i++)
		{
			cin >> x >> y;
			p[i].setXY(x,y);
		}
		max = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				double dis = p[i].getDisTo(p[j]);//用类的数组方式调用函数
				if (dis > max)
				{
					max = dis;
					index1 = i;
					index2 = j;
				}
			}
		}
		cout<<"The longeset distance is "<< fixed << setprecision(2) << max<<",between p["<<index1<<"] and "<<"p["<<index2<<"]."<<endl;
	delete []p;
	}
	return 0;
}