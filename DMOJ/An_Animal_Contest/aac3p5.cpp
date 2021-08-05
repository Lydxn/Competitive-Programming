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
	int r, c, sz;
	bool operator< (const node &n) const { return sz < n.sz; }
};

bool g[2000][2000];
int N, M, l[2000][2000], r[2000][2000], u[2000][2000], d[2000][2000], sz[2000][2000];
priority_queue<node> pq;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	char c;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> c, g[i][j] = c == '#';
	for (int i = 0; i < N; i++) {
		l[i][M - 1] = r[i][0] = -1;
		for (int j = M - 2; j >= 0; j--)
			l[i][j] = g[i][j + 1] ? j + 1 : l[i][j + 1];
		for (int j = 1; j < M; j++)
			r[i][j] = g[i][j - 1] ? j - 1 : r[i][j - 1];
	}
	for (int i = 0; i < M; i++) {
		d[i][N - 1] = u[i][0] = -1;
		for (int j = N - 2; j >= 0; j--)
			d[i][j] = g[j + 1][i] ? j + 1 : d[i][j + 1];
		for (int j = 1; j < N; j++)
			u[i][j] = g[j - 1][i] ? j - 1 : u[i][j - 1];
	}

	memset(sz, -1, sizeof(sz));
	for (int i = 0; i < M; i++)
		if (g[0][i]) pq.push({0, i, sz[0][i] = INF});
	while (!pq.empty()) {
		int cr = pq.top().r, cc = pq.top().c, csz = pq.top().sz; pq.pop();
		if (csz < sz[cr][cc]) continue;
		int lidx = l[cr][cc], ridx = r[cr][cc], didx = d[cc][cr], uidx = u[cc][cr];
		int lv = lidx - cc == 1 ? csz : min(csz, lidx - cc - 1);
		if (lidx != -1 && lidx < M && lv > sz[cr][lidx])
			pq.push({cr, lidx, sz[cr][lidx] = lv});
		int rv = cc - ridx == 1 ? csz : min(csz, cc - ridx - 1);
		if (ridx != -1 && ridx >= 0 && rv > sz[cr][ridx])
			pq.push({cr, ridx, sz[cr][ridx] = rv});
		int dv = didx - cr == 1 ? csz : min(csz, didx - cr - 1);
		if (didx != -1 && didx < N && dv > sz[didx][cc])
			pq.push({didx, cc, sz[didx][cc] = dv});
		int uv = cr - uidx == 1 ? csz : min(csz, cr - uidx - 1);
		if (uidx != -1 && uidx >= 0 && uv > sz[uidx][cc])
			pq.push({uidx, cc, sz[uidx][cc] = uv});
	}
	for (int i = 0; i < M; i++)
		cout << (sz[N - 1][i] == INF ? 0 : sz[N - 1][i]) << " \n"[i == M - 1];
	return 0;
}