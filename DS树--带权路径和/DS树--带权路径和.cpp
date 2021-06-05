#include<iostream>
#include<string>
using namespace std;

class BiTreeNode {
public:
    char data;
    int weight;
    BiTreeNode* LeftChild;
    BiTreeNode* RightChild;
    BiTreeNode() :LeftChild(NULL), RightChild(NULL) {
    }
    ~BiTreeNode() {
        delete[]LeftChild; delete[]RightChild;
    }
};
class BiTree {
private:
    BiTreeNode* Root;
    int pos;
    int w_pos;
    int APL;
    string strTree;
    int* NodeWeight;
    BiTreeNode* CreateBiTree() {
        BiTreeNode* T;
        char ch;
        ch = strTree[pos++];
        if (ch == '0')//如果是‘0’说明是空
            T = NULL;
        else {
            T = new BiTreeNode();
            if (ch >= 'A' && ch <= 'Z') {//赋予权重
                T->weight = NodeWeight[w_pos++];
            }
            else T->weight = 0;
            T->data = ch;
            T->LeftChild = CreateBiTree();
            T->RightChild = CreateBiTree();
        }
        return T;
    }
    void PreOrder(BiTreeNode* t) {//先序遍历
        if (t) {
            int h = 0;
            int level;
            if (!t->LeftChild && !t->RightChild) {//找到叶子
                level = find_node_level(Root, t->data, h);
                APL += level * t->weight;

            }
            PreOrder(t->LeftChild);
            PreOrder(t->RightChild);
        }
        pos++;
    }
    void InOrder(BiTreeNode* t) {//中序遍历
        if (t) {
            InOrder(t->LeftChild);
            cout << t->data;
            InOrder(t->RightChild);
        }
    }
    void PostOrder(BiTreeNode* t) {//后序遍历
        if (t) {
            PostOrder(t->LeftChild);
            PostOrder(t->RightChild);
            cout << t->data;
        }
    }
public:
    BiTree() {
    }
    ~BiTree() {
    }
    int find_node_level(BiTreeNode* bt, char x, int h) {
        if (bt == NULL)
            return 0;
        else if (bt->data == x)
            return h;
        else
        {
            int l = find_node_level(bt->LeftChild, x, h + 1);
            if (l != 0)
                return l;
            else
                return find_node_level(bt->RightChild, x, h + 1);
        }
    }
    void CreateTree(string TreeArray, int* w) {
        APL = 0;
        pos = 0;
        w_pos = 0;
        NodeWeight = w;
        strTree.assign(TreeArray);
        Root = CreateBiTree();
    }
    void PreOrder() {
        pos = 0;
        PreOrder(Root);
    }
    void InOrder() {
        InOrder(Root);
        cout << endl;
    }
    void PostOrder() {
        PostOrder(Root);
        cout << endl;
    }
    void show() {
        cout << APL << endl;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        BiTree tree;
        cin >> str;
        int n;
        cin >> n;
        int* weight = new int[n];
        for (int i = 0; i < n; i++) {
            cin >> weight[i];
        }
        tree.CreateTree(str, weight);
        tree.PreOrder();
        tree.show();

    }
    return 0;
}