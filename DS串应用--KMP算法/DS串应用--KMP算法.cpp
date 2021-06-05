#include <iostream>
#include <string>
using namespace std;

class myString {
    string S;//����
    string T;//ģʽ��
    int* next;
    void getNext();
public:
    myString();
    int KMP();
    void output();
};

myString::myString() {
    cin >> S >> T;
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
        return i - j + 1;//���ص�һ��ƥ���λ��
    return 0;
}

void myString::getNext() {//��next���鸳ֵ����������Ӵ���Ӧ��nextֵ
    int i, j;
    i = 0, j = -1;//1λ�òŴ��nextֵ
    next[i] = j;//next[0]=-1;
    while (i < T.length())
    {
        if (j == -1 || T[i] == T[j])
            next[++i] = ++j;//next[1]=0;
        else
            j = next[j];
    }
}

void myString::output() {
    getNext();
    for (int i = 0; i < (int)T.length(); i++)
        cout << next[i] << ' ';
    cout << endl;
    cout << KMP() << endl;
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
