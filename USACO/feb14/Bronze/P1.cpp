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

char G[1000][1000];
int N, M, dr[4] = {0, 1, 0, -1}, dc[4] = {1, 0, -1, 0}, b[2][4] = {{1, 0, 3, 2}, {3, 2, 1, 0}};

int f(int r, int c, int d) {
	int cnt = 0;
	while (r >= 0 && r < N && c >= 0 && c < M)
		d = b[G[r][c] == '/'][d], r += dr[d], c += dc[d], ++cnt;
	return cnt;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("mirror.in", "r", stdin);
	freopen("mirror.out", "w", stdout);

	int mx = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> G[i][j];
	for (int i = 0; i < N; i++) mx = max(mx, max(f(i, 0, 0), f(i, M - 1, 2)));
	for (int i = 0; i < M; i++) mx = max(mx, max(f(0, i, 1), f(N - 1, i, 3)));
	cout << mx << '\n';
	return 0;
}
