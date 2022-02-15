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
	int x, y, i;
} n[1000], e[1000];
int nidx, eidx, ans[1000];
bool vis[1000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, x, y; char c;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> c >> x >> y;
		if (c == 'N') n[nidx++] = {x, y, i};
		else e[eidx++] = {x, y, i};
	}
	sort(n, n + nidx, [&] (pt &a, pt &b) { return a.x < b.x; });
	sort(e, e + eidx, [&] (pt &a, pt &b) { return a.y < b.y; });

	for (int i = 0; i < nidx; i++) {
		for (int j = 0; j < eidx; j++) {
			if (vis[n[i].i] || vis[e[j].i] || e[j].x >= n[i].x || n[i].y >= e[j].y) continue;
			if (e[j].y - n[i].y < n[i].x - e[j].x)
				ans[n[i].i] += ans[e[j].i] + 1, vis[e[j].i] = true;
			if (e[j].y - n[i].y > n[i].x - e[j].x)
				ans[e[j].i] += ans[n[i].i] + 1, vis[n[i].i] = true;
		}
	}
	for (int i = 0; i < N; i++) cout << ans[i] << '\n';
	return 0;
}