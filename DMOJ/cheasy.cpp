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

int psa[3001][3001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int M, N, R, C, X, R2, C2;
	cin >> M >> N;
	while (cin >> R >> C >> X) {
		if (R == 0 && C == 0 && X == 0) break;
		psa[R][C] = (R + C) & 1 ? X : -X;
	}

	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= N; j++)
			psa[i][j] += psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1];

	while (cin >> R >> C >> R2 >> C2) {
		if (R == 0 && C == 0 && R2 == 0 && C2 == 0) break;
		cout << (psa[R2][C2] - psa[R - 1][C2] - psa[R2][C - 1] + psa[R - 1][C - 1]) * ((R + C) & 1 ? 1 : -1) << '\n';
	}
	return 0;
}
