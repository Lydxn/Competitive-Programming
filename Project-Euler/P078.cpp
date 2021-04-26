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

const int LIM = 60000;
ll dp[LIM + 1];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	dp[0] = 1;
	for (int i = 1; i < LIM; i++)
		for (int j = i; j <= LIM; j++)
			dp[j] = (dp[j] + dp[j - i]) % 1000000;
	for (int i = 1; i <= LIM; i++) {
		if (dp[i] == 0) { cout << i << '\n'; break; }
	}
	return 0;
}