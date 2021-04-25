#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int d1, d2, d3;
	cin >> d1 >> d2 >> d3;

	cout << min(min(d1 + d2 + d3, 2 * d1 + 2 * d2),
				min(2 * d2 + 2 * d3, 2 * d1 + 2 * d3)) << '\n';
	return 0;
}
