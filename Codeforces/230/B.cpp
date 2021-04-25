#include <cmath>
#include <iostream>

using namespace std;

bool is_prime(int n)
{
	if (n <= 1) return false;
	if (n <= 3) return true;
	if ((n & 1) == 0 || n % 3 == 0) return false;

	for (int i = 5; i * i <= n; i += 6)
	{
		if (n % i == 0 || n % (i + 2) == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	long long x;
	double sq;

	while (n--)
	{
		cin >> x;
		sq = sqrt(x);

		cout << (sq == floor(sq) && is_prime(sq) ? "YES" : "NO") << '\n';
	}
	return 0;
}
