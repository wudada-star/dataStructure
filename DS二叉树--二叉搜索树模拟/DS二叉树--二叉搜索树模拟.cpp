#include<iostream>
using namespace std;
int num = 0;//ȫ�ֱ�����ʹ������ո�
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
void addTree(int shu, node* root) {//����������������������ȡֵ��������߷�С��ֵ���ұ߷Ŵ��ֵ

    while (true) {
        if (shu < root->data) {//�����ֵС�ڸ������ݣ�����������
            if (!root->left) {//���root��������Ϊ��
                root->left = new node();
                root->left->data = shu;
                return;
            }
            else {
                root = root->left;
            }
        }
        else {
            if (!root->right) {//�����ֵ���ڸ������ݣ�����������
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
        node* Root = NULL;//����һ��ѭ�����ָ��ʹѭ���ڶ��ܹ����õ�������ĸ�ָ��
        if (n >= 1)//������һ�������
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