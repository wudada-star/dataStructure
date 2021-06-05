#include <iostream>
#include <string>
using namespace std;

class myString {
    string S;//主串
    string T;//模式串
    int* next;
    void getNext();
public:
    myString();
    int KMP();
    void output();
};

myString::myString() {
    cin >> S >> T;
    next = new int[T.length()];//创建next函数
}
int myString::KMP() {
    int i, j;

    for (i = 0, j = 0; i < S.length() && j < (int)T.length();)
    {
        if (j == -1 || S[i] == T[j])//如果字母相等均往后移动一位
            i++, j++;
        else
            j = next[j];//不相等调用next
    }
    if (j == T.length())//说明有匹配的
        return i - j + 1;//返回第一个匹配的位置
    return 0;
}

void myString::getNext() {//对next数组赋值，即计算出子串对应的next值
    int i, j;
    i = 0, j = -1;//1位置才存放next值
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
