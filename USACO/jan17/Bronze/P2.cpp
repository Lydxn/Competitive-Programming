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

int cnt[4][4];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("hps.in", "r", stdin);
	freopen("hps.out", "w", stdout);

	int N, x, y;
	cin >> N;
	while (N--) cin >> x >> y, ++cnt[x][y];
	cout << max(cnt[1][2] + cnt[2][3] + cnt[3][1], cnt[1][3] + cnt[3][2] + cnt[2][1]) << '\n';
	return 0;
}
