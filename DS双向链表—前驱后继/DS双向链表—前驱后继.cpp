#include<iostream>
using namespace std;
class node
{
public:
	int key;
	node* prev, *next;
	node()
	{
		prev = NULL;
		next = NULL;
	}
};
class list
{
public:
	node* head;
	list()
	{
		head = new node();
		head->next = head;
		head->prev = head;
	}
	void insert(int key);
	node* listSearch(int key);
	void display(node* cur);
};
void list::insert(int key)
{
	node* x = new node();
	x->key = key;
	x->next = head->next;//x����һ������ɱ�����head����һ�����
	head->next->prev = x;//nil��������һ��������ڵ�ǰһ������ڱ�Ϊx
	head->next = x;//nil����һ����Ϊx
	x->prev = head;//x����һ�������nil
}
void list::display(node* cur)
{
	if (cur->prev == head)cout << cur->next->key << endl;
	else if (cur->next == head)cout << cur->prev->key << endl;
	else cout << cur->next->key << " " << cur->prev->key << endl;
}
node* list::listSearch(int key)
{
		//������ͷ��㿪ʼ����
		node* cur = head->next;
		while (cur != head && cur->key != key)
		{
			cur = cur->next;
		}
		return cur;
}
int main()
{
	int n, m,key;
	list l;
	cin >> n>>m;
	for (int i = 1; i <= n; i++)
	{
		cin >> key;
		l.insert(key);
	}
	for (int i = 0; i < m; i++)
	{
		cin >> key;
		node* x=l.listSearch(key);
		l.display(x);
	}
	return 0;
}
//10 3
//1 2 3 4 5 6 7 8 9 0
//3
//1
//0