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

int x1[3000], _y1[3000], x2[3000], y2[3000], x3[3000], y3[3000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, Q, x, y;
	cin >> N >> Q;
	for (int i = 0; i < N; i++) cin >> x1[i] >> _y1[i] >> x2[i] >> y2[i] >> x3[i] >> y3[i];
	while (Q--) {
		cin >> x >> y; int cnt = 0;
		for (int i = 0; i < N; i++) {
			int nx = x3[i] - x1[i], ny = y2[i] - _y1[i];
			int cx = x - x1[i], cy = y - _y1[i];
			if (nx < 0) nx = -nx, cx = -cx;
			if (ny < 0) ny = -ny, cy = -cy;
			cnt += cx >= 0 && cy >= 0 && 1LL * cy * nx <= 1LL * ny * (nx - cx);
		}
		cout << cnt << '\n';
	}
	return 0;
}
