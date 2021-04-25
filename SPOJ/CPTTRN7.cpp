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
		for (int i = 0; i < l * s * 2; i++)
		{
			for (int j = 0; j < c * s * 2; j++)
			{
				if (!(i / s % 2 == 0) ^ (j / s % 2 == 0)) cout << (i % s + j % s == s - 1 ? '/' : '.');
				else cout << (i % s == j % s ? '\\' : '.');
			}
			cout << '\n';
		}
		cout << '\n';
	}
	return 0;
}
