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

int x[50000], y[50000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("reduce.in", "r", stdin);
	freopen("reduce.out", "w", stdout);

	int N, ans = INT_MAX;
	cin >> N;
	multiset<int> sx, sy;
	for (int i = 0; i < N; i++) cin >> x[i] >> y[i], sx.insert(x[i]), sy.insert(y[i]);
	for (int i = 0; i < N; i++) {
		sx.erase(sx.find(x[i])), sy.erase(sy.find(y[i]));
		ans = min(ans, (*sx.rbegin() - *sx.begin()) * (*sy.rbegin() - *sy.begin()));
		sx.insert(x[i]), sy.insert(y[i]);
	}
	cout << ans << '\n';
	return 0;
}
