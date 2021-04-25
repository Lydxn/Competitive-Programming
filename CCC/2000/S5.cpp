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

const int MAXN = 1000;
double x[MAXN], y[MAXN], l[MAXN], r[MAXN];
bool bad[MAXN];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> x[i] >> y[i], l[i] = 0.0, r[i] = 1000.0;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (x[i] == x[j]) {
				bad[y[i] < y[j] ? j : i] = true;
				continue;
			}

			double cx = (x[i] + x[j]) / 2.0, cy = (y[i] + y[j]) / 2.0;
			double bound = cx + (y[j] - y[i]) / (x[j] - x[i]) * cy;
			if (x[i] < x[j]) r[i] = min(r[i], bound), l[j] = max(l[j], bound);
			else r[j] = min(r[j], bound), l[i] = max(l[i], bound);
		}
	}

	for (int i = 0; i < n; i++)
		if (l[i] < r[i] + 1e-6 && !bad[i])
			cout << fixed << setprecision(2) << "The sheep at (" << x[i] << ", " << y[i] << ") might be eaten.\n";
	return 0;
}
