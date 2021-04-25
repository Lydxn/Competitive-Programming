#include <algorithm>
#include <iostream>

typedef long long ll;

using namespace std;

const int MOD = 1000000007, MAXF = 1000;
ll fact[MAXF + 1];

void init_fact()
{
	fact[0] = 1;
	for (int i = 1; i <= MAXF; i++)
	{
		fact[i] = i * fact[i - 1] % MOD;
	}
}

ll powmod(ll A, ll B)
{
	ll res = 1;
	while (B)
	{
		if (B & 1) res = res * A % MOD;
		B >>= 1;
		A = A * A % MOD;
	}
	return res;
}

int binomial(int N, int K)
{
	return fact[N] * powmod(fact[K], MOD - 2) % MOD * powmod(fact[N - K], MOD - 2) % MOD;
}

int main()
{
	init_fact();
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T, N, M;
	cin >> T;

	while (T--)
	{
		cin >> N >> M;
		cout << binomial(N + M, N) << '\n';
	}
	return 0;
}
