// WIP

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

ll diff[502][502]; int C, R;
pill dist[502][502];
pii dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
queue<pii> q;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int M, x, y, w, h, n, c, r;
	cin >> C >> R >> M;
	while (M--) {
		cin >> x >> y >> w >> h >> n;
		diff[y][x] += n;
		diff[y][x + w] -= (w + 1) * n;
		diff[y + h][x] -= (h + 1) * n;
		diff[y + h][x + w] += (w + 1) * (h + 1) * n;
		diff[y][x + w + 1] += w * n;
		diff[y + h + 1][x] += h * n;
		diff[y + h][x + w + 1] -= w * (h + 1) * n;
		diff[y + h + 1][x + w] -= (w + 1) * h * n;
		diff[y + h + 1][x + w + 1] += w * h * n;
	}

	for (int j = 1; j <= R + 1; j++)
		for (int k = 1; k <= C + 1; k++)
			diff[j][k] += diff[j - 1][k] + diff[j][k - 1] - diff[j - 1][k - 1];
	for (int j = 1; j <= R + 1; j++)
		for (int k = 1; k <= C + 1; k++)
			diff[j][k] += diff[j - 1][k] + diff[j][k - 1] - diff[j - 1][k - 1];

	for (int i = 0; i <= R + 1; i++) {
		for (int j = 0; j <= C + 1; j++)
			cout << diff[i][j] << ' ';
		cout << '\n';
	}

	cin >> c >> r;
	q.emplace(r, c), dist[r][c].second = diff[r][c];

	pill ans = {0, 0};
	while (!q.empty()) {
		int cr = q.front().first, cc = q.front().second; q.pop();
		ans = max(ans, dist[cr][cc]);
		for (auto d : dir) {
			int nr = cr + d.first, nc = cc + d.second;
			pill nd = {dist[cr][cc].first + 1, dist[cr][cc].second + diff[nr][nc]};
			if (diff[nr][nc] > diff[cr][cc] && nd > dist[nr][nc])
				dist[nr][nc] = nd, q.emplace(nr, nc);
		}
	}
	cout << ans.second % MOD << '\n';
	return 0;
}
