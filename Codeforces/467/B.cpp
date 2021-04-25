#include <iostream>

using namespace std;

int x[1001];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m, k, friends = 0, diff;
	cin >> n >> m >> k;

	for (int i = 0; i <= m; i++) cin >> x[i];

	for (int i = 0; i < m; i++)
	{
		diff = 0;
		for (int j = 0; j < n; j++)
		{
			if (((x[i] >> j) & 1) != ((x[m] >> j) & 1)) ++diff;
		}

		if (diff <= k) ++friends;
	}

	cout << friends << '\n';
	return 0;
}
