#include <iostream>

using namespace std;

typedef long long ll;

const int MOD = 1000000007, MAXF = 1000000;
ll fact[MAXF + 1];

void init_fact()
{
	fact[0] = 1;
	for (int i = 1; i <= MAXF; i++)
	{
		fact[i] = fact[i - 1] * i % MOD;
	}
}

ll powmod(ll A, ll B)
{
	ll res = 1;
	while (B)
	{
		if (B & 1) res = (res * A) % MOD;
		A = (A * A) % MOD;
		B >>= 1;
	}
	return res;
}

ll modinv(ll N)
{
	return powmod(N, MOD - 2);
}

ll binomial(ll N, ll K)
{
	return fact[N] * modinv(fact[K]) % MOD * modinv(fact[N - K]) % MOD;
}

int main()
{
	init_fact();
	cin.sync_with_stdio(0);
	cin.tie(0);

	ll N, A, B, D;
	while (cin >> N >> A >> B >> D)
	{
		cout << binomial(N, A) * powmod(binomial(B, D), A) % MOD << '\n';
	}
	return 0;
}
