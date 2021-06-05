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

void BiTree::createTree(BiNode*& r) {//建树还是用了递归
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
            p = p->lChild;//while循环找到最左的结点，直到最左的结点的下一个结点是NULL
        }
        if (!p)//当最左的结点的下一个结点是NULL时
        {
            int tag = s2.top();//将最后入栈的tag值给tag，默认为0
            if (tag == 0)//如果tag为0说明右结点还没遍历
            {
                s2.top() = 1;//该点的tag值改为1
                p = s1.top()->rChild;//然后将该点的右结点放入栈，重新开始遍历最左结点
            }
            else if (tag == 1)//如果tag值为1，说明该点已经遍历过了，这是一个回溯的过程了，所以可以输出
            {
                p = s1.top();
                s1.pop();//从栈中删除
                s2.pop();
                cout << p->data;//如果都遍历到了就输出
                p = NULL;
            }
        }


    } while (!s1.empty());//直到栈中没有点了就输出

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
