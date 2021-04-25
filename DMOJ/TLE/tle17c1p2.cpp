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

unordered_map<string, int> f;
pair<int, string> x[1000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int F, N, e; string s;
	cin >> F;
	while (F--) cin >> s >> e, f[s] = e;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> x[i].second >> x[i].first;
	sort(x, x + N);
	int ans = 0, g = 0, p = 0;
	for (int i = 0; i < N; i++) {
		g -= x[i].first - p;
		if (g < 0 && x[i].first != p) break;
		++ans, g += f[x[i].second], p = x[i].first;
	}
	cout << ans << '\n';
	return 0;
}
