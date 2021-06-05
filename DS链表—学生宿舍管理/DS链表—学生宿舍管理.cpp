#include <iostream>
#include<string>
using namespace std;

class ListNode
{
public:
    char people[20];
    int data;
    ListNode* next;
    ListNode() { next = NULL; }
};

class LinkList
{
public:
    int len;
    ListNode* head;
    LinkList();
    ~LinkList()
    {
        ListNode* p = head;
        ListNode* q;
        while (p)
        {
            q = p->next;
            delete p;
            p = q;
        }
        len = 0;
        head = NULL;
    }
};

LinkList::LinkList()
{
    len = 0;
    head = new ListNode;
}

int main(void)
{
    LinkList L1, L2;
    ListNode* q1 = L1.head;
    ListNode* q2 = L2.head;
    int n1, m;
    cin >> n1;
    int i, j;
    for (i = 0; i < n1; i++)
    {
        ListNode* p = new ListNode;
        cin >> p->people >> p->data;
        q1->next = p;
        q1 = q1->next;
    }
    ListNode* r;
    for (i = 101; i < 121; i++)
    {
        int x = 0;
        r = L1.head;
        for (j = 0; j < n1; j++)
        {
            r = r->next;
            if (r->data == i)
            {
                x = 1;
                break;
            }
        }
        if (0 == x)
        {
            ListNode* t = new ListNode;
            t->data = i;
            q2->next = t;
            q2 = q2->next;
        }
    }
    string a;
    cin >> m;
    while (m--)
    {
        cin >> a;
        if ("assign" == a)
        {
            q2 = L2.head;
            ListNode* p2 = q2->next;
            q2->next = p2->next;
            cin >> p2->people;
            q1 = L1.head;
            while (q1)
            {
                if ((q1->data < p2->data || q1 == L1.head) && (q1->next->data > p2->data || q1->next == NULL))
                {
                    p2->next = q1->next;
                    q1->next = p2;
                    break;
                }
                else
                    q1 = q1->next;
            }
        }
        else if ("return" == a)
        {
            int temp;
            cin >> temp;
            q1 = L1.head;
            while (q1)
            {
                q2 = q1->next;
                if (q2->data == temp)
                {
                    q1->next = q2->next;
                    ListNode* p1 = L2.head;
                    while (p1->next)
                        p1 = p1->next;
                    p1->next = q2;
                    q2->next = NULL;
                    break;
                }
                else
                    q1 = q1->next;
            }
        }
        else if ("display_free" == a)
        {
            ListNode* p1 = L2.head->next;
            while (p1)
            {
                cout << p1->data;
                if (p1->next)
                    cout << '-';
                p1 = p1->next;
            }
            cout << endl;
        }
        else if ("display_used" == a)
        {
            ListNode* p1 = L1.head->next;
            while (p1)
            {
                cout << p1->people << '(' << p1->data << ')';
                if (p1->next)
                    cout << '-';
                p1 = p1->next;
            }
            cout << endl;
        }
    }
    return 0;
}
