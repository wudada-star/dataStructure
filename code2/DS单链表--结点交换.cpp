#include<iostream>
using namespace std;
#define ok 0;
#define error -1;
class ListNode
{
public:
	int data;
	ListNode* next;
	ListNode() {
		next = NULL;
	}
};
class LinkList
{
public:
	ListNode* head;//头节点
	int len;
	LinkList();
	~LinkList();
	ListNode* LL_index(int i);//返回第i个结点的指针，如果不存在返回NULL
	int LL_get(int i);//获取第i个元素的数据
	int LL_insert(int i, int item);//把数值item插入第i个位置
	int LL_del(int i);//删除第i个结点
	void LL_display();//输出单链表的内容
	void swap(int p, int q, ListNode* cur1, ListNode* cur2);//将要交换的两个结点的位置和指针传入
};
void LinkList::swap(int p, int q,ListNode* cur1, ListNode* cur2)
{
	int s, b;
	if (p > q)//将位置在前面的结点给s，位置靠后的结点给b
	{
		 b = p;  s = q;
	}
	else { b = q; s = p; }
	ListNode* curs = LL_index(s);//获取s处的指针
	ListNode* curb = LL_index(b);//获取b处的指针
	if (curs->next != curb)//分类讨论，当s的下一个位置不是b时
	{

	ListNode* cursq = LL_index(s - 1);//将s处的前一个指针给cursq
	ListNode* curbq = LL_index(b - 1);//将b处的前一个指针给curbq
	ListNode* tmp1 = cursq->next->next;//s的下一个指针给tmp1
	ListNode* tmp2 = curbq->next->next;//b的下一个指针给tmp

	cursq->next = curb;//b的位置转到s本来前一个指针的下一个指针
	curb->next = tmp1;//b的下一个指针是s本来的下一个指针
	curbq->next = curs;//s的位置转到b本来前一个指针的下一个指针
	curs->next = tmp2;//s的下一个指针是b本来的下一个指针
	
	}
	else
	{
		//当s的下一个位置刚好是b时
		ListNode* curr = LL_index(s - 1);//小序号的前一个结点
		ListNode* curr1 = curb->next;//大序号的后一个结点
		ListNode* curr2 = curb;//大序号地址
		curr->next = curr2;
		curr2->next = curs;
		curs->next = curr1;

	}


}
ListNode* LinkList::LL_index(int i)
{

	if (i <= len && i >= 0)
	{
		int j = 0;//单链表要一个一个找直到找到，所以j就是记录找到第几个
		ListNode* cur = head;//从链表头结点开始访问，可以返回头节点，头节点不是NULL
		while (j != i)
		{
			cur = cur->next;
			j++;
		}
		return cur;
	}
	else return NULL;

}

int LinkList::LL_insert(int i, int item)
{
	ListNode* curr = LL_index(i - 1);
	if (curr != NULL)
	{
		ListNode* x = new ListNode();//开辟新的节点空间
		x->next = curr->next;//将原来节点的下一个结点作为x的下一个结点
		curr->next = x;//原来节点的下一个结点是x
		len += 1;
		x->data = item;
		return ok;
	}
	else
		return error;
}

LinkList::LinkList()
{
	head = new ListNode();
	len = 0;//头节点不算链表的长度，所以是0
}
LinkList::~LinkList()//链表回收，要逐个结点回收
{
	ListNode* p, * q;
	p = head;
	while (p != NULL)
	{
		q = p;
		p = p->next;
		delete q;
	}
	len = 0;
	head = NULL;

}
void LinkList::LL_display()
{
	ListNode* p;
	p = head->next;//这里的head是调用函数的链表的head
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
int main()
{
	int n, data, wz1,wz2;
	LinkList l;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> data;
		l.LL_insert(i, data);
	}
	l.LL_display();
	for (int i = 0; i < 2; i++)
	{
		cin >> wz1 >> wz2;
		ListNode* cur1 = l.LL_index(wz1);
		ListNode* cur2 = l.LL_index(wz2);
		if (cur1 != NULL && cur2 != NULL)
		{
	l.swap(wz1, wz2,  cur1,cur2);
			l.LL_display();
		}
		else cout << "error" << endl;
	}
	
}
//5 11 22 33 44 55 
//4 1
//2 6
