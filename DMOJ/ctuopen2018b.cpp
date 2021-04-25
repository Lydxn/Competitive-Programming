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

int dist[5001][5001];
queue<pii> q;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, Q, X, Y;
	cin >> N >> Q;
	memset(dist, -1, sizeof(dist));
	for (int i = 0; i < N; i++) cin >> X >> Y, dist[X][Y] = 0, q.emplace(X, Y);
	while (!q.empty()) {
		int cx = q.front().first, cy = q.front().second; q.pop();
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				int nx = cx + i, ny = cy + j;
				if (nx >= 0 && nx <= 5000 && ny >= 0 && ny <= 5000 && dist[nx][ny] == -1)
					q.emplace(nx, ny), dist[nx][ny] = dist[cx][cy] + 1;
			}
		}
	}

	while (Q--) {
		cin >> X >> Y;
		cout << dist[X][Y] << '\n';
	}
	return 0;
}
