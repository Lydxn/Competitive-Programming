#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, l, c;
	cin >> t;

	char symbols[] = {'.', '*'};
	while (t--)
	{
		cin >> l >> c;
		for (int i = 0; i < l; i++)
		{
			for (int j = 0; j < c; j++)
			{
				cout << symbols[i == 0 || i == l - 1 || j == 0 || j == c - 1];
			}
			cout << '\n';
		}
		cout << '\n';
	}
	return 0;
}
