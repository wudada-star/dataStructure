#include<iostream>
using namespace std;
class ListNode
{
public:
	int data;//�������ڽ�����ж���
	ListNode* next;//����ǰ��ָ��Ҳ���ڽ�����ж���
	ListNode() {
		next = NULL;//�øý�����һ������Ĭ��ΪNULL,��Ϊ�´����Ľ����һ��ȫ�µģ���������һ�����Ӧ����NULL�����������ܼ��뵽������һ��
	}
};
class LinkList
{
public:
	ListNode* head;//ͷ�ڵ�
	int len;//������
	LinkList();//�Գ�Ա�������г�ʼ��
	~LinkList();
	void insert(int N);
	void LL_del(int n);//ɾ���ظ��Ľ��
	void LL_display();//��������������
};
LinkList::LinkList()
{
	head = new ListNode();
	len = 0;//ͷ�ڵ㲻������ĳ��ȣ�������0
}
LinkList::~LinkList()//������գ�Ҫ���������
{
	ListNode* p, * q;
	p = head;//ע��ͷ�ڵ�Ŀռ�ҲҪɾ��
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
	ListNode* cur = head;//�������ͷ�ڵ����ͷcur
	for (int i = 1; i <=N; i++)
	{
		cin >> data1;
		ListNode* x = new ListNode();//����һ�����ռ�
		cur->next = x;//��x���嵽ͷ������һ��λ��
		//x->next = head;//x����һ�������ͷ�ڵ�
		cur = x;//��ͷָ��x
		cur->data = data1;//��x��㸳ֵ
		len += 1;
	}
}
void LinkList::LL_del(int n)
{
		ListNode* x = new ListNode();//����һ�����ռ�
		x = head->next;
	for (int i = 2; i <= n; i++)
	{
		ListNode* y = new ListNode();//����һ�����ռ�
		y = head->next;//�ӵ�һ����㿪ʼ
		x = x->next;//Ҫ���бȽϵ���,�ӵڶ�����㿪ʼ
		for (int j = 1; j < i-(n-len); j++)//Ҫ���бȽ�ǰ����������,����Ҫע������len��ɾ��������ʱ�ĳ���Ҳ���С
		{
			if (x->data == y->data)
			{
				while (j != i - (n - len + 1))
				{
					y = y->next;//��yָ��x��ǰһ�����
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
void LinkList::LL_display()//��������������
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