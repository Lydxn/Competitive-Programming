#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, x, y, z, xs = 0, ys = 0, zs = 0;
	cin >> n;

	while (n--)
	{
		cin >> x >> y >> z;
		xs += x, ys += y, zs += z;
	}

	cout << (xs == 0 && ys == 0 && zs == 0 ? "YES" : "NO") << '\n';
	return 0;
}
