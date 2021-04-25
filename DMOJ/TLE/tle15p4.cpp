#include <iostream>

typedef long long ll;

using namespace std;

const ll MOD = 1000000013;

ll pow_mod(ll a, ll b)
{
	ll res = 1;
	while (b)
	{
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	ll N;
	cin >> N;

	if (N == 1) cout << 1 << '\n';
	else
	{
		int mod8 = N & 7;
		cout << (pow_mod(2, N - 2) + pow_mod(2, N / 2 - 1) * (mod8 == 2 || mod8 == 6 ? 0 : mod8 < 3 || mod8 > 5 ? 1 : -1) + MOD) % MOD << '\n';
	}
	return 0;
}
