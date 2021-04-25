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

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T, a, b; string line;
	cin >> T;
	while (T--) {
		cin >> line;
		a = line[0] - '0', b = line[2] - '0';
		int cnt = 1;
		while (!(a == 8 && b == 4)) {
			if (a == 1 && b == 2) a = 4, b = 1;
			else if (a == 4 && b == 2) a = 8, b = 1;
			else if (++b == 5) b = 1, ++a;
			++cnt;
		}
		cout << cnt << '\n';
	}
	return 0;
}
