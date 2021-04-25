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

int n[100001], dist[100001][81];
queue<pii> q;

void push(int r, int c, int nr, int nc) {
	if (dist[nr][nc] == -1)
		dist[nr][nc] = dist[r][c] + 1, q.emplace(nr, nc);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, rs, cs, rf, cf;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> n[i];
	cin >> rs >> cs >> rf >> cf;

	memset(dist, -1, sizeof(dist));
	dist[rs][cs] = 0, q.emplace(rs, cs);
	while (!q.empty()) {
		int cr = q.front().first, cc = q.front().second; q.pop();
		if (cc != n[cr]) push(cr, cc, cr, cc + 1);
		else if (cr != N) push(cr, cc, cr + 1, 1);
		if (cc != 1) push(cr, cc, cr, cc - 1);
		else if (cr != 1) push(cr, cc, cr - 1, n[cr - 1]);
		if (cr != 1) push(cr, cc, cr - 1, min(n[cr - 1], cc));
		if (cr != N) push(cr, cc, cr + 1, min(n[cr + 1], cc));
	}
	cout << dist[rf][cf] << '\n';
	return 0;
}
