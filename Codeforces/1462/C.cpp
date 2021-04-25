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

	int t, x;
	cin >> t;
	while (t--) {
		cin >> x;
		if (x > 45) cout << "-1\n";
		else {
			vector<int> ans;
			for (int i = 9; i > 0; i--) {
				ans.push_back(min(x, i));
				x -= i;
				if (x <= 0) break;
			}
			for (int i = int(ans.size()) - 1; i >= 0; i--)
				cout << ans[i];
			cout << '\n';
		}
	}
	return 0;
}
