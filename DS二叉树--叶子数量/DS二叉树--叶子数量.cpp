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
    int count = 0;
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
    void countleaves(BiTreeNode* p)
    {
        if (p)
        {
            if (p)
                    {
                         if (!p->Left && !p->Right)count++;
                        countleaves(p->Left);
                        countleaves(p->Right);
                    }
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
        tree.countleaves(tree.Root);
        cout << tree.count << endl;
    }
    return 0;
}

