#include<iostream>
using namespace std;
#define ok 0;
#define error -1;
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
	ListNode* LL_index(int i);//返回第i个结点的指针，如果不存在返回NULL
	int LL_get(int i);//获取第i个元素的数据
	int LL_insert(int i, int item);//把数值item插入第i个位置
	int LL_del(int i);//删除第i个结点
	void LL_display();//输出单链表的内容
};
ListNode* LinkList::LL_index(int i)
{
		    
	if (i <= len&&i>=0)
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
int LinkList::LL_del(int i)
{
	ListNode* curr = LL_index(i-1);
	if (curr != NULL)
	{
		curr->next = curr->next->next;
		return ok;
	}
	else return error;
}
int LinkList::LL_insert(int i, int item)
{
	ListNode* curr = LL_index(i-1);
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
	ListNode *p, * q;
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
void LinkList::LL_display()
{
	ListNode* p;
	p = head->next;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
int main()
{
	int n,data,wz;
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
		cin >> wz >> data;
		if (!l.LL_insert(wz, data))
			l.LL_display();
		else cout << "error" << endl;
	}
	for (int i = 0; i < 2; i++)
	{
		cin >> wz;
		if (!l.LL_del(wz))
			l.LL_display();
		else cout << "error" << endl;
	}
	for (int i = 0; i < 2; i++)
	{
		cin >> wz;
		ListNode* curr = l.LL_index(wz);
		if (curr != NULL&&wz!=0)
			cout << curr->data << endl;
		else cout << "error" << endl;
	}
}
//4 5 9 15 36
//6 999
//5 999
//0 
//1
//5
//4