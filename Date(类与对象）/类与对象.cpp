#include<iostream>
#include<iomanip>
using namespace std;
class Date {
	int year, month, day;
public:
	Date() :year(1900), month(1), day(1) {};
	Date(int y, int m, int d) :year(y), month(m), day(d) {};
	int getYear();
	int getMonth();
	int getDay();
	void setDate(int y, int m, int d);
	void print();
	void addOneDay();
};
int Date::getYear()
{
	return year;
}
int Date::getMonth()
{
	return month;
}
int Date::getDay()
{
	return day;
}
void Date::setDate(int y, int m, int d)
{
	year = y; month = m; day = d;
}
void Date::print()
{
	cout << "Today is " << setfill('0') << setw(4) << year << "/" << setfill('0') << setw(2) << month << "/" << setfill('0') << setw(2) << day << endl;
}
void Date::addOneDay()
{
	if (month == 12 && day == 31) { year += 1; month = 1; day = 1; }
	else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10) && day == 31)month += 1, day = 1;
	else if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 30)month += 1, day = 1;
	else if ((month == 2 && day == 28 && year % 400 == 0) || (month == 2 && day == 28 && year % 4 == 0 && year % 100 != 0))day += 1;
	else if ((month == 2 && day == 28 && year % 400 != 0) || (month == 2 && day == 28 && year % 4 != 0 && year % 100 != 0))month+=1,day= 1;
	else if ((month == 2 && day == 29)) month += 1, day = 1; 
	else day += 1;
	cout << "Tomorrow is " << setfill('0') << setw(4) << year << "/" << setfill('0') << setw(2) << month << "/" << setfill('0') << setw(2) << day << endl;
}
int main()
{
	int t, sum, a, b, c;
	cin >> t;
	sum = 1;
	while (t--)
	{
		cin >> a >> b >> c;
		Date d1(a, b, c);
		Date d2;
		if (sum % 2 != 0) { sum += 1; d1.print(); d1.addOneDay(); }
		else {
			d2.setDate(a, b, c);
			d2.print();
			d2.addOneDay();

		}
	}
	return 0;
}
