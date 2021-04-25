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

pair<ll, int> a[200000];
int N, idx[200000];

bool f(ll x) {
	for (int i = 0, j = 1; i < N; i++) {
		if (i && a[i].first - a[i - 1].first > x) ++j;
		idx[a[i].second] = j;
	}

	for (int i = 1; i < N; i++)
		if (idx[i - 1] > idx[i]) return false;
	return true;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> a[i].first, a[i].second = i;
	sort(a, a + N);

	ll l = 0, r = 1e18, mid;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (f(mid)) r = mid - 1;
		else l = mid + 1;
	}
	cout << r + 1 << '\n';
	return 0;
}
