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

pii B[200];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("blist.in", "r", stdin);
	freopen("blist.out", "w", stdout);

	int N, s, t, b;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s >> t >> b;
		B[i << 1] = {s, b}, B[i << 1 | 1] = {t + 1, -b};
	}
	sort(B, B + (N << 1));
	int ans = 0, cur = 0;
	for (int i = 0; i < N << 1; i++) {
		cur += B[i].second;
		ans = max(ans, cur);
	}
	cout << ans << '\n';
	return 0;
}
