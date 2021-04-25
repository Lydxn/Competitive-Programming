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
		cin >> s;
		int l = -1, r = -1, ql = INF, qr = -1, cnt = 0;
		for (int i = 0; i < int(s.size()); i++) {
			cnt += s[i] == '?';
			if (s[i] == '?') ql = min(ql, i), qr = i;
			if (s[i] == '(') l = i;
			if (s[i] == ')') r = i;
		}
		cout << ((l < r || (ql < r && qr > l)) && cnt % 2 == 0 ? "YES" : "NO") << '\n';
	}
	return 0;
}
