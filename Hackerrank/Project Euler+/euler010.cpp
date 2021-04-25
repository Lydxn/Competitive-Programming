#include <cstring>
#include <iostream>

using namespace std;

const int MAXN = 1000000;
bool is_prime[MAXN + 1];
long long sums[MAXN + 1];

void init_sieve()
{
	memset(is_prime, true, sizeof(is_prime));
	for (int i = 2; i * i <= MAXN; i++)
	{
		if (is_prime[i])
		{
			for (int j = i * i; j <= MAXN; j += i)
			{
				is_prime[j] = false;
			}
		}
	}

	long long sum = 0;
	for (int i = 2; i <= MAXN; i++)
	{
		if (is_prime[i]) sum += i;
		sums[i] = sum;
	}
}

int main()
{
	init_sieve();
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T, N;
	cin >> T;

	while (T--)
	{
		cin >> N;
		cout << sums[N] << '\n';
	}
	return 0;
}
