#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		if (i & 1) cout << string(m, '#') << '\n';
		else if (i & 3) cout << string(m - 1, '.') + '#' << '\n';
		else cout << '#' + string(m - 1, '.') << '\n';
	}
	return 0;
}
