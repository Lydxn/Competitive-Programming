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

pii v[5000];
int nv[5000], dp[5000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> v[i].first, v[i].second = i;

	sort(v, v + N);
	for (int i = 0; i < N; i++)
		nv[v[i].second] = i / K;

	int lis = 0;
	for (int i = 0; i < N; i++) {
		int idx = upper_bound(dp, dp + lis, nv[i]) - dp;
		dp[idx] = nv[i];
		if (idx == lis) ++lis;
	}
	cout << N - lis << '\n';
	return 0;
}
