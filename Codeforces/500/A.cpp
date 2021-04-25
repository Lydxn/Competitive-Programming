#include <iostream>

using namespace std;

int a[30001];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	cin >> n >> t;

	for (int i = 1; i < n; i++) cin >> a[i];

	bool visit = false;
	for (int i = 1; i <= t && !(visit = i == t); i += a[i]);

	cout << (visit ? "YES" : "NO") << '\n';
	return 0;
}
