#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m, a, b;
	cin >> n >> m >> a >> b;

	cout << (m * a > b ? n / m * b + min(n % m * a, b) : n * a) << '\n';
	return 0;
}
