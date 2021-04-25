#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, p, q;
	cin >> n;

	int rooms = 0;
	while (n--)
	{
		cin >> p >> q;
		if (p + 2 <= q) rooms++;
	}

	cout << rooms << '\n';
	return 0;
}
