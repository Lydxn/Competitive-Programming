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
const int MOD = 1e9 + 7;

template <class T, class C = less<T>>
using ordered_set = tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;

ll pw[1000001], hs[1000001], ht[1000001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	string s, t;
	cin >> s >> t;
	int n = s.size(), m = t.size(), ans = 0;
	if (m > n) { cout << "0\n"; return 0; }
	pw[0] = 1;
	for (int i = 1; i <= n; i++) pw[i] = pw[i - 1] * 31 % MOD;
	for (int i = 1; i <= n; i++) hs[i] = (hs[i - 1] * 31 + s[i - 1]) % MOD;
	for (int i = 1; i <= m; i++) ht[i] = (ht[i - 1] * 31 + t[i - 1]) % MOD;
	for (int i = m; i <= n; i++) ans += (hs[i] - hs[i - m] * pw[m] % MOD + MOD) % MOD == ht[m];
	cout << ans << '\n';
	return 0;
}
