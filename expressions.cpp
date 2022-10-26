#include <bits/stdc++.h>
using namespace std;

int prefix(string str) {
	stack<int> s;
	for(int i = str.length()-1; i >= 0; i--) {
		if(!(str[i] >= '0' && str[i] <= '9') && str[i] != ' ') {
			int op1 = s.top(); s.pop();
			int op2 = s.top(); s.pop();
			int res = 0;
			switch(str[i]) {
				case '+': res = op1 + op2;
					break;
				case '-': res = op1 - op2;
					break;
				case '/': res = op1/op2;
					break;
				case '*': res = op1*op2;
					break;
				case '^': res = pow(op1, op2);
					break;
			}
			s.push(res);
		} else if(str[i] >= '0' && str[i] <= '9') {
			int n = 0, d = 1;
			while(i >= 0 && str[i] != ' ') {
				n = (str[i]-'0')*d + n;
				d *= 10;
				i--;
			}
			s.push(n);
		}
	}
	return s.top();
}

int postfix(string str) {
	stack<int> s;
	for(int i = 0; i < str.length(); i++) {
		if(!(str[i] >= '0' && str[i] <= '9') && str[i] != ' ') {
			int op2 = s.top(); s.pop();
			int op1 = s.top(); s.pop();
			int res = 0;
			switch(str[i]) {
				case '+': res = op1 + op2;
					break;
				case '-': res = op1 - op2;
					break;
				case '/': res = op1/op2;
					break;
				case '*': res = op1*op2;
					break;
				case '^': res = pow(op1, op2);
					break;
			}
			s.push(res);
		} else if(str[i] >= '0' && str[i] <= '9') {
			int n = 0, d = 1;
			while(i < str.length() && str[i] != ' ') {
				n = n*d + (str[i]-'0');
				d *= 10;
				i++;
			}
			s.push(n);
		}
	}
	return s.top();
}

int precedence(char c) {
	if(c == '^') return 3;
	if(c == '*' || c == '/') return 2;
	if(c == '+' || c == '-') return 1;
	return -1;
}

string infixToPostfix(string str) {
	stack<char> s;
	string t = "";
	for(int i = 0; i < str.length(); i++) {
		if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
			t += str[i];
		} else if(str[i] == '(') {
			s.push(str[i]);
		} else if(str[i] == ')') {
			while(!s.empty() && (s.top() != '(')) {
				t += s.top();
				s.pop();
			}
			s.pop();
		} else {
			while(!s.empty() && (precedence(s.top()) > precedence(str[i]))) {
				t += s.top();
				s.pop();
			}
			s.push(str[i]);
		}
	}
	while(!s.empty()) {
		t += s.top();
		s.pop();
	}
	return t;
}

string infixToPrefix(string str) {
	stack<char> s;
	string t = "";
	reverse(str.begin(), str.end());
	for(int i = 0; i < str.length(); i++) {
		if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
			t += str[i];
		} else if(str[i] == ')') {
			s.push(str[i]);
		} else if(str[i] == '(') {
			while(!s.empty() && (s.top() != ')')) {
				t += s.top();
				s.pop();
			}
			s.pop();
		} else {
			while(!s.empty() && (precedence(s.top()) >= precedence(str[i]))) {
				t += s.top();
				s.pop();
			}
			s.push(str[i]);
		}
	}
	while(!s.empty()) {
		t += s.top();
		s.pop();
	}
	reverse(t.begin(), t.end());
	return t;
}

bool balancedBrackets(string str) {
	stack<char> s;
	for(int i = 0; i < str.length(); i++) {
		if(str[i] == '(' || str[i] == '{' || str[i] == '[') {
			s.push(str[i]);
		} else if(str[i] == ')' && (!s.empty() && s.top() == '(')) {
			s.pop();
		} else if(str[i] == ']' && (!s.empty() && s.top() == '[')) {
			s.pop();
		}else if(str[i] == '}' && (!s.empty() && s.top() == '{')) {
			s.pop();
		} else return false;
	}
	return s.empty();
}

int main() {
	cout << prefix("- + 7 * 4 5 + 2 0") << endl;
	cout << postfix("4 6 + 2 / 5 * 7 +") << endl;
	cout << infixToPostfix("(a-b/c)*(a/k-l)") << endl;
	cout << infixToPrefix("(a-b/c)*(a/k-l)") << endl;
	cout << balancedBrackets("([{}])") << endl;
	return 0;
}