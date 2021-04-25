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

int C[101][101][101];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int L, M, N, x1, y1, z1, x2, y2, z2;
	cin >> L >> M >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			for (int k = 1; k <= L; k++) {
				cin >> C[i][j][k];
				C[i][j][k] += C[i - 1][j][k] + C[i][j - 1][k] + C[i][j][k - 1]
							- C[i - 1][j - 1][k] - C[i - 1][j][k - 1] - C[i][j - 1][k - 1]
							+ C[i - 1][j - 1][k - 1];
			}
		}
	}

	while (cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2) {
		cout << C[z2][y2][x2] - C[z1][y2][x2] - C[z2][y1][x2] - C[z2][y2][x1]
			  + C[z1][y1][x2] + C[z1][y2][x1] + C[z2][y1][x1] - C[z1][y1][x1] << '\n';
	}
	return 0;
}
