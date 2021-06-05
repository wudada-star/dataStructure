//���Ƚ�����ϣ������ģ��ȷ����ϣ������鳤�ȣ���Ϊȡģ�����е�������ģֵ�ڣ���ÿ������Ԫ�ض�������һ��ͷ
//�ڵ�ռ䣬��������ַ�����õ���ͷ�巨�����Ե�����ʱ�������һ���ΪNULL��
//˵���ù�ϣ����û��Ҫ�ҵ�ֵ��������±��ǹؼ��֣���ȡģ���ֵ��ģ�е������ǵ�ַ����ַ�е������Ǽ�¼��
#include<iostream>
using namespace std;
class node
{
public:
	int data;//������ݣ�����¼
	int times;//��¼���ҵĴ���
	node* next;
	node()
	{
		next = NULL;
		data = 0;
	}
	node* insert(int n)//��β����
	{
		node* p = this;
		while (true)
		{
		if (!p->next )
		{
			node* pp = new node();
			pp->data = n;
			p->next = pp;
			return this;//��������������
		}
		else
		{
			p = p->next;
		}
		}
	}
	int search(int n)//�ڸý������в�����û��Ҫ�ҵ�ֵ
	{
		times = 1;
		node* p = this->next;//ͷ�ڵ��ǿյģ�Ҫ�ӵڶ����������
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
		root = new node * [n];//����һ��ָ������Ϊ��ϣ��
		for (int i = 0; i < n; i++)
		{
			root[i] = new node();//iΪ������±꼴�ؼ��֣�root[i]Ϊ��ַ
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
		root[hash] = root[hash]->insert(k);//�Ѳ����������ͻظ�ԭ���Ľ��
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