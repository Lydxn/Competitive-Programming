#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

int f[50];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) cin >> f[i];
	sort(f, f + m);

	n--;
	int min_diff = INT_MAX;

	for (int i = 0; i < m - n; i++)
	{
		min_diff = min(min_diff, f[i + n] - f[i]);
	}

	cout << min_diff << '\n';
	return 0;
}
