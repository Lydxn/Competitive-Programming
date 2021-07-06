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

struct hsh {
	int operator()(ll h) const {
		h ^= h >> 33;
		h *= 0xff51afd7ed558ccdLL;
		h ^= h >> 33;
		h *= 0xc4ceb9fe1a85ec53LL;
		h ^= h >> 33;
		return h;
	}
};

int a[20], b[20];
gp_hash_table<ll, int, hsh> cnt;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, x; ll ans = 0;
	cin >> n >> x;
	int na = n / 2, nb = n - na;
	for (int i = 0; i < na; i++) cin >> a[i];
	for (int i = 0; i < nb; i++) cin >> b[i];
	for (int i = 0; i < 1 << na; i++) {
		ll s = 0;
		for (int j = 0; j < na; j++)
			if (i & (1 << j)) s += a[j];
		++cnt[s];
	}
	for (int i = 0; i < 1 << nb; i++) {
		ll s = 0;
		for (int j = 0; j < nb; j++)
			if (i & (1 << j)) s += b[j];
		ans += cnt[x - s];
	}
	cout << ans << '\n';
	return 0;
}
