#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, groups = 0, magnet, prev = -1;
	cin >> n;

	while (n--)
	{
		cin >> magnet;
		if (prev != magnet)
		{
			groups++;
			prev = magnet;
		}
	}

	cout << groups << '\n';
	return 0;
}
