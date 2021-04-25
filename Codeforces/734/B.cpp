#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int k2, k3, k5, k6, max256;
	cin >> k2 >> k3 >> k5 >> k6;

	max256 = min(k2, min(k5, k6));

	cout << 256 * max256 + 32 * min(k2 - max256, k3) << '\n';
	return 0;
}
