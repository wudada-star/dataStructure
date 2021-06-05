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
	void multidel(int i, int n);
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
 void SeqList::multiinsert(int i, int n, int item[])
{
	for (int k=0; k < n; k++,i++)
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
void SeqList::multidel(int i, int n)
{
	for (int k = 0; k < n; k++)
	{
	if (i <= size) {

		for (int j = i - 1; j < size; j++)//将删除位包括之后的数向前移一位
		{
			list[j] = list[j + 1];
		}
		size -= 1;
		
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
	int n,wz,k;
	SeqList s;
	cin >> n;
	int* item = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> item[i];
	}
	s.multiinsert(1, n,item);
	s.list_display();
	cin >> wz >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> item[i];
	}
	s.multiinsert(wz, k, item);
	s.list_display();
	cin >> wz >> k;
	s.multidel(wz, k);
	s.list_display();
	return 0;
}
