#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> plli;
typedef pair<int, ll> pill;
typedef pair<pair<int, int>, int> piii;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 998244353;

template <class T, class C = less<T>>
using ordered_set = tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, K; string S; ll ww = 0, aa = 0, cc = 0, a[4];
	cin >> N >> K >> S;
	for (int i = 0; i < N * 4; i++) {
		char c = S[i % N];
		if (c == 'W') ++ww;
		else if (c == 'A') aa = (aa + ww) % MOD;
		else if (c == 'C') cc = (cc + aa) % MOD;
		if (i % N == N - 1) a[i / N] = cc;
	}

	ll idk = ((((a[3] - a[2]) - (a[2] - a[1])) - ((a[2] - a[1]) - (a[1] - a[0]))) % MOD + MOD) % MOD;
	ll p = a[0], q = ((a[1] - a[0]) % MOD + MOD) % MOD, r = (((a[2] - a[1]) - (a[1] - a[0])) % MOD + MOD) % MOD;
	while (--K) p = (p + q) % MOD, q = (q + r) % MOD, r = (r + idk) % MOD;
	cout << p << '\n';
	return 0;
}

/*
193 10
ACACAACAAACAAAACAAWAAAACAAWACAAWWCWAWACAACCAAAAAAAWACCACAAAACCACAACWCACCAAAACACWCAAAAAAAACCAWACAACCCAWAWAAACACWCACACWAACWAAACAAAAWCCACAACACAACCAAACACCCAAAAAWWWCAAAACACCCAWACAAACAAAWWAAAAACAACWA
24507765
*/
