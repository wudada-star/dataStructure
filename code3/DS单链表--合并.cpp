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
	//~LinkList();
	ListNode* LL_index(int i);//返回第i个结点的指针，如果不存在返回NULL
	int LL_get(int i);//获取第i个元素的数据
	int LL_insert(int i, int item);//把数值item插入第i个位置
	int LL_del(int i);//删除第i个结点
	void LL_display();//输出单链表的内容
	void LL_merge(ListNode* La, ListNode* Lb);
};
void LinkList::LL_merge(ListNode* La, ListNode* Lb)
{
	
	La = La->next;
	Lb = Lb->next;
	ListNode* p;
	p = head;
	while (La!= NULL && Lb != NULL) {//需要A、B链表同时不为空
		if (La->data < Lb->data) {
			p->next = La;//调用函数的头节点的下一个结点指向La
			p = p->next;//p再指向下一个结点
			La = La->next;//La链表指向下一个位置
		}
		else if (La->data == Lb->data) {
			p->next = La;//将a或b的其中一个元素给p
			p = p->next;//p再指向下一个结点
			La = La->next;  //如果A、B的元素相等，则A、B的指针向后移位
			Lb = Lb->next;
		}
		else if (La->data > Lb->data) {
			p->next = Lb;//调用函数的头节点的下一个结点指向Lb
			p = p->next;//p再指向下一个结点
			Lb = Lb->next;//Lb链表指向下一个位置
		}
	}
	if (La != NULL&&Lb==NULL) {    //如果B遍历完了，A未遍历完，则将A的剩余部分接到C链表尾部
		p->next = La;
		p = p->next;//p再指向下一个结点
		La = La->next;
	}
	if (La == NULL && Lb != NULL) {    //如果A遍历完了，B未遍历完，则将B的剩余部分接到C链表尾部
		p->next = Lb;
		p = p->next;//p再指向下一个结点
		Lb = Lb->next;
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
//LinkList::~LinkList()//链表回收，要逐个结点回收
//{
//	ListNode* p, * q;
//	p = head;
//	while (p != NULL)
//	{
//		q = p;
//		p = p->next;
//		delete q;
//	}
//	len = 0;
//	head = NULL;
//
//}
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
	int n,m, data;
	LinkList l1;
	LinkList l2;
	LinkList l3;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> data;
		l1.LL_insert(i, data);
	}
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> data;
		l2.LL_insert(i, data);
	}
	l3.LL_merge(l1.head, l2.head);
	l3.LL_display();
	return 0;
}
