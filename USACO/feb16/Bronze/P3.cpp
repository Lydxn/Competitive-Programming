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

int x[100], y[100], cnt[2][2];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("balancing.in", "r", stdin);
	freopen("balancing.out", "w", stdout);

	int N, B, ans = INF;
	cin >> N >> B;
	for (int i = 0; i < N; i++) cin >> x[i] >> y[i];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int xw = x[i] + 1, yw = y[j] + 1;
			memset(cnt, 0, sizeof(cnt));
			for (int k = 0; k < N; k++) ++cnt[x[k] > xw][y[k] > yw];
			ans = min(ans, max(max(cnt[0][0], cnt[0][1]), max(cnt[1][0], cnt[1][1])));
		}
	}
	cout << ans << '\n';
	return 0;
}
