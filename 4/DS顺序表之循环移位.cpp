#include<iostream>
using namespace std;
class SeqList
{
	int* list;////元素数组
	int size;//顺序表实际长度
	int maxsize;//顺序表最大长度
public:
	SeqList();
	~SeqList();
	void leftMove(int n);
	void rightMove(int n);
	void multiinsert(int i, int n, int item[]);
	void list_display();
};
void SeqList::leftMove(int n)
{
	for (int j = 0; j < n; j++)
	{
		list[size] = list[0];
		for (int i = 0; i < size; i++)
		{
			list[i] = list[i + 1];
		}

	}
}
void SeqList::rightMove(int n)
{
	for (int j = 0; j < n; j++)
	{

		list[size] = list[size - 1];
		for (int i = 0; i < n; i++)
		{
			list[size - 1 - i] = list[size - 2 - i];
		}
		list[0] = list[size];
	}
}
void SeqList::multiinsert(int i, int n, int item[])
{
	for (int k = 0; k < n; k++, i++)
	{
		if (size < 1000 && i <= size + 1) {

			for (int j = size; j >= i - 1; j--)//将插入位处和之后的元素向后面移一位
			{
				list[j + 1] = list[j];
			}
			list[i - 1] = item[k];
			size += 1;
		}
	}
}
void SeqList::list_display()
{
	for (int i = 0; i < size; i++)
	{
		cout << list[i] << " ";
	}
	cout << endl;
}
SeqList::~SeqList()
{
	delete[]list;
}
SeqList::SeqList()
{
	list = new int[1000];
	size = 0;
	maxsize = 1000;
}
int main()
{
	int n, direction;
	SeqList s;
	cin >> n;
	int* item = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> item[i];
	}
	s.multiinsert(1, n, item);
	s.list_display();
	for (int i = 0; i < 2; i++)
	{
		cin >> direction >> n;
		if (direction == 0)
		{
			s.leftMove(n);
			s.list_display();
		}
		else
		{
			s.rightMove(n);
			s.list_display();
		}
	}
	return 0;
}