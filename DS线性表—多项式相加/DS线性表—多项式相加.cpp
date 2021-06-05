#include <iostream>
using namespace std;
class ListNode
{
public:
    int data1, data2;//需要几个数据就在结点中加几个变量
    ListNode* next;
    ListNode()
    {
        next = NULL;
    }
};
class linklist
{
public:
    ListNode* head;
    int len;
    linklist()
    {
        head = new ListNode();
        len = 0;
    }
    ~linklist()
    {
        ListNode* p, * q;
        p = head;
        while (p)
        {
            q = p;
            p = p->next;
            delete q;
        }
        len = 0;
        head = NULL;
    }
    void createlist(int n)
    {
        int i;
        ListNode* q = head;//将该链表的头节点给q
        int d1, d2;
        for (i = 0; i < n; i++)
        {
            cin >> d1 >> d2;//输入系数和指数
            ListNode* p = new ListNode;//创建p结点的空间
            p->data1 = d1;
            p->data2 = d2;
            q->next = p;//将该结点插入链表中
            p->next = NULL;
            q = p;//p改为下一个输入的上一个结点
        }
        len = n;
    }
    void display()
    {
        int i;
        ListNode* p = head->next;
        for (i = 0; i < len; i++)
        {
            if (p->data1 == 0)//当系数为0时
            {
                p = p->next;
                continue;
            }
            else if (p->data2 == 0)//当指数为0时
            {
                if (p->data1 < 0)
                    cout << "(" << p->data1 << ")";
                else
                    cout << p->data1;
                p = p->next;
            }
            else//当系数和指数均不为0时
            {
                if (p->data1 < 0)
                    cout << "(" << p->data1 << ")x^";
                else
                    cout << p->data1 << "x^";
                if (p->data2 < 0)
                    cout << "(" << p->data2 << ")";
                else
                    cout << p->data2;
                p = p->next;
            }
            if (i != len - 1)
                cout << " + ";
        }
        cout << endl;
    }
    void add(linklist* q)
    {
        ListNode* pre = head;
        ListNode* s = pre->next;//第一个链表的第一个结点
        ListNode* r = q->head->next;//第二个链表的第一个结点

        while (s != NULL && r != NULL)
        {
            if (s->data2 < r->data2)//当第一个链表的系数小于第二个链表时，第一个链表指向后一个指针，因为相加的结果是要输出第一个链表，所以只要指针继续向后就行
            {
                s = s->next;
                pre = pre->next;
            }
            else if (s->data2 == r->data2)//如果系数相同
            {
                s->data1 = s->data1 + r->data1;
                s = s->next;
                pre = pre->next;
                r = r->next;
                q->len--;//将第2个链表的长度减1，这样在析构时就不会删除同一个地址，可以正常析构
            }
            else//当第二个链表的指数小于第一个链表时，那就把第二个链表的该指针插入到第一个链表的前面
            {
                ListNode* m = new ListNode;
                m->data1 = r->data1;//第二个链表的系数给m
                m->data2 = r->data2;//第二个链表的指数给m
                m->next = s;//s成为m的下一个结点
                pre->next = m;//m成为s的上一个结点
                r = r->next;//第二个链表的下一个结点给r
                pre = pre->next;
                q->len--;//将第2个链表的长度减1 
            }
        }
        if (r)//可能s已经加到最后一个了，但是第二个链表还没有加完，那就将第二个链表加到第一个链表上
        {
            pre->next = r;
            len = len + q->len;//加上第二个链表剩下的长度，这里第二个链表的长度就不用减了，因为还要用到它的地址，即不用写q->len--;
        }
    }
    ListNode* index(int i)
    {
        int k;
        ListNode* p = head;
        if (i != 0)
        {
            for (k = 1; k < i; k++)
            {
                p = p->next;
            }
            return p->next;
        }
        else
        {
            return head;
        }
    }
};
int main()
{
    int T, n, m;
    cin >> T;
    while (T--)
    {
        linklist* l1 = new linklist, * l2 = new linklist;//创建两个链表
        cin >> n;
        l1->createlist(n);
        cin >> m;
        l2->createlist(m);
        l1->display();
        l2->display();
        l1->add(l2);
        l1->display();
        delete l1, l2;
    }
    return 0;
}