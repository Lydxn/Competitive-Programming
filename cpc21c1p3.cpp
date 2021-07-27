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

int donut(int a, int b) {
	if (b > a) return 0;
	return a * a - b * b;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T, R1, R2, R3;
	cin >> T;
	while (T--) {
		cin >> R1 >> R2 >> R3;
		int p1 = max(0, R1 - R3) * max(0, R1 - R3);
		int p2 = donut(R2 - R3, R1 + R3);
		int l = min(R2 - R3, R3 - R1), p3 = R3 > R1 ? l * l : 0;
		double ans = 1.0 * (p1 + p2 + p3) / ((R2 - R3) * (R2 - R3));
		cout << ans << '\n';
	}
	return 0;
}
