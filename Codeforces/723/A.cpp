#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int x[3];
	cin >> x[0] >> x[1] >> x[2];

	sort(x, x + 3);

	cout << x[2] - x[0] << '\n';
	return 0;
}
