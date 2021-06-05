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
	~LinkList();
	ListNode* LL_index(int i);//���ص�i������ָ�룬��������ڷ���NULL
	int LL_get(int i);//��ȡ��i��Ԫ�ص�����
	int LL_insert(int i, int item);//����ֵitem�����i��λ��
	int LL_del(int i);//ɾ����i�����
	void LL_display();//��������������
	void swap(int p, int q, ListNode* cur1, ListNode* cur2);//��Ҫ��������������λ�ú�ָ�봫��
};
void LinkList::swap(int p, int q,ListNode* cur1, ListNode* cur2)
{
	int s, b;
	if (p > q)//��λ����ǰ��Ľ���s��λ�ÿ���Ľ���b
	{
		 b = p;  s = q;
	}
	else { b = q; s = p; }
	ListNode* curs = LL_index(s);//��ȡs����ָ��
	ListNode* curb = LL_index(b);//��ȡb����ָ��
	if (curs->next != curb)//�������ۣ���s����һ��λ�ò���bʱ
	{

	ListNode* cursq = LL_index(s - 1);//��s����ǰһ��ָ���cursq
	ListNode* curbq = LL_index(b - 1);//��b����ǰһ��ָ���curbq
	ListNode* tmp1 = cursq->next->next;//s����һ��ָ���tmp1
	ListNode* tmp2 = curbq->next->next;//b����һ��ָ���tmp

	cursq->next = curb;//b��λ��ת��s����ǰһ��ָ�����һ��ָ��
	curb->next = tmp1;//b����һ��ָ����s��������һ��ָ��
	curbq->next = curs;//s��λ��ת��b����ǰһ��ָ�����һ��ָ��
	curs->next = tmp2;//s����һ��ָ����b��������һ��ָ��
	
	}
	else
	{
		//��s����һ��λ�øպ���bʱ
		ListNode* curr = LL_index(s - 1);//С��ŵ�ǰһ�����
		ListNode* curr1 = curb->next;//����ŵĺ�һ�����
		ListNode* curr2 = curb;//����ŵ�ַ
		curr->next = curr2;
		curr2->next = curs;
		curs->next = curr1;

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
LinkList::~LinkList()//������գ�Ҫ���������
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
	p = head->next;//�����head�ǵ��ú����������head
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
