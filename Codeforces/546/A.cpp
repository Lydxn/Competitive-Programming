#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int k, n, w;
	cin >> k >> n >> w;

	cout << max(k * w * (w + 1) / 2 - n, 0) << '\n';
	return 0;
}
