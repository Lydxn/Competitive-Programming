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
	int r, c, w;
	bool operator< (const node &n) const { return w > n.w; }
};

int g[80][80], dist[80][80];
priority_queue<node> pq;
pii dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("p083_matrix.txt", "r", stdin);

	for (int i = 0; i < 80; i++) {
		string s, cur; int j = 0;
		cin >> s; s += ',';
		for (char c : s) {
			if (c == ',') g[i][j++] = stoi(cur), cur = "";
			else cur += c;
		}
	}

	memset(dist, INF, sizeof(dist));
	pq.push({0, 0, dist[0][0] = g[0][0]});
	while (!pq.empty()) {
		node n = pq.top(); pq.pop();
		if (dist[n.r][n.c] < n.w) continue;
		for (pii d : dir) {
			int nr = n.r + d.first, nc = n.c + d.second;
			if (nr >= 0 && nr < 80 && nc >= 0 && nc < 80 && n.w + g[nr][nc] < dist[nr][nc])
				pq.push({nr, nc, dist[nr][nc] = n.w + g[nr][nc]});
		}
	}
	cout << dist[79][79] << '\n';
	return 0;
}
