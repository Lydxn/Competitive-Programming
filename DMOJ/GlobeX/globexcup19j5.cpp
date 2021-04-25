#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

#define _hash(a, b) a | b << 32

template <const int MAXN, typename T, const T MOD, const T MODM1, const int OFFSET>
struct Hashing
{
    inline T add_mod(T a, T b) { T res = a + b; return res < MOD ? res : res - MOD; }
    inline T sub_mod(T a, T b) { T res = a - b; return res >= 0 ? res : res + MOD; }
    inline T mul_mod(T a, T b) { return (a * b) & MODM1; }

	T pre[MAXN + 1], hsh[MAXN + 1];
	const T SEED = 987654321; // change this value if needed (must be smaller than MOD)

	void init(const auto& s, const int N)
	{
		pre[0] = 1, hsh[N] = 0;
		for (int i = 1; i <= N; i++) pre[i] = mul_mod(pre[i - 1], SEED);
		for (int i = N - 1; i >= 0; i--) hsh[i] = add_mod(mul_mod(hsh[i + 1], SEED), s[i] - OFFSET + 1);
	}

	T get_hash(int l, int r) { return sub_mod(hsh[l], mul_mod(hsh[r], pre[r - l])); }
};


const int MAXN = 1000, MOD = 1 << 30, MODM1 = MOD - 1;
Hashing<MAXN, ll, MOD, MODM1, 'a'> hashing;
gp_hash_table<ll, null_type> hashes;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	string a, b;
	cin >> a >> b;

	int alen = a.size(), blen = b.size();

	hashing.init(a, alen);
	for (int i = 0; i < alen; i++)
	{
		for (int j = i + 1; j <= alen; j++)
		{
			ll temp1 = hashing.get_hash(i, j);
			ll temp2 = (hashing.get_hash(0, i) + ((hashing.get_hash(j, alen) * hashing.pre[i]) & MODM1)) & MODM1;

			hashes.insert(_hash(temp1, temp2));
		}
	}
	
	hashing.init(b, blen);
	for (int i = 0; i < blen; i++)
	{
		for (int j = i + 1; j <= blen; j++)
		{
			ll temp1 = hashing.get_hash(i, j);
			ll temp2 = (hashing.get_hash(0, i) + ((hashing.get_hash(j, alen) * hashing.pre[i]) & MODM1)) & MODM1;

			if (hashes.find(_hash(temp1, temp2)) != hashes.end())
			{
				cout << "aliens\n";
				return 0;
			}
		}
	}

	cout << "no aliens\n";
	return 0;
}
