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

ll n, a[2][2], b[2][2] = {{1, 1}, {1, 0}}, res[2][2];

void matmul(ll x[2][2], ll y[2][2]) {
	memset(res, 0, 32);
	for (int i = 0; i < 2; i++)
		for (int k = 0; k < 2; k++)
			for (int j = 0; j < 2; j++)
				res[i][j] = (res[i][j] + x[i][k] * y[k][j]) % MOD;
	memcpy(x, res, 32);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	if (n == 0) { cout << "0\n"; return 0; }
	a[0][0] = a[1][1] = 1; --n;
	while (n) {
		if (n & 1) matmul(a, b);
		matmul(b, b), n >>= 1;
	}
	cout << a[0][0] << '\n';
	return 0;
}
