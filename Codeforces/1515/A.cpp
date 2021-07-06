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

int w[100];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n, x;
	cin >> t;
	while (t--) {
		cin >> n >> x;
		int s = 0;
		for (int i = 0; i < n; i++) cin >> w[i], s += w[i];
		if (s == x) { cout << "NO\n"; continue; }
		cout << "YES\n";
		sort(w, w + n); s = 0;
		for (int i = 0; i < n - 1; i++)
			if ((s += w[i]) == x) { swap(w[i], w[i + 1]); break; }
		for (int i = 0; i < n; i++) cout << w[i] << ' ';
		cout << '\n';
	}
	return 0;
}
