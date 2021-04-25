#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int SIEVE_SZ = 1000;
bool is_prime[SIEVE_SZ + 1];
vector<int> sieve;

void init_sieve()
{
	memset(is_prime, true, sizeof(is_prime));
	for (int i = 2; i * i <= SIEVE_SZ; i++)
	{
		if (is_prime[i])
		{
			for (int j = i * i; j <= SIEVE_SZ; j += i)
			{
				is_prime[j] = false;
			}
		}
	}

	for (int i = 2; i <= SIEVE_SZ; i++) sieve.push_back(i);
}

int divisors(int N)
{
	int res = 1, rem = N, exp;
	for (int s : sieve)
	{
		if (s * s > N) return res * 2;

		exp = 1;
		while (rem % s == 0)
		{
			exp++;
			rem /= s;
		}
		res *= exp;

		if (rem == 1) return res;
	}
	return res;
}

int tri_div(int N)
{
	int res = 1, i = 2;
	do
	{
		res += i++;
	} while (divisors(res) <= N);
	return res;
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
		cout << tri_div(N) << '\n';
	}
	return 0;
}
