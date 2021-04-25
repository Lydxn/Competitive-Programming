#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

string accounts[100000];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n;
	cin >> t;

	while (t--)
	{
		cin >> n;
		getline(cin, accounts[0]);
		for (int i = 0; i < n; i++) getline(cin, accounts[i]);

		sort(accounts, accounts + n);

		for (int i = 0, rep = 1; i < n; i++)
		{
			if (accounts[i] == accounts[i + 1]) ++rep;
			else
			{
				cout << accounts[i] << ' ' << rep << '\n';
				rep = 1;
			}
		}

		if (t) putchar('\n');
	}
	return 0;
}
