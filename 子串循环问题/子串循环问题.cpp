#include <iostream>
using namespace std;

class compare {
	string a;//ģʽ��
	string b;//ǰ׺
	string c;//��׺
	string same;//��ģʽ�����ҵ�����ظ��Ӵ���ע�������ظ��Ӵ���
				//����ǰ��׺���жϵģ������������������ȵ��Ӵ�
public:
	compare(string s) { a = s; }
	int find();
};
int compare::find() {
	int max = 0;
	int len = a.length();
	for (int i = 0, j = len - 1; i < len; i++, j--) {
		b += a[i];//ǰ׺���������ַ��������һ��
		c = a[j] + c;//��׺���������ַ�������ǰһ��
		if (b == c && max < b.length() && b.length() != len) {
			same = b;
			max = same.length();
		}
	}
	return max;//��ظ��Ӵ��ĳ���
}

int main()
{
	int next;
	int n;
	int r;
	int len;
	string s;//ģʽ��
	cin >> n;
	while (n--) {
		cin >> s;
		len = s.length();
		compare p(s);
		next = p.find();//��ظ��Ӵ��ĳ���
		r = len - next;//�õ���ȥ�ظ��Ӵ���ʣ��Ķ�
		if (len % r == 0 && r != len)//���nextΪlenһ�룬���nextΪ0
			cout << 0 << endl;
		else cout << r - len % r << endl;
	}
	return 0;
}