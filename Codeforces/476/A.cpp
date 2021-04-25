#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = (n + 1) / 2; i <= n; i++)
	{
		if (i % m == 0)
		{
			cout << i << '\n';
			return 0;
		}
	}

	cout << -1 << '\n';
	return 0;
}
