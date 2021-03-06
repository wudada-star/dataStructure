#include<iostream>
using namespace std;
//建立一个结点函数
class node
{
public:
	int date;
	node* next;
	node()
	{
		next = NULL;//下一个位置肯定要置空，这样其他的指针才可以插入进去
	}
};

class list
{
public:
	int len;
	node* head;
	list()
	{
		head = new node();
		head->next = head;//因为题目说要是循环链表，所以head的下一个结点还是head
		head->date = 1;//因为约瑟夫环的第一个数就是1，头结点也赋值
		len = 1;
	}
	~list()
	{
		node* p, * q;
		p = head;
		while (p != NULL)
		{
			q = p;
			p = p->next;
			delete q;
		}
	}
	void insert(int n)
	{
		node* cur = head;//将链表的头节点给表头cur
		for (int i = 1; i < n; i++)//因为头节点也算，所以从1开始
		{
			node* x = new node();//创建一个结点空间
			cur->next = x;//把x结点插到头结点的下一个位置
			x->next = head;//x的下一个结点是头节点
			cur = x;//表头指向x
			cur->date = i + 1;//给x结点赋值
			len += 1;
		}
	}
	void display(node* cur)
	{
		cout << cur->next->date << " ";
		if (len == 1)cout << endl;
	}
	void del(node* cur)
	{
		if (len > 1)
		{
			cur->next = cur->next->next;
		}
		else
			head = NULL;

		len -= 1;
	}
	void search(int k, int s)
	{
		//将找到的顺便输出，并删除
		node* cur = head;//将链表的头节点给表头cur
		for (int i = 1; i != s; i++)
		{
			cur = cur->next;
		}
		
		while (len != 0)//当链表的长度不为0时
		{
			if (len == 1) {
				display(cur);
				del(cur); break; }
			for (int i = 1; i != k - 1; i++)
			{
				cur = cur->next;//要找的数的前一个数
			}
			display(cur);
			del(cur);
			cur = cur->next;//cur现在指向被删除的指针的下一个指针，因为在del中已经把要删除的结点删除，所以现在cur的下一个结点即原来要删除结点的下一个结点
		}
	}
};
int main()
{
	int t, n, k, s;
	while (cin >> n >> k >> s)
	{
		list a;
		a.insert(n);
		a.search(k, s);
	}
	return 0;
} 
