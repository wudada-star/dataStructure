#include <iostream>
using namespace std;

class BiTNode
{
    int data;
    BiTNode* lchild, * rchild;
    friend class BiTree;
};

class BiTree
{
    BiTNode* root;
    int num;
    int minweight;
    int* post;
    int* in;
    void CreateTree(BiTNode*& p, int* post, int* in, int n);
    void PreOrderTraverse(BiTNode* p);
public:
    BiTree(int n, int* s1, int* s2);
    ~BiTree();
    void CreateTree();
    void PreOrder();
};

BiTree::BiTree(int n, int* s1, int* s2)
{
    num = n;
    minweight = 99999;
    post = new int[num];
    in = new int[num];
    for (int i = 0; i < num; i++)
    {
        post[i] = s1[i];
        in[i] = s2[i];
    }
}

BiTree::~BiTree()
{
    delete[]post;
    delete[]in;
}

void BiTree::CreateTree()
{
    CreateTree(root, post, in, num);
}

void BiTree::CreateTree(BiTNode*& p, int* post, int* in, int n)
{
    int i, j;
    if (n)
    {//�ݹ�������Ǵ���������Ƿ�Ϊ��
        int temp = post[n - 1];//��������������һ������temp�����һ����Ҳ�Ƕ������ĸ����
        p = new BiTNode();//���Կ�����������ɺ���ĸ��ڵ���ɣ�����������������ҵ�����
        //�������е�λ�ã��Դ���ȷ��n��ֵ
        p->data = temp;
        for (i = 0; i < n; i++)
            if (in[i] == temp)
                break;//�ҵ���������еĸ����
        int num1 = i;
        int num2 = n - i - 1;
        int* in1 = new int[num1];
        int* in2 = new int[num2];
        for (j = 0; j < n; j++)//�����������ж�λ�����ڵ��λ�ã�
                        //������ߵľ����������������У��ұߵľ�����������������
        {
            if (j < i)
                in1[j] = in[j];
            else if (j > i)
                in2[j - i - 1] = in[j];
        }
        int* post1 = new int[num1];//post����������Ϊ�����ṩ���ڵ㣬����ĺ�������
        int* post2 = new int[num2];//���ú���ĸ��ڵ㣬�������������������������
        for (j = 0; j < n; j++)
        {
            if (j < i)
                post1[j] = post[j];
            else if (j >= i && j < n - 1)//ÿ��ȥ��������������һ��Ԫ��
                post2[j - i] = post[j];
        }
        CreateTree(p->lchild, post1, in1, num1);
        CreateTree(p->rchild, post2, in2, num2);
    }
    else
        p = NULL;
}

void BiTree::PreOrder()
{
    PreOrderTraverse(root);
    cout << minweight << endl;
}

void BiTree::PreOrderTraverse(BiTNode* p)
{
    if (p)
    {
        if (!p->lchild && !p->rchild)
            if (p->data < minweight)
                minweight = p->data;
        PreOrderTraverse(p->lchild);
        PreOrderTraverse(p->rchild);
    }
}

int main()
{
    int i, n;
    while (cin >> n)
    {
        int* in = new int[n];
        int* post = new int[n];
        for (i = 0; i < n; i++)
            cin >> in[i];
        for (i = 0; i < n; i++)
            cin >> post[i];
        BiTree myTree(n, post, in);
        myTree.CreateTree();
        myTree.PreOrder();
    }
    return 0;
}

