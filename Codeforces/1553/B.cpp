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

	int q; string s, t;
	cin >> q;
	while (q--) {
		cin >> s >> t;
		int ss = s.size(), st = t.size();
		for (int i = 0; i < ss; i++) {
			for (int l = 0; l < ss - i; l++) {
				int left = st - l;
				if (i + l - left + 1 < 0 || st - l < 0) continue;
				string p1 = s.substr(i, l), p2 = s.substr(i + l - left + 1, st - l);
				reverse(p2.begin(), p2.end());
				if (p1 + p2 == t) { cout << "YES\n"; goto done; }
			}
		}
		cout << "NO\n"; done:;
	}
	return 0;
}
