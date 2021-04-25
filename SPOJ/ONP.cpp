#include <iostream>
#include <stack>
#include <string>

using namespace std;

int prec(char op)
{
	switch (op)
	{
	case '+': 
	case '-':
		return 0;
	case '*':
	case '/':
		return 1;
	case '^':
		return 2;
	}
	return -1;
}

string to_rpn(string expr)
{
	stack<char> st;
	string res = "";

	for (int i = 0; i < expr.size(); i++)
	{
		char ch = expr.at(i);
		if (isalpha(ch))
		{
			res += ch;
		}
		else if (ch == '(')
		{
			st.push(ch);
		}
		else if (ch == ')')
		{
			while (!st.empty() && st.top() != '(')
			{
				res += st.top();
				st.pop();
			}
			st.pop();
		}
		else
		{
			while (!st.empty() && prec(ch) <= prec(st.top()))
			{
				res += st.top();
				st.pop();
			}
			st.push(ch);
		}
	}
	return res;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	string expr;
	for (int i = 0; i < T; i++)
	{
		cin >> expr;
		cout << to_rpn(expr) << "\n";
	}
	return 0;
}
