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

int a[101];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		if (k > (n - 1) / 2) cout << "-1\n";
		else {
			for (int i = 1; i <= n; i++) a[i] = i;
			for (int i = 2; i < n && k--; i += 2) swap(a[i], a[i + 1]);
			for (int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
		}
	}
	return 0;
}
