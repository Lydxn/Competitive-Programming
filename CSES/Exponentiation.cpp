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

int pm(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = 1LL * res * a % MOD;
		a = 1LL * a * a % MOD, b >>= 1;
	}
	return res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, a, b;
	cin >> n;
	while (n--) {
		cin >> a >> b;
		cout << pm(a, b) << '\n';
	}
	return 0;
}
