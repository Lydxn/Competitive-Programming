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

const int MAXN = 3001;
int BIT[MAXN][MAXN], grid[MAXN][MAXN], M, N;

void update(int R, int C, int X) {
	for (int r = R; r <= M; r += r & -r)
		for (int c = C; c <= N; c += c & -c)
			BIT[r][c] += X;
}

int query(int R, int C) {
	int res = 0;
	for (int r = R; r; r -= r & -r)
		for (int c = C; c; c -= c & -c)
			res += BIT[r][c];
	return res;
}

int query(int R, int C, int R2, int C2) {
	return query(R2, C2) - query(R - 1, C2) - query(R2, C - 1) + query(R - 1, C - 1);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int R, C, X, R2, C2, op;
	cin >> M >> N;
	while (cin >> op) {
		if (op == 0) break;
		else if (op == 1) {
			cin >> R >> C >> X;
			int V = (R + C) & 1 ? X : -X;
			update(R, C, V - grid[R][C]);
			grid[R][C] = V;
		} else {
			cin >> R >> C >> R2 >> C2;
			cout << query(R, C, R2, C2) * ((R + C) & 1 ? 1 : -1) << '\n';
		}
	}
	return 0;
}
