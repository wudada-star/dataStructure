#include<iostream>
using namespace std;
class ListNode
{
public:
	int data;//数据是在结点类中定义
	ListNode* next;//结点的前后指针也是在结点类中定义
	ListNode() {
		next = NULL;//让该结点的下一个结点的默认为NULL,因为新创建的结点是一个全新的，所以其下一个结点应该是NULL，其他结点才能加入到它的下一个
	}
};
class LinkList
{
public:
	ListNode* head;//头节点
	int len;//链表长度
	LinkList();//对成员变量进行初始化
	~LinkList();
	void insert(int N);
	void LL_del(int n);//删除重复的结点
	void LL_display();//输出单链表的内容
};
LinkList::LinkList()
{
	head = new ListNode();
	len = 0;//头节点不算链表的长度，所以是0
}
LinkList::~LinkList()//链表回收，要逐个结点回收
{
	ListNode* p, * q;
	p = head;//注意头节点的空间也要删除
	while (p != NULL)
	{
		q = p;
		p = p->next;
		delete q;
	}
	len = 0;
	head = NULL;

}
void LinkList::insert(int N)
{
	int data1;
	ListNode* cur = head;//将链表的头节点给表头cur
	for (int i = 1; i <=N; i++)
	{
		cin >> data1;
		ListNode* x = new ListNode();//创建一个结点空间
		cur->next = x;//把x结点插到头结点的下一个位置
		//x->next = head;//x的下一个结点是头节点
		cur = x;//表头指向x
		cur->data = data1;//给x结点赋值
		len += 1;
	}
}
void LinkList::LL_del(int n)
{
		ListNode* x = new ListNode();//创建一个结点空间
		x = head->next;
	for (int i = 2; i <= n; i++)
	{
		ListNode* y = new ListNode();//创建一个结点空间
		y = head->next;//从第一个结点开始
		x = x->next;//要进行比较的数,从第二个结点开始
		for (int j = 1; j < i-(n-len); j++)//要进行比较前的所有数字,这里要注意随着len的删除，遍历时的长度也会减小
		{
			if (x->data == y->data)
			{
				while (j != i - (n - len + 1))
				{
					y = y->next;//让y指到x的前一个结点
					j += 1;
				}
				y->next = x->next;
				len -= 1;
				break;
			}
			y = y->next;
		}
	}
}
void LinkList::LL_display()//输出单链表的内容
{
	cout << len << ":";
	ListNode* p;
	p = head->next;
	while (p)
	{
		cout << " " << p->data ;
		p = p->next;
	}
	cout << endl;
}
int main()
{
	int t, n, data;
	cin >> t;
	while (t--)
	{
		LinkList l;
		cin >> n;
		l.insert(n);
		l.LL_del(n);
		l.LL_display();

	}
	return 0;
}
//3
//10 1 2 3 4 1 2 10 20 30 20
//5 1 1 1 1 1
//6 20 22 22 22 22 22 20