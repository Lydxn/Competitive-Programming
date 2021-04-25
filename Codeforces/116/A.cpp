#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, a, b;
	cin >> n;

	int maxcap = 0, cur = 0;
	while (n--)
	{
		cin >> a >> b;
		cur = cur - a + b;
		maxcap = max(maxcap, cur);
	}

	cout << maxcap << '\n';
	return 0;
}
