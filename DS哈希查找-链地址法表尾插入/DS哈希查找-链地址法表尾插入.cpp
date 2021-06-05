//首先建立哈希表，根据模数确定哈希表的数组长度（因为取模完所有的数都在模值内），每个数组元素都先生成一个头
//节点空间，由于链地址法采用的是头插法，所以当查找时，如果下一结点为NULL，
//说明该哈希表中没有要找的值，数组的下标是关键字（即取模后的值）模中的链表是地址，地址中的数据是记录。
#include<iostream>
using namespace std;
class node
{
public:
	int data;//存放数据，即记录
	int times;//记录查找的次数
	node* next;
	node()
	{
		next = NULL;
		data = 0;
	}
	node* insert(int n)//表尾插入
	{
		node* p = this;
		while (true)
		{
		if (!p->next )
		{
			node* pp = new node();
			pp->data = n;
			p->next = pp;
			return this;//将插入后的链表返回
		}
		else
		{
			p = p->next;
		}
		}
	}
	int search(int n)//在该结点的链中查找有没有要找的值
	{
		times = 1;
		node* p = this->next;//头节点是空的，要从第二个结点找起
		while (p)
		{
			if (n == p->data)
			{
				return n % 11;
			}
			else
			{
				p = p->next;
				times++;
			}
		}
		return -1;
	}
};
class hashTable
{
public:
	node** root;
	hashTable(int n)
	{
		root = new node * [n];//创建一个指针数组为哈希表
		for (int i = 0; i < n; i++)
		{
			root[i] = new node();//i为数组的下标即关键字，root[i]为地址
		}
	}
	int Hash(int k)
	{
		return k % 11;
	}
	void search(int k)
	{
		int hash = Hash(k);
		if (root[hash]->search(k) != -1)
		{
			cout << hash << " " << root[hash]->times << endl;
		}
		else
		{
			cout << "error" << endl;
			insert(k);
		}
	}
	void insert(int k)
	{
		int hash = Hash(k);
		root[hash] = root[hash]->insert(k);//把插入结点后的链送回给原来的结点
	}
};
int main()
{
	int n, data;
	while (cin >> n)
	{
	hashTable h(11);
	while (n--)
	{
		cin >> data;
		h.insert(data);
	}
	cin >> n;
	while (n--)
	{
		cin >> data;
		h.search(data);
	}
	}
}

//6
//11 23 39 48 75 62
//6
//39
//52
//52
//63
//63
//52