#include<iostream>
#include<string>
using namespace std;
class Node
{
public:
    char data;
    Node* Left;
    Node* Right;
    Node()
    {
        Left = NULL;
        Right = NULL;
    }
    ~Node()
    {
        delete Left;
        delete Right;
    }
};

class BiTree
{
public:
    Node* Root;
    int pos;
    string strTree;
    BiTree(string str)
    {
        pos = 0;
        strTree = str;
        Root = CreateBiTree();
    }
    Node* CreateBiTree()//���õݹ鴴��������
    {
        char ch = strTree[pos];
        pos++;
        if (ch == '0')
        {
            return NULL;
        }
        else
        {
            Node* T;
            T = new Node();
            T->data = ch;
            T->Left = CreateBiTree();
            T->Right = CreateBiTree();
            return T;
        }
    }
    void getleaves(Node* p)
    {
        if (p)
        {
            if (p->Left == NULL && p->Right == NULL)
            {
                cout << p->data << " ";
            }
            getleaves(p->Left);
            getleaves(p->Right);
        }
    }
    void getparents(Node* p, Node* parent)
    {
        if (p)
        {
            if (p->Left == NULL && p->Right == NULL)
            {
                cout << parent->data << " ";
            }
            getparents(p->Left, p);
            getparents(p->Right, p);
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
        tree.getleaves(tree.Root);
        cout << endl;
        tree.getparents(tree.Root, NULL);
        cout << endl;
    }
    return 0;
}
