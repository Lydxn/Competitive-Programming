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

struct node {
	int r, c, h;
	friend bool operator< (const node &a, const node &b) { return a.h > b.h; }
};

int b[100][100];
bool vis[100][100];
priority_queue<node> pq;
pii dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		pq = {}, memset(vis, false, sizeof(vis));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> b[i][j];
				if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
					pq.push({i, j, b[i][j]}), vis[i][j] = true;
			}
		}

		int ans = 0;
		while (!pq.empty()) {
			auto v = pq.top(); pq.pop();
			for (auto d : dir) {
				int nr = v.r + d.first, nc = v.c + d.second;
				if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc]) {
					vis[nr][nc] = true;
					if (b[nr][nc] >= v.h) pq.push({nr, nc, b[nr][nc]});
					else pq.push({nr, nc, v.h}), ans += v.h - b[nr][nc];
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
