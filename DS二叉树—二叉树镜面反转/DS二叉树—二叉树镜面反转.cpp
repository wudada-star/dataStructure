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
            T->right = CreateBitreeReverse();//ֱ�ӵ���������˳��
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
        int fr = 0;//��ǰ���������λ��
        int re = 0;//�����ǰ�Ľ����¸���㲻Ϊ�գ��ͼ�1���൱��Ԫ�ظ����ļ���
        if (Root == NULL)
            return;
        Q[0] = Root;//�������е���ʽ�ŵ��������ǰ��зŵ������еģ�����ʽû��ʲô��ϵ
        re++;//��������������������α�����ʵ�Ƚϼ򵥣�ֻҪ֪���������ж೤�Ϳ��������
        while (fr != re)
        {
            BitreeNode* temp = Q[fr];
            cout << temp->data << " ";
            if (temp->left != NULL)//���ǵ����ļ���
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