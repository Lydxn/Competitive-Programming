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

const int BASE = 31;
int sz[2000];
ll shsh[2001], hsh[2000], pw[2001];
bitset<2000> dp[2001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	pw[0] = 1;
	for (int i = 1; i <= 2000; i++) pw[i] = pw[i - 1] * BASE % MOD; 

	string S, w; int N;
	cin >> S >> N; int ss = S.size();
	for (int i = 1; i <= ss; i++)
		shsh[i] = (shsh[i - 1] * BASE + S[i - 1] - 'a') % MOD;
	for (int i = 0; i < N; i++) {
		cin >> w; sz[i] = w.size();
		for (char c : w) hsh[i] = (hsh[i] * BASE + c - 'a') % MOD;
	}
	
	for (int i = 1; i <= ss; i++) {
		for (int j = 0; j < N; j++) {
			if (i >= sz[j] && (shsh[i] - shsh[i - sz[j]] * pw[sz[j]] % MOD + MOD) % MOD == hsh[j])
				dp[i].set(i - sz[j]), dp[i] |= dp[i - sz[j]];
		}
	}
	
	int ans = 0;
	for (int i = 1; i <= ss; i++)
		ans += dp[i].count();
	cout << ans << '\n';
	return 0;
}
