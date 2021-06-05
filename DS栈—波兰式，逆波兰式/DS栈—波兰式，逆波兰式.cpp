#include <iostream>
#include <string>
#include <stack>
using namespace std;

class poland {
	stack<char> concur;
	stack<char> reverse;
	string str;
	string change;
	int size;
public:
	poland(string r) {
		str = r;
		size = str.length();
	}
	void change_reverse();   //�沨����ת��
	void priority(char c);  //�ж����ȼ�
	void change_concur(); //����ʽת��
	void priority1(char c);   //����ʽ�ж����ȼ�
};
void poland::priority(char c) {
	int i, j;
	if (reverse.empty()) {
		j = 0;
	}
	else if (reverse.top() == '+' || reverse.top() == '-')
		j = 1;
	else if (reverse.top() == '*' || reverse.top() == '/')
		j = 2;
	//����������ţ������ȼ����
	else j = 0;
	if (c == '+' || c == '-')
		i = 1;
	else
		i = 2;
	//���ջ���ķ��ŵ����ȼ�С����һ�����ŵ����ȼ�������һ������ѹջ
	if (j < i)
		reverse.push(c);
	//���ջ�����ŵ����ȼ����ڵ�����һ�����ŵ����ȼ�����ջ��Ԫ��������ҵ���
	//Ȼ���ټ����Ƚϣ�ֱ���÷��ŵ����ȼ�����ջ�����ŵ����ȼ�Ϊֹ���ݹ���ã�
	else {
		cout << reverse.top() << ' ';
		reverse.pop();
		priority(c);
	}
}
void poland::change_reverse() {
	for (int i = 0; i < size; i++)
	{
		//��������֣�ֱ�����������ѹջ����
		if (str[i] >= '0' && str[i] <= '9')
		{
			if (str[i + 1] >= '0' && str[i + 1] <= '9') {
				cout << str[i] << str[i + 1] << ' ';
				i++;
			}
			else cout << str[i] << ' ';
		}
		//����������ţ�����ѹջ
		else if (str[i] == '(')
			reverse.push(str[i]);
		//����������ţ���ջ����������������������ֱ������������
		else if (str[i] == ')') {
			while (reverse.top() != '(') {
				cout << reverse.top() << ' ';
				reverse.pop();
			}
			reverse.pop();

		}
		//�������������ж����ȼ�
		else if (str[i] == '*' || str[i] == '/' || str[i] == '-' || str[i] == '+') {
			if (reverse.empty())
				reverse.push(str[i]);
			else
				priority(str[i]);
		}
	}
	while (!reverse.empty()) {
		cout << reverse.top() << ' ';
		reverse.pop();
	}
	cout << endl;
}
void poland::priority1(char c) {
	int i, j;
	if (concur.empty()) {
		j = 0;
	}
	else if (concur.top() == '+' || concur.top() == '-')
		j = 1;
	else if (concur.top() == '*' || concur.top() == '/')
		j = 3;
	//����������ţ������ȼ����
	else j = 0;
	if (c == '+' || c == '-')
		i = 2;
	else
		i = 4;
	//���ջ���ķ��ŵ����ȼ�������һ�����ŵ����ȼ�����ջ��Ԫ��������ҵ���,
	//����һ������ѹջ
	//Ȼ���ټ����Ƚϣ�ֱ���÷��ŵ����ȼ�����ջ�����ŵ����ȼ�Ϊֹ���ݹ���ã�
	if (j > i) {
		change = change + concur.top() + ' ';
		concur.pop();
		priority1(c);
	}
	//���ջ�����ŵ����ȼ�С����һ�����ŵ����ȼ�,���÷���ѹջ
	else
		concur.push(c);
}
void poland::change_concur()
{
	{
		for (int i = size - 1; i >= 0; i--)
		{
			//��������֣�ֱ�Ӵ���ת�����ַ����У�����ѹջ����
			if (str[i] >= '0' && str[i] <= '9')
			{
				if (i != 0) {
					if (str[i - 1] >= '0' && str[i - 1] <= '9') {
						change = change + str[i] + str[i - 1] + ' ';
						i--;
					}
					else
						change = change + str[i] + ' ';
				}
				else change = change + str[i] + ' ';
			}
			//����������ţ�����ѹջ
			else if (str[i] == ')')
				concur.push('(');
			//����������ţ���ջ����������������������ֱ������������
			else if (str[i] == '(') {
				while (concur.top() != '(') {
					change = change + concur.top() + ' ';
					concur.pop();
				}
				concur.pop();

			}
			//�������������ж����ȼ�
			else if (str[i] == '*' || str[i] == '/' || str[i] == '-' || str[i] == '+') {
				if (concur.empty())
					concur.push(str[i]);
				else
					priority1(str[i]);
			}
		}
		while (!concur.empty()) {
			change = change + concur.top() + ' ';
			concur.pop();
		}
		for (int i = change.length() - 2; i >= 0; i--)
			cout << change[i];
		cout << endl;
		change = '/0';
	}
}

int main() {
	int t;
	string str;
	cin >> t;
	while (t--) {
		cin >> str;
		poland p(str);
		p.change_concur();
		p.change_reverse();
		cout << endl;
	}
	return 0;
}