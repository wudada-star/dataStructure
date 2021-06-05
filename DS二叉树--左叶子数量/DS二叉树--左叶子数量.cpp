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
    int count=0;
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
    void countLeft(BiTreeNode* p)
    {
        if (p)
        {
        if (p->Left)//因为要有左节点才能判断有没有左左节点
        {
        if (!p->Left->Left&&!p->Left->Right)
        {
            count++;
        }
        }
            countLeft(p->Left);
            countLeft(p->Right);
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
        tree.countLeft(tree.Root);
        cout << tree.count << endl;
    }
    return 0;
}

