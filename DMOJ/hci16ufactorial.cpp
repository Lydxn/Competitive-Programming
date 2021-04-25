#include <iostream>
#include <string>

typedef long long ll;

using namespace std;

ll fact(ll N)
{
	ll res = 1;
	for (ll i = 2; i <= N; i++)
	{
		res *= i;
	}
	return res;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	string line;
	getline(cin, line);

	for (int i = 1; i < line.length(); i++)
	{
		if (line[i] == '!' && isdigit(line[i - 1]))
		{
			if (i > 1 && isdigit(line[i - 2]))
			{
				cout << fact((line[i - 2] - '0') * 10 + (line[i - 1] - '0')) << "\n";
			}
			else
			{
				cout << fact(line[i - 1] - '0') << "\n";
			}
			return 0;
		}
	}

	cout << -1 << "\n";
	return 0;
}
