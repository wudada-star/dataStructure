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
    {//递归的条件是传入的序列是否为空
        int temp = post[n - 1];//将后序遍历的最后一个数给temp，最后一个数也是二叉树的根结点
        p = new BiTNode();//可以看成先序就是由后序的根节点组成，而中序的作用在于找到后序
        //在中序中的位置，以此来确定n的值
        p->data = temp;
        for (i = 0; i < n; i++)
            if (in[i] == temp)
                break;//找到中序遍历中的根结点
        int num1 = i;
        int num2 = n - i - 1;
        int* in1 = new int[num1];
        int* in2 = new int[num2];
        for (j = 0; j < n; j++)//在中序序列中定位出根节点的位置，
                        //在其左边的就是左子树中序序列，右边的就是右子树中序序列
        {
            if (j < i)
                in1[j] = in[j];
            else if (j > i)
                in2[j - i - 1] = in[j];
        }
        int* post1 = new int[num1];//post的作用在于为种序提供根节点，本题的核心在于
        int* post2 = new int[num2];//利用后序的根节点，中序的左右子树来构建先序树
        for (j = 0; j < n; j++)
        {
            if (j < i)
                post1[j] = post[j];
            else if (j >= i && j < n - 1)//每次去掉后序遍历的最后一个元素
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

