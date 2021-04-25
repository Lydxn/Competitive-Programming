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

map<int, int> cnt;
int x[200000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, k; ll ans = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> x[i];
	for (int l = 0, r = 0, s = 0; l < n; l++) {
		while (r < n && s + !cnt[x[r]] <= k) s += !cnt[x[r++]]++;
		ans += r - l, s -= !--cnt[x[l]];
	}
	cout << ans << '\n';
	return 0;
}
