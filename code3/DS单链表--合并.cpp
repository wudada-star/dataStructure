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
	ListNode* head;//ͷ�ڵ�
	int len;
	LinkList();
	//~LinkList();
	ListNode* LL_index(int i);//���ص�i������ָ�룬��������ڷ���NULL
	int LL_get(int i);//��ȡ��i��Ԫ�ص�����
	int LL_insert(int i, int item);//����ֵitem�����i��λ��
	int LL_del(int i);//ɾ����i�����
	void LL_display();//��������������
	void LL_merge(ListNode* La, ListNode* Lb);
};
void LinkList::LL_merge(ListNode* La, ListNode* Lb)
{
	
	La = La->next;
	Lb = Lb->next;
	ListNode* p;
	p = head;
	while (La!= NULL && Lb != NULL) {//��ҪA��B����ͬʱ��Ϊ��
		if (La->data < Lb->data) {
			p->next = La;//���ú�����ͷ�ڵ����һ�����ָ��La
			p = p->next;//p��ָ����һ�����
			La = La->next;//La����ָ����һ��λ��
		}
		else if (La->data == Lb->data) {
			p->next = La;//��a��b������һ��Ԫ�ظ�p
			p = p->next;//p��ָ����һ�����
			La = La->next;  //���A��B��Ԫ����ȣ���A��B��ָ�������λ
			Lb = Lb->next;
		}
		else if (La->data > Lb->data) {
			p->next = Lb;//���ú�����ͷ�ڵ����һ�����ָ��Lb
			p = p->next;//p��ָ����һ�����
			Lb = Lb->next;//Lb����ָ����һ��λ��
		}
	}
	if (La != NULL&&Lb==NULL) {    //���B�������ˣ�Aδ�����꣬��A��ʣ�ಿ�ֽӵ�C����β��
		p->next = La;
		p = p->next;//p��ָ����һ�����
		La = La->next;
	}
	if (La == NULL && Lb != NULL) {    //���A�������ˣ�Bδ�����꣬��B��ʣ�ಿ�ֽӵ�C����β��
		p->next = Lb;
		p = p->next;//p��ָ����һ�����
		Lb = Lb->next;
	}
}

ListNode* LinkList::LL_index(int i)
{

	if (i <= len && i >= 0)
	{
		int j = 0;//������Ҫһ��һ����ֱ���ҵ�������j���Ǽ�¼�ҵ��ڼ���
		ListNode* cur = head;//������ͷ��㿪ʼ���ʣ����Է���ͷ�ڵ㣬ͷ�ڵ㲻��NULL
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
		ListNode* x = new ListNode();//�����µĽڵ�ռ�
		x->next = curr->next;//��ԭ���ڵ����һ�������Ϊx����һ�����
		curr->next = x;//ԭ���ڵ����һ�������x
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
	len = 0;//ͷ�ڵ㲻������ĳ��ȣ�������0
}
//LinkList::~LinkList()//������գ�Ҫ���������
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
