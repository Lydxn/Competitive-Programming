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

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t; string s;
	cin >> t;
	while (t--) {
		cin >> s; int ans = INF;
		for (int i = 0; i < 1 << 10; i++) {
			int p1 = 0, p2 = 0, cur = 9;
			for (int j = 0; j < 10; j++) {
				int v = s[j] == '?' ? ((i >> j) & 1) : s[j] - '0';
				if (j % 2 == 0) p1 += v;
				else p2 += v;
				if (p1 > p2 + (10 - j) / 2) { cur = j; break; }
				if (p2 > p1 + (9 - j) / 2) { cur = j; break; }
			}
			ans = min(ans, cur);
		}
		cout << ans + 1 << '\n';
	}
	return 0;
}
