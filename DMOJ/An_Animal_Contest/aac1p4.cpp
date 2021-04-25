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

int a[1000001];
vector<int> idxs[100001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, Q, l, r, x;
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) cin >> a[i], idxs[a[i]].push_back(i);
	for (int i = 1; i <= 100000; i++) sort(idxs[i].begin(), idxs[i].end());
	while (Q--) {
		cin >> l >> r >> x;
		for (int i = 1; i * i < x; i++) {
			if (x % i) continue;
			auto v1 = lower_bound(idxs[i].begin(), idxs[i].end(), l);
			auto v2 = upper_bound(idxs[x / i].begin(), idxs[x / i].end(), r);
			if (v1 == idxs[i].end()) continue;
			if (v2 == idxs[x / i].begin()) continue;
			int t1 = v1 - idxs[i].begin(), t2 = v2 - idxs[x / i].begin() - 1;
			if (t2 >= 0 && idxs[i][t1] <= r && idxs[x / i][t2] >= l)
				{ cout << "YES\n"; goto nxt; }
		}
		cout << "NO\n"; nxt:;
	}
	return 0;
}
