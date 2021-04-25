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

int d[100];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n; vector<string> ans;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> d[i];
	for (int i = 0; i < n - 1; i++) {
		int mx = 0;
		for (int j = 0; j < n - i; j++)
			if (d[j] > d[mx]) mx = j;
		for (int j = 0; j < mx; j++)
			ans.push_back("UZMI L L"), ans.push_back("STAVI L D");
		ans.push_back("UZMI D L");
		for (int j = mx + 1; j < n - i; j++)
			ans.push_back("UZMI L L"), ans.push_back("STAVI L D");
		ans.push_back("STAVI D L");
		for (int j = 0; j < n - i - 1; j++)
			ans.push_back("UZMI L D"), ans.push_back("STAVI L L");
		memcpy(d + mx, d + mx + 1, (n - mx) * 4);
	}

	cout << ans.size() << '\n';
	for (auto i : ans) cout << i << '\n';
	return 0;
}
