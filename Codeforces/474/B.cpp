#include <algorithm>
#include <iostream>

using namespace std;

int prefix[100001];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, a, m, q;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		prefix[i + 1] = prefix[i] + a;
	}

	cin >> m;
	while (m--)
	{
		cin >> q;
		cout << lower_bound(prefix, prefix + n, q) - prefix << '\n';
	}
	return 0;
}
