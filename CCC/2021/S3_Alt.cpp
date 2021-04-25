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

pll e[400000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; ll P, W, D, cur = 0, lsum = 0, rsum = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> P >> W >> D; P += 1e9;
		e[i << 1] = {P - D, W}, e[i << 1 | 1] = {P + D, -W};
		cur += (P - D) * W, rsum += W;
	}
	sort(e, e + (N << 1));
	
	ll ans = cur, p = 0;
	for (int i = 0; i < N << 1; i++) {
		P = e[i].first, W = e[i].second;
		cur += (P - p) * (lsum - rsum), ans = min(ans, cur), p = P;
		(W > 0 ? lsum : rsum) += W;
	}
	cout << ans << '\n';
	return 0;
}