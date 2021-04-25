#include <iostream>
#include <string>
#include <vector>

using namespace std;

string mult(string a, string b)
{
	vector<int> res(159);
	int len_a = a.size(), len_b = b.size();
	for (int i = len_a - 1; i >= 0; i--)
	{
		for (int j = len_b - 1; j >= 0; j--)
		{
			int prod = (a.at(i) - '0') * (b.at(j) - '0');
			int pos = i + j;
			int sum = prod + res[pos + 1];

			res[pos] += sum / 10;
			res[pos + 1] = sum % 10;
		}
	}

	string s = "";
	for (int i = 0; i < len_a + len_b; i++)
	{
		if (!(s.size() == 0 && res[i] == 0))
		{
			s.append(to_string(res[i]));
		}
	}
	return s;
}

string fact(int n)
{
	string res = "1";
	for (int i = 2; i <= n; i++)
	{
		res = mult(res, to_string(i));
	}
	return res;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> n;
		cout << fact(n) << "\n";
	}
	return 0;
}
