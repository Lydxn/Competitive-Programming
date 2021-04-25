#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, k, i, mins = 0;
	cin >> n >> k;

	k = 240 - k;
	for (i = 1; i <= n && mins <= k; i++)
	{
		mins += i * 5;
		if (mins > k) break;
	}

	cout << i - 1 << '\n';
	return 0;
}
