#include<iostream>
#include<string>
using namespace std;
class BiTreeNode
{
public:
    char data;
    BiTreeNode* Left;
    BiTreeNode* Right;
    BiTreeNode()
    {
        Left = NULL;
        Right = NULL;
    }
    ~BiTreeNode()
    {
        delete Left;
        delete Right;
    }
};

class BiTree
{
public:
    BiTreeNode* Root;
    int pos;
    string strTree;
    BiTree(string str)
    {
        pos = 0;
        strTree = str;
        Root = CreateBiTree();
    }
    BiTreeNode* CreateBiTree()
    {
        char ch = strTree[pos];//这一步是因为每次递归都要先把pos的值加1到后面的数据
        pos++;
        if (ch == '0')
        {
            return NULL;
        }
        else
        {
            BiTreeNode* T;
            T = new BiTreeNode();
            T->data = ch;
            T->Left = CreateBiTree();//当该节点的左右节点均为0时可以返回T,此时递归会停止，回溯到前面还差的右节点的递归
            T->Right = CreateBiTree();
            return T;
        }
    }
    void Pre(BiTreeNode* p)//传递的是指针，所以遇到NULL会停止，如果是数组则不行，因为数组之外是乱码不为NULL
    {
        if (p)
        {
            cout << p->data;
            Pre(p->Left);
            Pre(p->Right);
        }
    }
    void In(BiTreeNode* p)
    {
        if (p)
        {
            In(p->Left);
            cout << p->data;
            In(p->Right);
        }
    }
    void Post(BiTreeNode* p)
    {
        if (p)
        {
            Post(p->Left);
            Post(p->Right);
            cout << p->data;
        }
    }
};

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string str;
        cin >> str;
        BiTree tree(str);
        tree.Pre(tree.Root);
        cout << endl;
        tree.In(tree.Root);
        cout << endl;
        tree.Post(tree.Root);
        cout << endl;
    }
    return 0;
}

