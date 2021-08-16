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

int a[100000], ind[100000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 0; i < n; i++) cin >> a[i], ind[i] = i;
		sort(ind, ind + n, [&] (int x, int y) { return a[x] < a[y]; });
		for (int i = 1; i < n; i++)
			if (ind[i - 1] + 1 != ind[i]) --k;
		cout << (k > 0 ? "Yes" : "No") << '\n';
	}
	return 0;
}
