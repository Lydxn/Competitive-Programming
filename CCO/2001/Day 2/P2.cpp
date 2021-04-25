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

int cnt[50], x[50], y[50];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> x[i] >> y[i];

	for (double i = 0.01; i < 10; i += 0.01) {
		for (double j = 0.01; j < 10; j += 0.01) {
			double mn = DBL_MAX; int mi = -1;
			for (int k = 0; k < N; k++) {
				double dist = (i - y[k]) * (i - y[k]) + (j - x[k]) * (j - x[k]);
				if (dist < mn) mn = dist, mi = k;
			}
			++cnt[mi];
		}
	}

	for (int i = 0; i < N; i++)
		cout << "Restaurant at (" << x[i] << ',' << y[i] << ") serves " << round(cnt[i] / 10000.0) << "% of the population.\n";
	return 0;
}
