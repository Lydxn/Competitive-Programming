#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 10000;
int digsum[MAXN + 1];

string mult(string a, string b)
{
	int len_a = a.size(), len_b = b.size();
	vector<int> res(len_a + len_b);

	for (int i = len_a - 1; i >= 0; i--)
	{
		for (int j = len_b - 1; j >= 0; j--)
		{
			int prod = (a[i] - '0') * (b[j] - '0');
			int pos = i + j;
			int sum = prod + res[pos + 1];

			res[pos] += sum / 10;
			res[pos + 1] = sum % 10;
		}
	}

	string s = "";
	for (int i = 0; i < res.size(); i++)
	{
		if (!(s.size() == 0 && res[i] == 0))
		{
			s.append(to_string(res[i]));
		}
	}
	return s.size() == 0 ? "0" : s;
}

void init_digsum()
{
	string pow = "2";
	for (int i = 1, sum; i <= MAXN; i++, pow = mult(pow, "2"))
	{
		sum = 0;
		for (char p : pow) sum += p - '0';
		digsum[i] = sum;
	}
}

int main()
{
	init_digsum();
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T, N;
	cin >> T;

	while (T--)
	{
		cin >> N;
		cout << digsum[N] << '\n';
	}
	return 0;
}
