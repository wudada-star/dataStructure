#include<iostream>
using namespace std;
class BitreeNode
{
public:
    char data;
    BitreeNode* left;
    BitreeNode* right;
    BitreeNode()
    {
        left = right = NULL;
    }
};

class Bitree
{
public:
    int pos;
    BitreeNode* Root;
    char* strtree;
    Bitree(char* str)
    {
        pos = 0;
        strtree = str;
        Root = CreateBitreeReverse();
    }
    BitreeNode* CreateBitreeReverse()
    {
        char ch = strtree[pos];
        pos++;
        if (ch == '#')
            return NULL;
        else
        {
            BitreeNode* T = new BitreeNode();
            T->data = ch;
            T->right = CreateBitreeReverse();//直接调换构建的顺序
            T->left = CreateBitreeReverse();
            return T;
        }
    }
    void preorder(BitreeNode* T)
    {
        if (T != NULL)
        {
            cout << T->data << " ";
            preorder(T->left);
            preorder(T->right);
        }
        return;
    }
    void inorder(BitreeNode* T)
    {
        if (T != NULL)
        {
            inorder(T->left);
            cout << T->data << " ";
            inorder(T->right);
        }
        return;
    }
    void pastorder(BitreeNode* T)
    {
        if (T != NULL)
        {
            pastorder(T->left);
            pastorder(T->right);
            cout << T->data << " ";
        }
        return;
    }
    void levelorder()
    {
        BitreeNode* Q[100];
        int fr = 0;//当前先序遍历的位置
        int re = 0;//如果当前的结点的下个结点不为空，就加1，相当于元素个数的计数
        if (Root == NULL)
            return;
        Q[0] = Root;//二叉树中的链式放到数组中是按行放到数组中的，跟链式没有什么关系
        re++;//所以如果用数组来输出层次遍历其实比较简单，只要知道这条链有多长就可以输出了
        while (fr != re)
        {
            BitreeNode* temp = Q[fr];
            cout << temp->data << " ";
            if (temp->left != NULL)//就是单纯的计数
            {
                Q[re] = temp->left;
                re++;
            }
            if (temp->right != NULL)
            {
                Q[re] = temp->right;
                re++;
            }
            fr++;
        }
        return;
    }
};

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        char str[100];
        cin >> str;
        Bitree Tree(str);
        if (Tree.Root == NULL)
        {
            cout << "NULL" << endl;
            cout << "NULL" << endl;
            cout << "NULL" << endl;
            cout << "NULL" << endl;
        }
        else
        {
            Tree.preorder(Tree.Root);
            cout << endl;
            Tree.inorder(Tree.Root);
            cout << endl;
            Tree.pastorder(Tree.Root);
            cout << endl;
            Tree.levelorder();
            cout << endl;
        }
    }
    return 0;
}