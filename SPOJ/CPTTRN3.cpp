#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, l, c;
	cin >> t;

	char symbols[] = { '*', '.' };
	while (t--)
	{
		cin >> l >> c;
		for (int i = 0; i < 3 * l + 1; i++)
		{
			for (int j = 0; j < 3 * c + 1; j++)
			{
				cout << symbols[i % 3 && j % 3];
			}
			cout << '\n';
		}
		cout << '\n';
	}
	return 0;
}
