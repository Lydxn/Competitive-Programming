#include <iostream>

#define ifc(n) is_prime[n >> 6] &  (1 << ((n >> 1) & 31))
#define isc(n) is_prime[n >> 6] |= (1 << ((n >> 1) & 31))

using namespace std;

const int MAXN = 10000000;
int is_prime[MAXN >> 6], primes[MAXN + 1];

void init() 
{
	for (int i = 3; i * i <= MAXN; i += 2)
	{
		if (!(ifc(i)))
		{
			for (int j = i * i, k = i << 1; j <= MAXN; j += k) isc(j);
		}
	}

	primes[2] = 1;
	for (int i = 3; i <= MAXN; i++)
	{
		if (!(ifc(i)) && i & 1) primes[i] += primes[i - 1] + 1;
		else				    primes[i] =  primes[i - 1];
	}
}

int main()
{
	init();
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T, n;
	cin >> T;

	while (T--)
	{
		cin >> n;
		cout << primes[n] - primes[n >> 1] << '\n';
	}
	return 0;
}
