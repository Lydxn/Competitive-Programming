#include <iostream>

using namespace std;

bool is_prime(int n)
{
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

	for (int i = 2; i <= n / 2; i++)
	{
		if (!is_prime(i) && !is_prime(n - i))
		{
			cout << i << ' ' << n - i << '\n';
			return 0;
		}
	}
}
