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

string ans;

void pre(int m) {
	int a = 0, b = 1, c = 1;
	for (int i = 0; i < m * m; i++) {
		c = (a + b) % m, a = b, b = c;
		ans += to_string(a);
		if (a == 0 && b == 1) break;
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int M, Q; ll N;
	cin >> M >> Q; pre(M);
	while (Q--) {
		cin >> N;
		cout << ans[(N - 1) % ans.size()] << '\n';
	}
	return 0;
}
