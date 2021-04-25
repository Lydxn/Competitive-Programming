#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	long long n, odd;
	while (t--)
	{
		cin >> n;
		odd = 1 << __builtin_popcountll(n);
		cout << n - odd + 1 << ' ' << odd << '\n';
	}
	return 0;
}
