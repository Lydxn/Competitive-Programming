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

string o[100000];
int n, m, t[100000];

bool f(bool b, int i) {
	for (int j = 0; j < n; j++) {
		bool c = (t[j] >> i) & 1;
		if (o[j] == "AND") b &= c;
		else if (o[j] == "OR") b |= c;
		else b ^= c;
	}
	return b;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int ans = 0, cur = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> o[i] >> t[i];
	for (int i = 29; i >= 0; i--) {
		if (f(0, i)) ans |= 1 << i;
		else if ((cur | (1 << i)) <= m && f(1, i)) ans |= 1 << i, cur |= 1 << i;
	}
	cout << ans << '\n';
	return 0;
}
