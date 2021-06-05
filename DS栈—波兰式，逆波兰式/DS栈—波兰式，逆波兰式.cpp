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
	void change_reverse();   //逆波兰数转换
	void priority(char c);  //判断优先级
	void change_concur(); //波兰式转换
	void priority1(char c);   //波兰式判断优先级
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
	//如果是左括号，则优先级最低
	else j = 0;
	if (c == '+' || c == '-')
		i = 1;
	else
		i = 2;
	//如果栈顶的符号的优先级小于下一个符号的优先级，则将下一个符号压栈
	if (j < i)
		reverse.push(c);
	//如果栈顶符号的优先级大于等于下一个符号的优先级，则将栈顶元素输出并且弹出
	//然后再继续比较，直到该符号的优先级大于栈顶符号的优先级为止（递归调用）
	else {
		cout << reverse.top() << ' ';
		reverse.pop();
		priority(c);
	}
}
void poland::change_reverse() {
	for (int i = 0; i < size; i++)
	{
		//如果是数字，直接输出，不做压栈处理
		if (str[i] >= '0' && str[i] <= '9')
		{
			if (str[i + 1] >= '0' && str[i + 1] <= '9') {
				cout << str[i] << str[i + 1] << ' ';
				i++;
			}
			else cout << str[i] << ' ';
		}
		//如果是左括号，将其压栈
		else if (str[i] == '(')
			reverse.push(str[i]);
		//如果是右括号，将栈顶的运算符弹出并且输出，直到遇到左括号
		else if (str[i] == ')') {
			while (reverse.top() != '(') {
				cout << reverse.top() << ' ';
				reverse.pop();
			}
			reverse.pop();

		}
		//如果是运算符，判断优先级
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
	//如果是左括号，则优先级最高
	else j = 0;
	if (c == '+' || c == '-')
		i = 2;
	else
		i = 4;
	//如果栈顶的符号的优先级大于下一个符号的优先级，则将栈顶元素输出并且弹出,
	//将下一个符号压栈
	//然后再继续比较，直到该符号的优先级大于栈顶符号的优先级为止（递归调用）
	if (j > i) {
		change = change + concur.top() + ' ';
		concur.pop();
		priority1(c);
	}
	//如果栈顶符号的优先级小于下一个符号的优先级,将该符号压栈
	else
		concur.push(c);
}
void poland::change_concur()
{
	{
		for (int i = size - 1; i >= 0; i--)
		{
			//如果是数字，直接存入转换的字符串中，不做压栈处理
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
			//如果是左括号，将其压栈
			else if (str[i] == ')')
				concur.push('(');
			//如果是右括号，将栈顶的运算符弹出并且输出，直到遇到左括号
			else if (str[i] == '(') {
				while (concur.top() != '(') {
					change = change + concur.top() + ' ';
					concur.pop();
				}
				concur.pop();

			}
			//如果是运算符，判断优先级
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