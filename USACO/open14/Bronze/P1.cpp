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

	freopen("odometer.in", "r", stdin);
	freopen("odometer.out", "w", stdout);

	ll X, Y; unordered_set<ll> ans;
	cin >> X >> Y;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (i == j) continue;
			for (int k = 2; k <= 17; k++) {
				string s(k, i + '0');
				for (int l = 0; l <= int(s.size()); l++) {
					s.insert(s.begin() + l, j + '0');
					ll res = stoll(s);
					if (X <= res && res <= Y && s[0] != '0')
						ans.insert(res);
					s.erase(s.begin() + l);
				}
			}
		}
	}
	cout << ans.size() << '\n';
	return 0;
}
