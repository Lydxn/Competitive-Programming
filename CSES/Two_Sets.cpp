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
 
	int n;
	cin >> n;
 
	ll sum = 1LL * n * (n + 1) / 2;
	if (sum & 1) {
		cout << "NO\n";
		return 0;
	}
 
	vector<int> ans1, ans2;
	for (sum /= 2; n; n--) {
		if (sum - n >= 0) ans1.push_back(n), sum -= n;
		else ans2.push_back(n);
	}
 
	cout << "YES\n";
	cout << ans1.size() << '\n';
	for (int i : ans1) cout << i << ' ';
	cout << '\n';
	cout << ans2.size() << '\n';
	for (int i : ans2) cout << i << ' ';
	cout << '\n';
	return 0;
}