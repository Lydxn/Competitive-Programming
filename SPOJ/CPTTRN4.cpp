#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, l, c, h, w;
	cin >> t;

	char symbols[] = { '*', '.' };
	while (t--)
	{
		cin >> l >> c >> h >> w;
		++h, ++w;

		for (int i = 0; i < h * l + 1; i++)
		{
			for (int j = 0; j < w * c + 1; j++)
			{
				cout << symbols[i % h && j % w];
			}
			cout << '\n';
		}
		cout << '\n';
	}
	return 0;
}
