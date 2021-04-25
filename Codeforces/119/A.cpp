#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int a, b, n;
	cin >> a >> b >> n;

	while (n)
	{
		n -= gcd(a, n);
		if (n <= 0)
		{
			putchar('0');
			return 0;
		}

		n -= gcd(b, n);
		if (n <= 0)
		{
			putchar('1');
			return 0;
		}
	}
}
