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

pii p[1001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> p[i].first >> p[i].second;
		sort(p + 1, p + n + 1);
		for (int i = 1; i <= n; i++)
			if (p[i].first < p[i - 1].first || p[i].second < p[i - 1].second)
				{ cout << "NO\n"; goto orz; }
		cout << "YES\n";
		for (int i = 1; i <= n; i++)
			cout << string(p[i].first - p[i - 1].first, 'R') + string(p[i].second - p[i - 1].second, 'U');
		cout << '\n';
		orz:;
	}
	return 0;
}
