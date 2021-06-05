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
	void multiinsert(int i, int n, int item[]);
	void paixu();
	void list_display();

};
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
void SeqList::paixu()
{
	for (int i = 0; i < size-1; i++)
		for (int j =0; j < size - i-1; j++)
		{
			if (list[j] > list[j+1])
			{
				int temp = list[j];
				list[j] = list[j+1];
				list[j+1] = temp;
			}
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
	cout << size << " ";
	for (int i = 0; i < size; i++)
	{
		cout << list[i] << " ";
	}
	cout << endl;
}
int main()
{
	int n,k;
	SeqList s;
	cin >> n;
	int* item = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> item[i];
	}
	s.multiinsert(1, n, item);
	cin >> k;
	int* item1 = new int[k];
	for (int i = 0; i < k; i++)
	{
		cin >> item1[i];
	}
	s.multiinsert(n, k, item1);
	s.paixu();
	s.list_display();

	return 0;
}
//3 11 33 55
//5 22 44 66 88 99