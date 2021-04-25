#include <algorithm>
#include <iomanip>
#include <iostream>

using namespace std;

int a[1000];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, l, max_dist;
	cin >> n >> l;

	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);

	max_dist = max(a[0], l - a[n - 1]) * 2;
	for (int i = 1; i < n; i++)
	{
		max_dist = max(max_dist, a[i] - a[i - 1]);
	}

	cout << setprecision(9) << max_dist / 2.0 << '\n';
	return 0;
}
