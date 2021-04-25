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

	freopen("circlecross.in", "r", stdin);
	freopen("circlecross.out", "w", stdout);

	string s;
	cin >> s;
	int ans = 0;
	for (char c = 'A'; c <= 'Z'; c++) {
		for (char d = 'A'; d <= 'Z'; d++) {
			if (c == d) continue;
			int cl = INF, cr = -INF, dl = INF, dr = -INF;
			for (int i = 0; i < int(s.size()); i++) {
				if (s[i] == c) cl = min(cl, i), cr = max(cr, i);
				if (s[i] == d) dl = min(dl, i), dr = max(dr, i);
			}
			ans += cl < dl && cr > dl && cr < dr;
		}
	}
	cout << ans << '\n';
	return 0;
}
