#include <iostream>
#include <string>
using namespace std;

class myString {
    string S;//����
    string T;//ģʽ��
    string T1;
    int* next;
    void getNext();
public:
    myString();
    int KMP();
    void output();
};

myString::myString() {
    cin >> S >> T>>T1;
    next = new int[T.length()];//����next����
}
int myString::KMP() {
    int i, j;

    for (i = 0, j = 0; i < S.length() && j < (int)T.length();)
    {
        if (j == -1 || S[i] == T[j])//�����ĸ��Ⱦ������ƶ�һλ
            i++, j++;
        else
            j = next[j];//����ȵ���next
    }
    if (j == T.length())//˵����ƥ���
        return i - j + 1;
    return 0;
}

void myString::getNext() {//��next���鸳ֵ����������Ӵ���Ӧ��nextֵ
    int i, j;
    i = 0, j = -1;//1λ�òŴ��nextֵ
    next[i] = j;//next[0]=-1;
    while (i < T.length())
    {
        if (j == -1 || T[i] == T[j])
            next[++i] = ++j;
        else
            j = next[j];
    }
}

void myString::output() {
    getNext();
   
    int n = KMP();
    int len1 = T1.length();
    int len2 = S.length();
    int len3 = T.length();
    cout << S << endl;
    if (n == 0)cout << S << endl;
    else {

    for (int i = 0; i < n-1; i++)
    {
        cout << S[i];
    }
    cout << T1;
    for (int i = n-1+len3; i < len2; i++)
    {
        cout << S[i];
    }
    cout << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        myString s;
        s.output();
    }
    return 0;
}
