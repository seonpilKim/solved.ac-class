#include <iostream>
#include <stack>

using namespace std;

void Postfix(const string&);

int main() {
	string infix;

	cin >> infix;

	Postfix(infix);

	return 0;
}

void Postfix(const string& infix) {
	stack<char> s;

	for (int i = 0; i < infix.size(); i++) {
		if (infix[i] == '(') s.push(infix[i]);

		else if (infix[i] == ')') {
			while (!s.empty() && s.top() != '(') {
				cout << s.top(); s.pop();
			}
			s.pop();
		}

		else if (infix[i] == '+' || infix[i] == '-') {
			while (!s.empty() && s.top() != '(') {
				cout << s.top(); s.pop();
			}
			s.push(infix[i]);
		}

		else if (infix[i] == '*' || infix[i] == '/') {
			while (!s.empty() && ((s.top() == '*') || (s.top() == '/'))) {
				cout << s.top(); s.pop();
			}
			s.push(infix[i]);
		}

		else cout << infix[i];
	}

	while (!s.empty()) {
		cout << s.top(); s.pop();
	}
}
