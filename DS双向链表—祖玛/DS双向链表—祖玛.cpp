#include<iostream>
#include<string>
using namespace std;
const int maxx = 100000 + 10;//ϰ��д������Ŀ������Ϊ�б��������Ĵ��������û�п����õ���һ��
struct Node {//����һ�����ṹ��
    char key;//������ֵ
    struct Node* prev, * next;//����ǰһ�����ͺ�һ�����ָ��
};
int sum=0;//�����н�����
Node* nil;//ȫ������һ��ͷ���
void init()//�����ʼ��
{
    nil = new Node();//Ϊͷ��㿪�ٿռ�
    //nil=(Node*)malloc(sizeof(Node));
    nil->next = nil;//ǰ��ָ���ָ��ͷ��㣬������γ���һ��ѭ������
    nil->prev = nil;
}
//��������������ֵΪkey�Ľ��
Node* listSearch(int wz,char cc)
{
    //������ͷ��㿪ʼ����
    Node* cur = nil->next;
    for (int i = 0; i < wz; i++)
    {
        cur = cur->next;
    }
    Node* x = new Node();//�����ýڵ�Ŀռ䣬ע�ⲻ�����������ʽ���洢���ݣ����ǲ��ÿ���һ���¿ռ����ָ����ʵ���������ڴ��е���ʽ�ṹ
    x->key = cc;
    x->prev = cur->prev;
    cur->prev->next=x;
    x->next = cur;
    cur->prev=x;//�ҵ�λ�ò�����
    sum += 1;
    return x;//���ص��ǲ���λ�õĽ��
}
//�������ͷ������һ�����
void insert(char key)
{
    Node* x = new Node();//�����ýڵ�Ŀռ䣬ע�ⲻ�����������ʽ���洢���ݣ����ǲ��ÿ���һ���¿ռ����ָ����ʵ���������ڴ��е���ʽ�ṹ
    x->key = key;
    x->prev = nil->prev;
    nil->prev->next=x;
    x->next = nil;
     nil->prev=x;//�ұߵ�ֵ������ߣ����Զ��ڲ���Ľ������ߵ������Σ����ڲ���ڵ��ǰһ����㣬���ĺ�ָ����Ϊ��ֵ��һ�Σ�
                //���ڲ���ڵ�ĺ�һ����㣬����ǰָ����Ϊ��ֵ��һ�Σ�
    sum += 1;
}
//ɾ�����t
void deleteNode(Node* t)
{
    if (t == nil)return;
    t->next->prev = t->prev;
    t->prev->next = t->next;//��Ҫɾ���Ľ���ǰһ���ͺ�һ������ָ��ı䣬�Ⱥ�˳�򶼿���
    delete (t);
    sum--;
}
//��ӡ����
void print()
{
    Node* cur = nil->next;
    if (cur == nil)cout << "-" ;
    while (cur != nil)
    {
            cout << cur->key;
            cur = cur->next;
    }
    cout << endl;
}
int main()
{
    string str;
    int num, wz;
    char cc;
    init();//��ʼ������
    cin >> str;
    int n = str.length();
    for (int i = 0; i < n; i++)
    {
        insert(str[i]);
    }
    cin >> num;
    while (num--)
    {
        int len = 0;
        int len1 = 0;//�����ǰ����ͬ��ɫ��ĸ���
        int len2 = 0;//����������ͬ��ɫ��ĸ���
        cin >> wz >> cc;
        Node* cur = listSearch(wz, cc);
        while (sum >= 3)//�����е���ʣ�����3��
        {
            if (cur->prev->key == cur->key) {
                len1 += 1;
                if (cur->prev->prev->key == cur->key)len1 += 1;
            }
            if (cur->next->key == cur->key) {
                len2 += 1;
                if (cur->next->next->key == cur->key)len2 += 1;
            }
            len = len1 + len2;//ǰ����ͬ��ɫ���ܸ���
            if (len >= 2)//������ڵ���2ִ����ȥ
            {
                if (len1 == 1) { deleteNode(cur->prev); len1 -= 1; }
                else if (len1 == 2) {
                    deleteNode(cur->prev);
                    deleteNode(cur->prev);
                    len1 -= 2;
                }
                if (len2 == 1) {
                    deleteNode(cur->next); len2 -= 1;
                }
                else if (len2 == 2) {
                    deleteNode(cur->next);
                    deleteNode(cur->next);
                    len2 -= 2;
                }
                if (cur->next != nil)
                {
                    cur = cur->next;//��cur����һ������cur
                    deleteNode(cur->prev);
                }
                else if (cur->prev != nil)
                {
                    cur = cur->prev;
                    deleteNode(cur->next);
                }
                else deleteNode(cur);//���ֻʣ�����һ����㣬�Ǿ�ֱ��ɾ���ý��
            }
            else
            {
                print();//���������ȥ�ˣ������
                break;
            }
             if (sum == 0)print();
        }
        if (sum < 3 && sum != 0)print();
    }
        return 0;
}