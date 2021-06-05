#include<iostream>
#include<string>
using namespace std;

class BiTreeNode
{
public:
    char data;        //�������
    BiTreeNode* LeftChild;    //������ָ��
    BiTreeNode* RightChild;        //������ָ��
    BiTreeNode() :LeftChild(NULL), RightChild(NULL) {}
    ~BiTreeNode() {}
};

class BiTree
{
private:
    BiTreeNode* Root;    //�����ָ��
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

//�����������������������������
void BiTree::CreateTree(string TreeArray)    //���к���������ӿ�
{
    len = TreeArray.length();    //��������ĳ���
    strTree.assign(TreeArray);    //�����������ת�浽�������strTree��
    Root = CreateBiTree(0);        //������0��ʼ������
}

BiTreeNode* BiTree::CreateBiTree(int pos)    //��posλ�õݹ齨����˽�к���������ʵ��
{    //�ò���pos���ݵ�ǰ����������λ�ã�����������5����Ϊ�����0��ʼ��ţ��������i�����Һ���λ����2i+1,2i+2
    BiTreeNode* T;    //��ʱָ��T
    int ch;
    if (pos > strTree.length())
        return NULL;
    ch = strTree[pos];
    if (ch == '0')
        T = NULL;
    else
    {
        T = new BiTreeNode();
        T->data = ch;        //���ɸ����
        if (2 * (pos + 1) <= len)
            T->LeftChild = CreateBiTree(2 * (pos + 1) - 1);
        if (2 * (pos + 1) + 1 <= len)
            T->RightChild = CreateBiTree(2 * (pos + 1));
    }
    return T;
}
//���������������
void BiTree::PreOrder()    //���к���������ӿ�
{
    PreOrder(Root);
}
void BiTree::PreOrder(BiTreeNode* t)    //˽�к���������ʵ��
{
    if (t != NULL)
    {
        cout << t->data;    //�����ǰ���t�����ݣ���ʾt�Ѿ�����
        PreOrder(t->LeftChild);    //�������t������
        PreOrder(t->RightChild);    //�������t���Һ���
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