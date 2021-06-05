#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    int t, len, i;
    string str;
    stack<char> s;
    cin >> t;
    while (t--) {
        cin >> str;
        len = str.length();
        for (i = 0; i < len; i++) {
            if (str[i] == '(' || str[i] == '[' || str[i] == '{')
                s.push(str[i]);
            else if (str[i] == ')')
            {
                if (s.empty())
                    break;
                if (s.top() == '(') {
                    s.pop();
                    continue;
                }
                else
                    break;
            }
            else if (str[i] == ']')
            {
                if (s.empty())
                    break;
                if (s.top() == '[') {
                    s.pop();
                    continue;
                }
                else
                    break;
            }
            else if (str[i] == '}')
            {
                if (s.empty())
                    break;
                if (s.top() == '{') {
                    s.pop();
                    continue;
                }
                else
                    break;
            }
        }
        if (i == len && s.empty())
            cout << "ok" << endl;
        else
            cout << "error" << endl;
        while (!s.empty())
            s.pop();
    }
    return 0;
}