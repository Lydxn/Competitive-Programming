#include <cmath>
#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	double n, m, a;
	cin >> n >> m >> a;

	cout << (long long) ceil(n / a) * (long long) ceil(m / a) << '\n';
	return 0;
}
