#include<iostream>
#include<string>
#include<cstring>
using namespace std;
#define error -1;
#define ok 1;
const int MaxW = 9999999;  // ������Ȩֵ������9999999
// ����huffman�������
class HuffNode
{
public:
    int weight;     // Ȩֵ
    int parent;     // ������±�
    int leftchild;  // �����±�
    int rightchild; // �Һ����±�
    char c_Tree;
};
// ����շ�������
class HuffMan
{
private:
    void MakeTree();    // ������˽�к����������к�������
    void SelectMin(int pos, int* s1, int* s2);  // �� 1 �� pos ��λ���ҳ�Ȩֵ��С��������㣬�ѽ���±���� s1 �� s2 ��
public:
    int len;    // �������
    int lnum;   // Ҷ������
    HuffNode* huffTree; // �շ��������������ʾ
    string* huffCode;   // ÿ���ַ���Ӧ�ĺշ�������
    void MakeTree(int n, int wt[], char* c_T); // ���к�������������main����
    void Coding();  // ���к�������������main����
    void Destroy();
    int Decode(const string codestr, char txtstr[]);
};
// ����huffman��
void HuffMan::MakeTree(int n, int wt[], char* c_T)
{
    // ������Ҷ�ӽ��������Ҷ��Ȩֵ
    // ���к���������ӿ�
    int i;
    lnum = n;
    len = 2 * n - 1;
    huffTree = new HuffNode[2 * n];
    huffCode = new string[lnum + 1];    // λ�ô� 1 ��ʼ����
    // huffCodeʵ���Ǹ���ά�ַ����飬�� i �б�ʾ�� i ���ַ���Ӧ�ı���
    // �շ�����huffTree��ʼ��
    for (i = 1; i <= n; i++)
    {
        huffTree[i].weight = wt[i - 1]; // ��0�Ų��ã���1��ʼ���
        huffTree[i].c_Tree = c_T[i - 1];
    }
    for (i = 1; i <= len; i++)
    {
        if (i > n) {
            huffTree[i].weight = 0;  // ǰn�������Ҷ�ӣ��Ѿ�����
            huffTree[i].c_Tree = '0';
        }
        huffTree[i].parent = 0;
        huffTree[i].leftchild = 0;
        huffTree[i].rightchild = 0;
    }
    MakeTree();  // ����˽�к�������
}
void HuffMan::SelectMin(int pos, int* s1, int* s2)
{
    // �ҳ���С������Ȩֵ���±�
    // �������õ�ַ���ݵķ������ҳ������±걣���� s1 �� s2 ��
    int w1, w2, i;
    w1 = w2 = MaxW;  // ��ʼ��w1��w2Ϊ���ֵ���ڱȽ��лᱻʵ�ʵ�Ȩֵ�滻
    *s1 = *s2 = 0;
    for (i = 1; i <= pos; i++)
    {
        if (huffTree[i].weight < w1 && huffTree[i].parent == 0) {
            w2 = w1;
            *s2 = *s1;
            w1 = huffTree[i].weight;
            *s1 = i;
        }
        else if (huffTree[i].weight < w2 && huffTree[i].parent == 0) {
            w2 = huffTree[i].weight;
            *s2 = i;
        }
    }
}
void HuffMan::MakeTree()
{
    // ˽�к����������к�������
    int i, s1, s2;
    for (i = lnum + 1; i <= len; i++)
    {
        SelectMin(i - 1, &s1, &s2);  // �ҳ�������СȨֵ���±���� s1 �� s2 ��
        // ���ҳ�������Ȩֵ��С�������ϲ�Ϊһ�����������̰���
        huffTree[s1].parent = huffTree[s2].parent = i;
        huffTree[i].rightchild = s2;
        huffTree[i].leftchild = s1;
        huffTree[i].weight = huffTree[s1].weight + huffTree[s2].weight;

    }
}
// ���ٺշ�����
void HuffMan::Destroy()
{
    len = 0;
    lnum = 0;
    delete[]huffTree;
    delete[]huffCode;
}
// �շ�������
void HuffMan::Coding()
{
    char* cd;
    int i, c, f, start;
    // �� n �����ĺշ�������
    cd = new char[lnum];    // ���������Ĺ����ռ�
    cd[lnum - 1] = '\0';    // ���������
    for (i = 1; i <= lnum; ++i)
    {
        // ����ַ���շ�������
        start = lnum - 1;   // ���������λ��
        for (int c = i, f = huffTree[i].parent; f != 0; c = f, f = huffTree[f].parent) {
            if (huffTree[f].leftchild == c)
                cd[--start] = '0';
            else
                cd[--start] = '1';
        }

        huffCode[i] = new char[lnum - start];
        huffCode[i].assign(&cd[start]); // ��cd�д�start��ĩβ�ı��븴�Ƶ�huffCode��
    }
    delete[]cd;    // �ͷŹ����ռ�
}
int HuffMan::Decode(const string codestr, char txtstr[]) {
    int i, k, c;
    char ch;
    c = len;
    k = 0;
    for (i = 0; i < codestr.length(); i++) {
        ch = codestr[i];
        if (ch == '0') {
            c = huffTree[c].leftchild;
        }
        else if (ch == '1') {
            c = huffTree[c].rightchild;
        }
        else {
            return error;
        }
        if (huffTree[c].leftchild == 0 && huffTree[c].rightchild == 0) {
            txtstr[k++] = c = huffTree[c].c_Tree;
            c = len;
        }
        else {
            ch = '\0';
        }
    }
    if (ch == '\0') {
        return error;
    }
    else {
        txtstr[k] = '\0';
    }
    return ok;
}
// ������
int main()
{
    int t, n, m, i, j;
    int wt[800];
    char c_T[800];
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> wt[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> c_T[i];
        }
        cin >> m;
        string codeStr;
        char txtStr[800];
        HuffMan myHuff;
        myHuff.MakeTree(n, wt, c_T);
        myHuff.Coding();
        while (m--) {
            cin >> codeStr;
            if (myHuff.Decode(codeStr, txtStr) == 1) {
                cout << txtStr << endl;
            }
            else {
                cout << "error" << endl;
            }
        }
        myHuff.Destroy();
    }
    return 0;
}