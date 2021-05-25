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

ll w[100000], pw[100000], h[100000], dp[100000];
int l[100000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	string s, t; int n, k;
	cin >> s >> k; n = s.size();
	pw[0] = 1;
	for (int i = 1; i <= n; i++) pw[i] = pw[i - 1] * 31 % MOD;
	for (int i = 1; i <= n; i++) h[i] = (h[i - 1] * 31 + s[i - 1]) % MOD;
	for (int i = 0; i < k; i++) {
		cin >> t; l[i] = t.size();
		for (char c : t) w[i] = (w[i] * 31 + c) % MOD;
	}
	dp[0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < k; j++)
			if ((h[i] - h[i - l[j]] * pw[l[j]] % MOD + MOD) % MOD == w[j])
				dp[i] = (dp[i] + dp[i - l[j]]) % MOD;
	cout << dp[n] << '\n';
	return 0;
}
