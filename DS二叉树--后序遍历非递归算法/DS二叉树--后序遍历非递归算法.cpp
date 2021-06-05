#include <iostream>
#include <stack>
using namespace std;

class BiNode {
    char data;
    int tag;
    BiNode* lChild;
    BiNode* rChild;
    BiNode() :lChild(NULL), rChild(NULL) {}
    BiNode(char e) :data(e), lChild(NULL), rChild(NULL) {}
    friend class BiTree;
};

class BiTree {
    BiNode* root;
    void createTree(BiNode*& r);
public:
    BiTree() :root(NULL) {}
    void createTree();
    void postOrder();
};

void BiTree::createTree(BiNode*& r) {//�����������˵ݹ�
    char ch;
    cin >> ch;
    if (ch != '0')
    {
        r = new BiNode(ch);
        createTree(r->lChild);
        createTree(r->rChild);
    }
    else
        r = NULL;
}

void BiTree::createTree() {
    createTree(root);
}

void BiTree::postOrder() {
    stack<BiNode*> s1;
    stack<int> s2;
    BiNode* p = root;
    do {
        while (p) {
            s1.push(p);
            s2.push(p->tag);
            p = p->lChild;//whileѭ���ҵ�����Ľ�㣬ֱ������Ľ�����һ�������NULL
        }
        if (!p)//������Ľ�����һ�������NULLʱ
        {
            int tag = s2.top();//�������ջ��tagֵ��tag��Ĭ��Ϊ0
            if (tag == 0)//���tagΪ0˵���ҽ�㻹û����
            {
                s2.top() = 1;//�õ��tagֵ��Ϊ1
                p = s1.top()->rChild;//Ȼ�󽫸õ���ҽ�����ջ�����¿�ʼ����������
            }
            else if (tag == 1)//���tagֵΪ1��˵���õ��Ѿ��������ˣ�����һ�����ݵĹ����ˣ����Կ������
            {
                p = s1.top();
                s1.pop();//��ջ��ɾ��
                s2.pop();
                cout << p->data;//������������˾����
                p = NULL;
            }
        }


    } while (!s1.empty());//ֱ��ջ��û�е��˾����

    cout << endl;
}


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        BiTree myTree;
        myTree.createTree();
        myTree.postOrder();
    }
    return 0;
}
