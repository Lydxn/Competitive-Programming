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

struct pt {
	int x, y;
} p[2500];
int psa[2501][2501];

int query(int x1, int x2, int y1, int y2) {
	return psa[x2][y2] - psa[x1 - 1][y2] - psa[x2][y1 - 1] + psa[x1 - 1][y1 - 1];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; ll ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> p[i].x >> p[i].y;
	sort(p, p + N, [&] (pt &a, pt &b) { return a.x < b.x; });
	for (int i = 0; i < N; i++) p[i].x = i + 1;
	sort(p, p + N, [&] (pt &a, pt &b) { return a.y < b.y; });
	for (int i = 0; i < N; i++) p[i].y = i + 1;
	for (int i = 0; i < N; i++) ++psa[p[i].x][p[i].y];
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			psa[i][j] += psa[i][j - 1] + psa[i - 1][j] - psa[i - 1][j - 1];
			
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			int l = p[i].x, r = p[j].x;
			if (l > r) swap(l, r);
			ans += query(1, l, p[i].y, p[j].y) * query(r, N, p[i].y, p[j].y);
 		}
	}
	cout << ans + N + 1 << '\n';
	return 0;
}
