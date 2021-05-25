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

int N, g[101][101], tmp[101][101];

void rotr(int r1, int c1, int r2, int c2) {
	memcpy(tmp, g, sizeof(tmp));
	for (int i = r1; i <= r2; i++)
		for (int j = c1; j <= c2; j++)
			tmp[r1 + j - c1][c1 + r2 - i] = g[i][j];
	memcpy(g, tmp, sizeof(g));
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int Q, r1, c1, r2, c2, x;
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> g[i][j];
	cin >> Q;
	while (Q--) {
		cin >> r1 >> c1 >> r2 >> c2 >> x;
		int d = (x + 360) % 360 / 90;
		while (d--) rotr(r1, c1, r2, c2);
	}
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cout << g[i][j] << " \n"[j == N];
	return 0;
}
