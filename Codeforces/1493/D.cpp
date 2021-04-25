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

int n, spf[200001]; ll ans = 1;
unordered_map<int, int> cnt[200001], t[200001];

void upd(int idx, int x) {
	while (x != 1) {
		int f = spf[x];
		if (++t[f][++cnt[idx][f]] == n) ans = ans * f % MOD;
		x /= f;
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	for (int i = 1; i <= 200000; i++) spf[i] = i;
	for (int i = 2; i * i <= 200000; i++)
		if (spf[i] == i)
			for (int j = i * i; j <= 200000; j += i)
				if (spf[j] == j) spf[j] = i;
	
	int q, x, y;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> x, upd(i, x);
	while (q--) cin >> x >> y, upd(x, y), cout << ans << '\n';
	return 0;
}
