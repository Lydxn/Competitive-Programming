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

int a[12], p[12], cnt[4], s[4], ans = INF;

void solve(int idx) {
	if (idx == 12) {
		s[0] = s[1] = s[2] = s[3] = 0;
		for (int i = 0; i < 12; i++) s[p[i]] += a[i];
		ans = min(ans, max(max(s[0], s[1]), max(s[2], s[3])) - min(min(s[0], s[1]), min(s[2], s[3])));
	} else {
		for (int i = 0; i < 4; i++) {
			if (cnt[i] >= 3) continue;
			p[idx] = i;
			++cnt[i], solve(idx + 1), --cnt[i];
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("bteams.in", "r", stdin);
	freopen("bteams.out", "w", stdout);

	for (int i = 0; i < 12; i++) cin >> a[i];
	solve(0);
	cout << ans << '\n';
	return 0;
}
