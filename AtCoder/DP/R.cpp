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

int a[50][50], b[50][50], res[50][50];

void matmul(int A[50][50], int B[50][50], int N) {
	memset(res, 0, sizeof(res));
	for (int i = 0; i < N; i++)
		for (int k = 0; k < N; k++)
			for (int j = 0; j < N; j++)
				res[i][j] = (res[i][j] + (ll) A[i][k] * B[k][j]) % MOD;
	memcpy(A, res, sizeof(res));
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; ll K;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> a[i][j];
	for (int i = 0; i < N; i++) b[i][i] = 1;

	while (K) {
		if (K & 1) matmul(b, a, N);
		K >>= 1, matmul(a, a, N);
	}

	int ans = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			ans = (ans + b[i][j]) % MOD;
	cout << ans << '\n';
	return 0;
}
