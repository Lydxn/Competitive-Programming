#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	cin >> n >> t;

	if (n == 1 && t == 10) cout << -1 << '\n';
	else
	{
		cout << t << string((t != 10) + n - 2, '0');
	}
	return 0;
}
