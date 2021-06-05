#include <iostream>
using namespace std;

#define LH 1	//左高
#define EH 0	//等高
#define RH -1	//右高

class BiNode {
public:
	int key;		//关键值
	int bf;			//平衡因子
	BiNode* lChild, * rChild;
	BiNode(int kValue, int bValue) {
		key = kValue;
		bf = bValue;
		lChild = NULL;
		rChild = NULL;
	}
	~BiNode()
	{
		key = 0;
		bf = 0;
		lChild = NULL;
		rChild = NULL;
	}
};

class BST {
	BiNode* root;
	void rRotate(BiNode*& p);
	void lRotate(BiNode*& p);
	void leftBalance(BiNode*& t);
	void rightBalance(BiNode*& t);
	int insertAVL(BiNode*& t, int key, bool& taller);
	void inOrder(BiNode* o);
public:
	BST();
	void insertAVL(int key);
	~BST();
	void inOrder();
};
BST::BST() {
	root = NULL;
}
BST::~BST() {
	root = NULL;
}
//插入元素并做平衡处理
void BST::insertAVL(int key) {
	bool taller = false;
	insertAVL(root, key, taller);
}
int BST::insertAVL(BiNode*& t, int key, bool& taller) {
	if (!t) {//如果到了空节点那就直接插入，然后跳出循环，一定是插在叶子节点
		t = new BiNode(key, EH);
		taller = true;
	}
	else {
		//树中已经存在和key相同的结点，则不再插入
		if (key == t->key) {
			taller = false;
			return 0;
		}
		//树中不存在关键字为key的结点
		//如果key小于当前结点的key，则应插入左子树
		//否则应插入右子树
		if (key < t->key) {
			//未插入
			if (!insertAVL(t->lChild, key, taller))
				return 0;
			//如果已经插入左子树,则判断是否需要平衡化处理
			//如果左子树比右子树高，则需要左平衡处理(右旋)
			//如果原本左右子树等高，则左子树增高
			//如果原本右子树高，则现在左右子树等高
			if (taller) {//插入后判断平衡关系
				switch (t->bf)
				{
				case LH:
					leftBalance(t);
					taller = false;
					break;
				case EH:
					t->bf = LH;
					taller = true;
					break;
				case RH:
					t->bf = EH;
					taller = false;
					break;
				}
			}
		}
		else {
			//未插入
			if (!insertAVL(t->rChild, key, taller))
				return 0;
			//如果已经插入右子树,则判断是否需要平衡化处理
			//如果原本左子树比右子树高，则现在左右子树等高
			//如果原本左右子树等高，则右子树增高
			//如果右子树高，则需要右平衡处理(左旋)
			if (taller) {
				switch (t->bf)
				{
				case LH:
					t->bf = EH;
					taller = false;
					break;
				case EH:
					t->bf = RH;
					taller = true;
					break;
				case RH:
					rightBalance(t);
					taller = false;
					break;
				}
			}
		}
	}
	return 1;
}
//中序遍历
void BST::inOrder(BiNode* p) {
	if (p) {
		inOrder(p->lChild);
		cout << p->key << ':' << p->bf << ' ';
		inOrder(p->rChild);
	}
}
void BST::inOrder() {
	inOrder(root);
}
//以p为根的二叉排序树做右旋处理
void BST::rRotate(BiNode*& p) {
	//lc指向p的左子树的根结点
	//lc的右子树挂为p的左子树
	//p指向新的根结点
	BiNode* lc;
	lc = p->lChild;
	p->lChild = lc->rChild;
	lc->rChild = p;
	p = lc;
}
//以p为根的二叉排序树做左旋处理
void BST::lRotate(BiNode*& p) {
	//rd指向p的右子树的根结点
	//rd的左子树挂为p的右子树
	//p指向新的根结点
	BiNode* rd;
	rd = p->rChild;
	p->rChild = rd->lChild;
	rd->lChild = p;
	p = rd;
}
//以t为根的二叉排序树做左平衡处理
void BST::leftBalance(BiNode*& t) {
	//指针指向新的根结点
	//判断该根结点的左子树平衡状态
	BiNode* lc;
	BiNode* rd;
	lc = t->lChild;
	switch (lc->bf)
	{
		//如果为LH，则新结点插入在t的左孩子的左子树上
		//需要进行单右旋处理
		//如果为RH，则新结点插入在t的左孩子的右子树上
		//需要进行双旋处理
	case LH:
		t->bf = lc->bf = EH;
		rRotate(t);
		break;
	case RH:

		rd = lc->rChild;
		switch (rd->bf) {
		case LH:t->bf = RH;
			lc->bf = EH;
			break;
		case EH:
			t->bf = lc->bf = EH;
			break;
		case RH:
			t->bf = EH;
			lc->bf = LH;
			break;
		}
		rd->bf = EH;
		lRotate(t->lChild);
		rRotate(t);
	}
}
//以t为根的二叉排序树做右平衡处理
void BST::rightBalance(BiNode*& t) {
	BiNode* lc;
	BiNode* rd;
	rd = t->rChild;
	switch (rd->bf)
	{
	case RH:
		t->bf = rd->bf = EH;
		lRotate(t);
		break;
	case LH:
		lc = rd->lChild;
		switch (lc->bf)
		{
		case RH:
			t->bf = LH;
			rd->bf = EH;
			break;
		case EH:
			t->bf = rd->bf = EH;
			break;
		case LH:
			t->bf = EH;
			rd->bf = RH;
			break;
		}
		lc->bf = EH;
		rRotate(t->rChild);
		lRotate(t);
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, elem;
		cin >> n;
		BST tree;
		while (n--)
		{
			cin >> elem;
			tree.insertAVL(elem);
		}
		tree.inOrder();
		cout << endl;
	}
	return 0;
}