#include<iostream>
using namespace std;
class TreeNode {
public:
	TreeNode* leftChild;//左孩子
	TreeNode* rightChild;//右孩子
	int weight;//该节点的权重
	TreeNode() {
		leftChild = NULL;
		rightChild = NULL;
		weight = 0;
	}
	~TreeNode() {
		delete leftChild ;
		delete rightChild ;
		weight = 0;
	}
};
class Tree {
private:
	int maxx;//记录最大的权重
	int pos;//字母表的位置
	int pos_wt;//字母表对应的权重的位置
	int n;
	TreeNode* root;//根节点
	string str;
	int* weight;
	TreeNode* createTree() {//递归建树
		TreeNode* t;
		char ch = str[pos++];

		if (ch == '0')
			t = NULL;
		else {
			t = new TreeNode();
			t->weight = weight[pos_wt++];
			t->leftChild = createTree();
			t->rightChild = createTree();
		}
		return t;
	}
	void PreOrder(TreeNode* root) {//先序遍历的同时将父节点的权重加到左右孩子上
		if (root) {
			if (root->leftChild && root->rightChild) {//左右孩子都有
				root->leftChild->weight += root->weight;
				root->rightChild->weight += root->weight;
			}
			else if (root->leftChild)//只有左孩子
				root->leftChild->weight += root->weight;
			else if (root->rightChild)//只有右孩子
				root->rightChild->weight += root->weight;


			maxx = maxx > root->weight ? maxx : root->weight;
			PreOrder(root->leftChild);
			PreOrder(root->rightChild);
		}
	}
public:
	void createTree(string st, int wt[], int nn) {
		str = st;
		maxx = -10000;
		pos = 0;
		pos_wt = 0;
		n = nn;
		weight = new int[n + 5];
		for (int i = 0; i < n; i++)
			weight[i] = wt[i];
		root = createTree();
	}
	void getMax() {
		PreOrder(root);
		cout << maxx << endl;
	}
};
int main() {
	int t;
	cin >> t;
	while (t--) {
		string str;
		cin >> str;
		int n;
		cin >> n;
		int* array = new int[n + 5];
		for (int i = 0; i < n; i++)
			cin >> array[i];
		Tree tree;
		tree.createTree(str, array, n);
		tree.getMax();
	}
	return 0;
}
