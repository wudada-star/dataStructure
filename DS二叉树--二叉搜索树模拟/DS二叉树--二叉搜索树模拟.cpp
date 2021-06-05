#include<iostream>
using namespace std;
int num = 0;//全局变量来使不输出空格
class node {
public:
    int data;
    node* left;
    node* right;
    node() {
        data = 0;
        left = NULL;
        right = NULL;
    }
    ~node()
    {
        delete left;
        delete right;
    }
};
void addTree(int shu, node* root) {//排序二叉树是用中序遍历来取值，所以左边放小的值，右边放大的值

    while (true) {
        if (shu < root->data) {//插入的值小于根的数据，放入左子树
            if (!root->left) {//如果root的左子树为空
                root->left = new node();
                root->left->data = shu;
                return;
            }
            else {
                root = root->left;
            }
        }
        else {
            if (!root->right) {//插入的值大于根的数据，放入右子树
                root->right = new node();
                root->right->data = shu;
                return;
            }
            else
                root = root->right;
        }
    }
}
void inOrder(node*& root) {
        
    if (root) {
        inOrder(root->left);
        if (num != 0) {
            cout << " " << root->data;
        }
        else
        {
            cout << root->data;
            num++;
        }
        inOrder(root->right);
    }
}
void preOrder(node*& root) {
       
    if (root) {
        if (num != 0) {
            cout << " " << root->data;
        }
        else
        {
            cout << root->data;
            num++;
        }
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(node*& root) {
       
    if (root) {
        postOrder(root->left);
        postOrder(root->right);
        if (num != 0) {
        cout <<" "<< root->data ;
        }
        else
        {
            cout << root->data;
            num++;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, data, m;
        cin >> n;
        node* Root = NULL;//设置一个循环外的指针使循环内都能够调用到这个树的根指针
        if (n >= 1)//建立第一个根结点
        {
            cin >> data;
            node* root;
            root = new node();
            root->data = data;
            Root = root;
        }
        for (int i = 1; i < n; i++) {
            cin >> data;
            node* root = Root;
            addTree(data, root);
        }
        preOrder(Root);
        cout << endl;
        num = 0;
        inOrder(Root);
        cout << endl;
        num = 0;
        postOrder(Root);
        cout << endl;
        
    }
    return 0;
}