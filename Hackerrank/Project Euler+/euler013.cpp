#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string add(string a, string b)
{
	if (a.size() > b.size()) swap(a, b);

	string res = "";
	int len_a = a.size(), len_b = b.size(), diff = len_b - len_a, carry = 0, sum;
	
	for (int i = len_a - 1; i >= 0; i--)
	{
		sum = (a[i] - '0') + (b[i + diff] - '0') + carry;
		res.push_back(sum % 10 + '0');
		carry = sum / 10;
	}

	for (int i = diff - 1; i >= 0; i--)
	{
		sum = (b[i] - '0') + carry;
		res.push_back(sum % 10 + '0');
		carry = sum / 10;
	}

	if (carry) res.push_back(carry + '0');
	reverse(res.begin(), res.end());
	return res;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	string num, sum = "0";
	while (N--)
	{
		cin >> num;
		sum = add(sum, num);
	}

	cout << sum.substr(0, 10) << '\n';
}
