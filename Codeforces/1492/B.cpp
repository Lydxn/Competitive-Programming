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

int p[100000], mx[100000], ans[100000];

int main() {
	//cin.sync_with_stdio(0);
	//cin.tie(0);
	
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> p[i];
		for (int i = 0; i < n; i++) mx[i] = p[i] > p[mx[i - 1]] ? i : mx[i - 1];
		int idx = n - 1, aidx = 0;
		while (idx != 0) {
			memcpy(ans + aidx, p + mx[idx], (n - mx[idx]) << 2), aidx += n - mx[idx];
			cout << idx << '\n';
			idx = mx[idx] - 1;
		}

		for (int i = 0; i < n; i++) cout << ans[i] << ' ';
		cout << '\n';
	}
	return 0;
}
