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

int L;
ll dp[2000001], C[2000001];
deque<int> dq;

double cross(int i, int j) {
	ll vi = -i - 1 - C[i] - L, vj = -j - 1 - C[j] - L;
	return (dp[j] + vj * vj - dp[i] - vi * vi) / (2.0 * (vi - vj));
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N >> L;
	for (int i = 1; i <= N; i++) cin >> C[i], C[i] += C[i - 1];
	dq.push_back(0);
	for (int i = 1; i <= N; i++) {
		while (dq.size() >= 2 && cross(dq[0], dq[1]) < C[i] + i)
			dq.pop_front();
		ll x = i - dq[0] - 1 + C[i] - C[dq[0]] - L;
		dp[i] = dp[dq[0]] + x * x;
		while (dq.size() >= 2 && cross(dq[dq.size() - 2], i) < cross(dq[dq.size() - 2], dq.back()))
			dq.pop_back();
		dq.push_back(i);
	}
	cout << dp[N] << '\n';
	return 0;
}