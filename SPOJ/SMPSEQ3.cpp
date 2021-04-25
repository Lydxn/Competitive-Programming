#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

int s[100], q[100];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m;

	cin >> n;
	for (int i = 0; i < n; i++) cin >> s[i];

	cin >> m;
	for (int i = 0; i < m; i++) cin >> q[i];

	set<int> res;
	for (int i = 0; i < n; i++)
	{
		if (!binary_search(q, q + m, s[i])) res.insert(s[i]);
	}

	for (int r : res) cout << r << ' ';
	return 0;
}
