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

#define f(i, j) (dp[i] - dp[j] + p[i + 1] * p[i + 1] - p[j + 1] * p[j + 1]) / (-2.0 * (p[j + 1] - p[i + 1]))

int p[100001], dp[100001];
deque<int> dq;

// dp[i]=dp[j]+(p[i]-p[j+1])^2+H
// dp[i]=dp[j]+p[i]^2-2*p[i]*p[j+1]+p[j+1]^2+H
// y=mx+b
// m=-2*p[j+1]
// x=p[i]
// b=dp[j]+p[j+1]^2

// mx+b=m'x+b'
// b-b'=m'x-mx
// b-b'=x(m'-m)
// x=(b-b')/(m'-m)

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, H;
	cin >> N >> H;
	for (int i = 1; i <= N; i++) cin >> p[i];
	dq.push_back(0);
	for (int i = 1; i <= N; i++) {
		while (dq.size() >= 2 && f(dq[0], dq[1]) < p[i]) dq.pop_front();
		dp[i] = dp[dq[0]] + (p[i] - p[dq[0] + 1]) * (p[i] - p[dq[0] + 1]) + H;
		while (dq.size() >= 2 && f(dq[dq.size() - 2], dq.back()) > f(dq.back(), i)) dq.pop_back();
		dq.push_back(i);
	}
	cout << dp[N] << '\n';
	return 0;
}
