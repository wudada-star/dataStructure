#include <iostream>
using namespace std;
class ListNode
{
public:
    int data1, data2;//��Ҫ�������ݾ��ڽ���мӼ�������
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
        ListNode* q = head;//���������ͷ�ڵ��q
        int d1, d2;
        for (i = 0; i < n; i++)
        {
            cin >> d1 >> d2;//����ϵ����ָ��
            ListNode* p = new ListNode;//����p���Ŀռ�
            p->data1 = d1;
            p->data2 = d2;
            q->next = p;//���ý�����������
            p->next = NULL;
            q = p;//p��Ϊ��һ���������һ�����
        }
        len = n;
    }
    void display()
    {
        int i;
        ListNode* p = head->next;
        for (i = 0; i < len; i++)
        {
            if (p->data1 == 0)//��ϵ��Ϊ0ʱ
            {
                p = p->next;
                continue;
            }
            else if (p->data2 == 0)//��ָ��Ϊ0ʱ
            {
                if (p->data1 < 0)
                    cout << "(" << p->data1 << ")";
                else
                    cout << p->data1;
                p = p->next;
            }
            else//��ϵ����ָ������Ϊ0ʱ
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
        ListNode* s = pre->next;//��һ������ĵ�һ�����
        ListNode* r = q->head->next;//�ڶ�������ĵ�һ�����

        while (s != NULL && r != NULL)
        {
            if (s->data2 < r->data2)//����һ�������ϵ��С�ڵڶ�������ʱ����һ������ָ���һ��ָ�룬��Ϊ��ӵĽ����Ҫ�����һ����������ֻҪָ�����������
            {
                s = s->next;
                pre = pre->next;
            }
            else if (s->data2 == r->data2)//���ϵ����ͬ
            {
                s->data1 = s->data1 + r->data1;
                s = s->next;
                pre = pre->next;
                r = r->next;
                q->len--;//����2������ĳ��ȼ�1������������ʱ�Ͳ���ɾ��ͬһ����ַ��������������
            }
            else//���ڶ��������ָ��С�ڵ�һ������ʱ���ǾͰѵڶ�������ĸ�ָ����뵽��һ�������ǰ��
            {
                ListNode* m = new ListNode;
                m->data1 = r->data1;//�ڶ��������ϵ����m
                m->data2 = r->data2;//�ڶ��������ָ����m
                m->next = s;//s��Ϊm����һ�����
                pre->next = m;//m��Ϊs����һ�����
                r = r->next;//�ڶ����������һ������r
                pre = pre->next;
                q->len--;//����2������ĳ��ȼ�1 
            }
        }
        if (r)//����s�Ѿ��ӵ����һ���ˣ����ǵڶ�������û�м��꣬�Ǿͽ��ڶ�������ӵ���һ��������
        {
            pre->next = r;
            len = len + q->len;//���ϵڶ�������ʣ�µĳ��ȣ�����ڶ�������ĳ��ȾͲ��ü��ˣ���Ϊ��Ҫ�õ����ĵ�ַ��������дq->len--;
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
        linklist* l1 = new linklist, * l2 = new linklist;//������������
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