#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int a, b;
	cin >> a >> b;

	if (a > b) swap(a, b);

	cout << a << ' ' << (b - a) / 2 << '\n';
	return 0;
}
