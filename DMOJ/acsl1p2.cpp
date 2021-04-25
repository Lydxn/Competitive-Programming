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

int x[1000], vx[1000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, v, d, t;
	cin >> n >> v >> d >> t;
	for (int i = 0; i < n; i++) x[i] = -i * d;
	vx[0] = v;
	while (t--) {
		for (int i = 0; i < n; i++) x[i] += 5 * vx[i];
		
		int diff0 = x[0] - x[1];
		if (diff0 <= 0) { cout << "-1\n"; return 0; }
		else if (diff0 < 80) vx[0] += 5;
		else if (diff0 > 100) vx[0] = max(vx[0] - 5, 0);
			
		for (int i = 1; i < n; i++) {
			int diff = x[i - 1] - x[i];
			if (diff <= 0) { cout << "-1\n"; return 0; }
			else if (diff < 80) vx[i] = max(vx[i] - 5, 0);
			else if (diff > 100) vx[i] += 5;
		}
	}
	cout << x[0] << '\n';
	return 0;
}
