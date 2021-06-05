#include<iostream>
using namespace std;
class TreeNode {
public:
	TreeNode* leftChild;//����
	TreeNode* rightChild;//�Һ���
	int weight;//�ýڵ��Ȩ��
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
	int maxx;//��¼����Ȩ��
	int pos;//��ĸ���λ��
	int pos_wt;//��ĸ���Ӧ��Ȩ�ص�λ��
	int n;
	TreeNode* root;//���ڵ�
	string str;
	int* weight;
	TreeNode* createTree() {//�ݹ齨��
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
	void PreOrder(TreeNode* root) {//���������ͬʱ�����ڵ��Ȩ�ؼӵ����Һ�����
		if (root) {
			if (root->leftChild && root->rightChild) {//���Һ��Ӷ���
				root->leftChild->weight += root->weight;
				root->rightChild->weight += root->weight;
			}
			else if (root->leftChild)//ֻ������
				root->leftChild->weight += root->weight;
			else if (root->rightChild)//ֻ���Һ���
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
