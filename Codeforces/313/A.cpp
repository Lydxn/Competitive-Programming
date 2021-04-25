#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	cout << (n < 0 ? max(n / 10, n / 100 * 10 + n % 10) : n) << '\n';
	return 0;
}
