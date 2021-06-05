#include<iostream>
using namespace std;
#define ok 0;
#define error -1;
class SeqList
{
private:
	int* list;//元素数组
	int maxsize;//顺序表最大长度
	int size;//顺序表实际长度

public:
	SeqList();
	~SeqList();
	int list_size();//获取顺序表实际长度
	int list_insert(int i, int item);//插入一个元素，参数是插入的数值和位置
	int list_del(int i);//删除一个元素，参数是删除的位置
	int list_get(int i);//获取一个元素，参数是获取的位置
	void list_display();
};
int SeqList::list_size()
{
	return size;
}
int SeqList::list_get(int i)
{
	if (i <= size&&i>0) {
		cout << list[i - 1] << endl;
		return ok;
	}
	else cout << "error" << endl;
	return error;
}

int SeqList::list_del(int i)//删除
{
	if (i <= size) {

		for (int j = i - 1; j < size; j++)//将删除位包括之后的数向前移一位
		{
			list[j] = list[j + 1];
		}
		size -= 1;
		return ok;
	}
	else return error;
}
int SeqList::list_insert(int i, int item)//插入
{
	if (size < 1000 && i <=size+1) {//要注意插入的地方要连续，即只有6个元素，不能直接插在第8位

		for (int j = size; j >= i - 1; j--)//将插入位处和之后的元素向后面移一位
		{
			list[j + 1] = list[j];
		}
		list[i - 1] = item;
		size += 1;
		return ok;
	}
	else return error;
}
void SeqList::list_display()
{
	cout << size<<" ";
	for (int i = 0; i < size; i++)
	{
		cout << list[i] << " ";
	}
	cout << endl;
}
SeqList::SeqList()
{
	maxsize = 1000;
	size = 0;
	list = new int[maxsize];
}
SeqList::~SeqList()
{
	delete[]list;
}
int main()
{
	int t,item,wz,data;
	SeqList s;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> item;
		s.list_insert(i + 1, item);
	}
	s.list_display();
	for (int i = 0; i < 2; i++)
	{
	cin >> wz >> data;
	if (!s.list_insert(wz, data))//if判断语句中如果是！=-1，即为0，在判断语句中只有0和1
	{
		s.list_display();
	}
	else cout << "error" << endl;
	}
	for (int i = 0; i < 2; i++)
	{

	cin >> wz;
	if (!s.list_del(wz))
	{
		s.list_display();
	}
	else cout << "error" << endl;
	}
	cin >> wz;
	s.list_get(wz);
	cin >> wz;
	s.list_get(wz);
	return 0;
}
