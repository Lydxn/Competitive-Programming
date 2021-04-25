#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, l, c, s;
	cin >> t;

	while (t--)
	{
		cin >> l >> c >> s;
		++s;

		for (int i = 0; i < s * l + 1; i++)
		{
			for (int j = 0; j < s * c + 1; j++)
			{
				if (i % s == 0 || j % s == 0) cout << '*';
				else if ((i / s + j / s) % 2 == 0) cout << (i % s == j % s ? '\\' : '.');
				else cout << (i % s == s - j % s ? '/' : '.');
			}
			cout << '\n';
		}
		cout << '\n';
	}
	return 0;
}
