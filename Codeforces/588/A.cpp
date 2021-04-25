#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, a, p, money = 0, min_p = INT_MAX;
	cin >> n;

	while (n--)
	{
		cin >> a >> p;
		min_p = min(min_p, p);
		money += a * min_p;
	}

	cout << money << '\n';
	return 0;
}
