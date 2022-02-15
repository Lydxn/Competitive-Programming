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

struct pos {
	int r, c, w;
	bool operator< (const pos &p) const { return w > p.w; }
};

char g[1000][1000];
int dst[1000][1000];
pii dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
priority_queue<pos> pq;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> g[i][j];
	memset(dst, INF, sizeof(dst));
	dst[0][0] = g[0][0] == 'C';
	pq.push({0, 0, dst[0][0]});
	while (!pq.empty()) {
		auto p = pq.top(); pq.pop();
		if (p.w > dst[p.r][p.c]) continue;
		for (auto [r, c] : dir) {
			int nr = p.r + r, nc = p.c + c, nw = p.w + (g[nr][nc] == 'C');
			if (nr >= 0 && nr < N && nc >= 0 && nc < M && nw < dst[nr][nc])
				dst[nr][nc] = nw, pq.push({nr, nc, nw});
		}
	}
	cout << dst[N - 1][M - 1] << '\n';
	return 0;
}
