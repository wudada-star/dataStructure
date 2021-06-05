#include<iostream>
#include<string>
#include<queue>
using namespace std;
class BiTreeNode
{
public:
	char data;
	BiTreeNode* left;
	BiTreeNode* right;
	BiTreeNode()
	{
		left = NULL;
		right = NULL;
	}
	~BiTreeNode()
	{
		delete left;
		delete right;
	}
};
class BiTree
{
public:
	string str;
	BiTreeNode* root;
	int pos = 0;
	BiTree(string s)
	{
		str = s;
		root=CreatBitree();//注意这里是将空参构造给root,创建root的链
	}
	BiTreeNode* CreatBitree()
	{
		char cc = str[pos];
		pos++;
		if (cc == '0')//注意数组是没有NULL的，是建成树之后才有链式，才有判断NULL来判断是否有元素
		{
			return NULL;
		}
		if (cc != '0')
		{
			BiTreeNode* rr;
			rr = new BiTreeNode();
			rr->data = cc;
			rr->left=CreatBitree();//这里是利用递归创造一个结点返回赋值
			rr->right=CreatBitree();//当两个结点返回值均为NULL时就会停止递归
			return rr;
		}
	}
	void LevelOrder()
	{
		LevelOrder(root);
	}
	void LevelOrder(BiTreeNode* t)
	{
		queue< BiTreeNode*>tq;
		BiTreeNode* p = t;//创建这个p的意义在于将t第一个值给他，而不改动t的链
		if (p)//如果第一个元素不为NULL
		{
			tq.push(p);
			while (!tq.empty())//队列中有元素就可以继续输出
			{
				p = tq.front();//这里将p作为链的头部
				cout << p->data;
				tq.pop();
				if (p->left)tq.push(p->left);//分别将左右结点放入队列，这样就不会漏掉每行中的任意一个元素
				if (p->right)tq.push(p->right);
			}
		}
		cout << endl;
	}
};
int main()
{
	int t;
	string str;
	cin >> t;
	while (t--)
	{
		cin >> str;
		BiTree b(str);
		b.LevelOrder();
	}
	return 0;
}