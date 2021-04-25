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

int n, k, x[200000];

bool f(ll m) {
	int cnt = 0;
	for (int i = 0; i < n; ) {
		if (x[i] > m) return false;
		ll s = 0;
		while (i < n && s + x[i] <= m) s += x[i++];
		++cnt;
	}
	return cnt <= k;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> x[i];

	ll l = 1, r = 1e15;
	while (l <= r) {
		ll mid = (l + r) >> 1;
		if (f(mid)) r = mid - 1;
		else l = mid + 1;
	}
	cout << l << '\n';
	return 0;
}
