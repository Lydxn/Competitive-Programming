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

pii I[100000];
int N, dp[100000], track[100000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> I[i].first >> I[i].second;

	// sort, then reduction to LIS
	sort(I, I + N, [] (pii a, pii b) {
		return a.first > b.first || (a.first == b.first && a.second < b.second);
	});

	int len = 0;
	for (int i = 0; i < N; i++) {
		int x = upper_bound(dp, dp + len, I[i].second) - dp;
		if (x == len) ++len;
		dp[x] = I[i].second, track[i] = x ? dp[x - 1] : -1;
	}

	cout << len << '\n';
	for (int ptr = N - 1, e = dp[len - 1]; e != -1; ptr--)
		if (e == I[ptr].second)
			cout << I[ptr].first << ' ' << I[ptr].second << '\n', e = track[ptr];
	return 0;
}
