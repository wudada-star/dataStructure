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
        char ch = strTree[pos];//��һ������Ϊÿ�εݹ鶼Ҫ�Ȱ�pos��ֵ��1�����������
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
            T->Left = CreateBiTree();//���ýڵ�����ҽڵ��Ϊ0ʱ���Է���T,��ʱ�ݹ��ֹͣ�����ݵ�ǰ�滹����ҽڵ�ĵݹ�
            T->Right = CreateBiTree();
            return T;
        }
    }
    void Pre(BiTreeNode* p)//���ݵ���ָ�룬��������NULL��ֹͣ��������������У���Ϊ����֮�������벻ΪNULL
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

