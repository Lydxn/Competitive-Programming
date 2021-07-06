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

int cntw[750001], cntrw[750001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T, n; string s;
	cin >> T;
	while (T--) {
		cin >> n >> s;
		for (int i = 1; i <= n; i++) cntw[i] = cntw[i - 1] + (s[i - 1] == 'W');
		for (int i = 1; i <= n; i++) cntrw[i] = (s[i - 1] == 'W') - (s[i - 1] == 'R');
		int mx = cntrw[2], cur = cntrw[2];
		for (int i = 3; i < n; i++) {
			cur = max(cntrw[i], cur + cntrw[i]);
			mx = max(mx, cur);
		}
		cout << cntw[n] - mx << '\n';
	}
	return 0;
}
