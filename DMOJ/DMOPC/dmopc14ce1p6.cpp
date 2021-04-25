#include <algorithm>
#include <iostream>
#pragma GCC optimize "O3"

typedef long long ll;

using namespace std;

const int MAXD = 3000, MOD = 1000000007;
ll fact[MAXD + 1], inv_fact[MAXD + 1];

ll pow_mod(ll A, ll B)
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

ll binomial(int N, int K)
{
    return fact[N] * inv_fact[K] % MOD * inv_fact[N - K] % MOD;
}

void init_fact()
{
    fact[0] = 1;
    for (int i = 1; i <= MAXD; i++) fact[i] = i * fact[i - 1] % MOD;
    inv_fact[MAXD] = pow_mod(fact[MAXD], MOD - 2);
    for (int i = MAXD - 1; i >= 0; i--) inv_fact[i] = (i + 1) * inv_fact[i + 1] % MOD;
}

long solve(int R, int C)
{
    if (R > C) swap(R, C);

    ll res = 0;
    for (int i = 0; i <= R; i++) {
        if (i & 1) res -= binomial(R, i) * pow_mod(pow_mod(2, R - i) - 1, C);
        else       res += binomial(R, i) * pow_mod(pow_mod(2, R - i) - 1, C);
        res = (res + MOD) % MOD;
    }
    return res;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int T, R, C;
    cin >> T;

    init_fact();
    while (T--)
    {
        cin >> R >> C;
        cout << solve(R, C) << '\n';
    }
    return 0;
}
