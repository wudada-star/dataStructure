#include<iostream>
#include<string>
using namespace std;

class BiTreeNode
{
public:
    char data;        //结点数据
    BiTreeNode* LeftChild;    //左子树指针
    BiTreeNode* RightChild;        //右子树指针
    BiTreeNode() :LeftChild(NULL), RightChild(NULL) {}
    ~BiTreeNode() {}
};

class BiTree
{
private:
    BiTreeNode* Root;    //根结点指针
    int pos, len;
    string strTree;
    BiTreeNode* CreateBiTree(int pos);
    void PreOrder(BiTreeNode* t);
public:
    BiTree() {};
    ~BiTree() {};
    void CreateTree(string TreeArray);
    void PreOrder();
    void InOrder();
    void PostOrder();
};

//构造二叉树，利用先序遍历结果建树
void BiTree::CreateTree(string TreeArray)    //公有函数，对外接口
{
    len = TreeArray.length();    //输入数组的长度
    strTree.assign(TreeArray);    //将输入的数组转存到类的数据strTree中
    Root = CreateBiTree(0);        //从数组0开始读数据
}

BiTreeNode* BiTree::CreateBiTree(int pos)    //在pos位置递归建树，私有函数，类内实现
{    //用参数pos传递当前结点在数组的位置，二叉树性质5，因为数组从0开始编号，父结点是i，左右孩子位置是2i+1,2i+2
    BiTreeNode* T;    //临时指针T
    int ch;
    if (pos > strTree.length())
        return NULL;
    ch = strTree[pos];
    if (ch == '0')
        T = NULL;
    else
    {
        T = new BiTreeNode();
        T->data = ch;        //生成根结点
        if (2 * (pos + 1) <= len)
            T->LeftChild = CreateBiTree(2 * (pos + 1) - 1);
        if (2 * (pos + 1) + 1 <= len)
            T->RightChild = CreateBiTree(2 * (pos + 1));
    }
    return T;
}
//定义先序遍历函数
void BiTree::PreOrder()    //公有函数，对外接口
{
    PreOrder(Root);
}
void BiTree::PreOrder(BiTreeNode* t)    //私有函数，类内实现
{
    if (t != NULL)
    {
        cout << t->data;    //输出当前结点t的数据，表示t已经访问
        PreOrder(t->LeftChild);    //先序遍历t的左孩子
        PreOrder(t->RightChild);    //先序遍历t的右孩子
    }
}

int main(void)
{
    int t;
    BiTree T;
    string str;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> str;
        T.CreateTree(str);
        T.PreOrder();
        cout << endl;
    }
    return 0;
}