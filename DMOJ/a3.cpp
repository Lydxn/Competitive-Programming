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

bool yay(ull n) {
	return n >= 888 && n % 10 == 8 && n / 10 % 10 == 8 && n / 100 % 10 == 8;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	vector<ull> ans;
	for (ull i = 0; i * i * i < (1ULL << 63); i++)
		if (yay(i * i * i)) ans.push_back(i);

	int t, k;
	cin >> t;
	while (t--) {
		cin >> k;
		cout << ans[upper_bound(ans.begin(), ans.end(), k) - ans.begin()] << '\n';
	}
	return 0;
}
