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

int cnt[200002], cidx;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n, k; string s;
	cin >> t;
	while (t--) {
		cin >> n >> k >> s;
		cidx = 0; s += '1'; memset(cnt, 0, (n + 2) * 4);
		for (char c : s) {
			if (c == '0') ++cnt[cidx];
			else ++cidx;
		}

		if (cidx == 1) { cout << (n - 1) / (k + 1) + 1 << '\n'; continue; }

		int ans = 0;
		for (int i = 0; i < cidx; i++) {
			if (i == 0 || i == cidx - 1) ans += cnt[i] / (k + 1);
			else ans += (cnt[i] - k) / (k + 1);
		}
		cout << ans << '\n';
	}
	return 0;
}
