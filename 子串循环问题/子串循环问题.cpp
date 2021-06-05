#include <iostream>
using namespace std;

class compare {
	string a;//模式串
	string b;//前缀
	string c;//后缀
	string same;//在模式串中找到最长的重复子串，注意这种重复子串是
				//由真前后缀来判断的，而不是随便找两段相等的子串
public:
	compare(string s) { a = s; }
	int find();
};
int compare::find() {
	int max = 0;
	int len = a.length();
	for (int i = 0, j = len - 1; i < len; i++, j--) {
		b += a[i];//前缀，包括到字符串的最后一个
		c = a[j] + c;//后缀，包括到字符串的最前一个
		if (b == c && max < b.length() && b.length() != len) {
			same = b;
			max = same.length();
		}
	}
	return max;//最长重复子串的长度
}

int main()
{
	int next;
	int n;
	int r;
	int len;
	string s;//模式串
	cin >> n;
	while (n--) {
		cin >> s;
		len = s.length();
		compare p(s);
		next = p.find();//最长重复子串的长度
		r = len - next;//得到减去重复子串后剩余的段
		if (len % r == 0 && r != len)//如果next为len一半，如果next为0
			cout << 0 << endl;
		else cout << r - len % r << endl;
	}
	return 0;
}