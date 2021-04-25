#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string to_str(int n)
{
	string res;
	while (n)
	{
		res.append(string(1, (n - 1) % 26 + 'A'));
		n = n / 26 - !(n % 26);
	}

	reverse(res.begin(), res.end());
	return res;
}

int to_num(string s)
{
	int res = 0;
	for (char c : s)
	{
		res = res * 26 + c - 'A' + 1;
	}
	return res;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, cpos;
	cin >> n;

	string coord;
	while (n--)
	{
		cin >> coord;
		string row, col;

		cpos = coord.find_last_not_of("0123456789");
		if (isdigit(coord[cpos - 1]))
		{
			row = coord.substr(1, cpos - 1);
			col = coord.substr(cpos + 1);
			cout << to_str(stoi(col)) << row << '\n';
		}
		else
		{
			row = coord.substr(0, cpos + 1);
			col = coord.substr(cpos + 1);
			cout << 'R' << col << 'C' << to_num(row) << '\n';
		}
	}
	return 0;
}
