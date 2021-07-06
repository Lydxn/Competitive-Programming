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
	int x, y, z;
};

int dst[101][101][101], ans[101][101][101];
queue<pt> Q;
pt dirs[6] = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, q, x, y, z;
	cin >> n >> q;
	memset(dst, INF, sizeof(dst));
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> z;
		ans[x][y][z] = i + 1, dst[x][y][z] = 0, Q.push({x, y, z});
	}

	while (!Q.empty()) {
		pt c = Q.front(); Q.pop();
		for (auto d : dirs) {
			int nx = c.x + d.x, ny = c.y + d.y, nz = c.z + d.z;
			if (nx >= 0 && nx <= 100 && ny >= 0 && ny <= 100 && nz >= 0 && nz <= 100 && dst[nx][ny][nz] == INF)
				ans[nx][ny][nz] = ans[c.x][c.y][c.z], dst[nx][ny][nz] = dst[c.x][c.y][c.z] + 1, Q.push({nx, ny, nz});
		}
	}

	while (q--) {
		cin >> x >> y >> z;
		cout << ans[x][y][z] << '\n';
	}
	return 0;
}
