#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, k, y;
	cin >> n >> k;

	int teams = 0;
	while (n--)
	{
		cin >> y;
		teams += y + k <= 5;
	}

	cout << teams / 3 << '\n';
	return 0;
}
