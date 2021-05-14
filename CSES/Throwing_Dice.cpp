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

ll a[6][6], b[6][6], res[6][6];

void matmul(ll x[6][6], ll y[6][6]) {
	memset(res, 0, 288);
	for (int i = 0; i < 6; i++)
		for (int k = 0; k < 6; k++)
			for (int j = 0; j < 6; j++)
				res[i][j] = (res[i][j] + x[i][k] * y[k][j]) % MOD;
	memcpy(x, res, 288);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ll n;
	cin >> n;
	for (int i = 0; i < 6; i++) a[i][i] = b[0][i] = 1;
	for (int i = 1; i < 6; i++) b[i][i - 1] = 1;
	while (n) {
		if (n & 1) matmul(a, b);
		matmul(b, b), n >>= 1;
	}
	cout << a[0][0] << '\n';
	return 0;
}
