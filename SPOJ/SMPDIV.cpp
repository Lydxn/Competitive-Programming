#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n, x, y;
	cin >> t;

	while (t--)
	{
		cin >> n >> x >> y;
		for (int a = 2; a < n; a++)
		{
			if (a % x == 0 && a % y) cout << a << ' ';
		}
		cout << '\n';
	}
	return 0;
}
