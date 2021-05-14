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

int n;
ll A[100][100], B[100][100], res[100][100];

void matmul(ll X[100][100], ll Y[100][100]) {
	memset(res, 0, sizeof(res));
	for (int i = 0; i < n; i++)
		for (int k = 0; k < n; k++)
			for (int j = 0; j < n; j++)
				res[i][j] = (res[i][j] + X[i][k] * Y[k][j]) % MOD;
	memcpy(X, res, n * 800);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int m, k, a, b;
	cin >> n >> m >> k;
	while (m--) cin >> a >> b, ++B[a - 1][b - 1];
	for (int i = 0; i < n; i++) A[i][i] = 1;
	while (k) {
		if (k & 1) matmul(A, B);
		matmul(B, B), k >>= 1;
	}
	cout << A[0][n - 1] << '\n';
	return 0;
}
