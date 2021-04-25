#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, l, c, h, w;
	cin >> t;

	while (t--)
	{
		cin >> l >> c >> h >> w;
		++h, ++w;

		for (int i = 1; i < h * (l + 1); i++)
		{
			for (int j = 1; j < w * (c + 1); j++)
			{
				if (i % h == 0) cout << (j % w ? '-' : '+');
				else if (j % w == 0) cout << '|';
				else cout << '.';
			}
			cout << '\n';
		}
		cout << '\n';
	}
	return 0;
}
