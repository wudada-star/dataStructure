#include<iostream>
#include<string>
using namespace std;
const int maxx = 100000 + 10;//习惯写法，题目中是因为有表明操作的次数，如果没有可能用到这一步
struct Node {//声明一个结点结构体
    char key;//结点的数值
    struct Node* prev, * next;//结点的前一个结点和后一个结点指针
};
int sum=0;//链表中结点个数
Node* nil;//全局声明一个头结点
void init()//链表初始化
{
    nil = new Node();//为头结点开辟空间
    //nil=(Node*)malloc(sizeof(Node));
    nil->next = nil;//前后指针均指向头结点，这里就形成了一个循环链表
    nil->prev = nil;
}
//从链表中搜索出值为key的结点
Node* listSearch(int wz,char cc)
{
    //从链表头结点开始访问
    Node* cur = nil->next;
    for (int i = 0; i < wz; i++)
    {
        cur = cur->next;
    }
    Node* x = new Node();//创建该节点的空间，注意不是用数组的形式来存储数据，而是采用开辟一个新空间加上指针来实现数据在内存中的链式结构
    x->key = cc;
    x->prev = cur->prev;
    cur->prev->next=x;
    x->next = cur;
    cur->prev=x;//找到位置并插入
    sum += 1;
    return x;//返回的是插入位置的结点
}
//在链表的头部插入一个结点
void insert(char key)
{
    Node* x = new Node();//创建该节点的空间，注意不是用数组的形式来存储数据，而是采用开辟一个新空间加上指针来实现数据在内存中的链式结构
    x->key = key;
    x->prev = nil->prev;
    nil->prev->next=x;
    x->next = nil;
     nil->prev=x;//右边的值赋给左边，所以对于插入的结点在左边的有两次，对于插入节点的前一个结点，它的后指针作为左值有一次，
                //对于插入节点的后一个结点，它的前指针作为左值有一次，
    sum += 1;
}
//删除结点t
void deleteNode(Node* t)
{
    if (t == nil)return;
    t->next->prev = t->prev;
    t->prev->next = t->next;//将要删除的结点的前一个和后一个结点的指向改变，先后顺序都可以
    delete (t);
    sum--;
}
//打印链表
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
    init();//初始化链表
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
        int len1 = 0;//插入点前面相同颜色球的个数
        int len2 = 0;//插入点后面相同颜色球的个数
        cin >> wz >> cc;
        Node* cur = listSearch(wz, cc);
        while (sum >= 3)//链表中的数剩余大于3个
        {
            if (cur->prev->key == cur->key) {
                len1 += 1;
                if (cur->prev->prev->key == cur->key)len1 += 1;
            }
            if (cur->next->key == cur->key) {
                len2 += 1;
                if (cur->next->next->key == cur->key)len2 += 1;
            }
            len = len1 + len2;//前后相同颜色的总个数
            if (len >= 2)//如果大于等于2执行消去
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
                    cur = cur->next;//将cur的下一个结点给cur
                    deleteNode(cur->prev);
                }
                else if (cur->prev != nil)
                {
                    cur = cur->prev;
                    deleteNode(cur->next);
                }
                else deleteNode(cur);//如果只剩下最后一个结点，那就直接删除该结点
            }
            else
            {
                print();//如果不用消去了，就输出
                break;
            }
             if (sum == 0)print();
        }
        if (sum < 3 && sum != 0)print();
    }
        return 0;
}