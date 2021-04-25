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
const ll MOD = 10000000000039L;

template <class T, class C = less<T>>
using ordered_set = tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;

unordered_set<ll> s;
int N, dp[200001];

void solve() {
	string S;
	cin >> S; int sz = S.size();
	memset(dp, INF, sizeof(dp)); dp[0] = 0;
	for (int i = 1; i <= sz; i++) {
		ll hsh = 0;
		for (int j = i; j; j--) {
			hsh = (hsh * 31 + S[j - 1]) % MOD;
			if (s.count(hsh)) dp[i] = min(dp[i], dp[j - 1] + 1);
		}
	}
	cout << dp[sz] - 1 << '\n';
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	string W;
	for (int i = 0; i < N; i++) {
		cin >> W; ll hsh = 0;
		for (int j = W.size() - 1; j >= 0; j--)
			hsh = (hsh * 31 + W[j]) % MOD;
		s.insert(hsh);
	}
	
	for (int _ = 0; _ < 10; _++) solve();
	return 0;
}