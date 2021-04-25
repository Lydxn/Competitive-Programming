#include <algorithm>
#include <iostream>

using namespace std;

int x[100000];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, q, m;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> x[i];
	sort(x, x + n);

	cin >> q;
	while (q--)
	{
		cin >> m;
		cout << upper_bound(x, x + n, m) - x << '\n';
	}
	return 0;
}
