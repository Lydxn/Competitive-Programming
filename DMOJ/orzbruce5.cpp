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

int dp[5000][30][30], q[30][30];
bool good[5000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, s, L, R; string S;
	cin >> N >> M >> s;
	for (int i = 0; i < N; i++) {
		cin >> S;
		for (int j = 0; j < s; j++)
			for (int k = 0; k < s; k++)
				if (S[k] == S[k + j])
					dp[i][k][k + j] = j <= 1 ? true : dp[i][k + 1][k + j - 1];
	}

	memset(good, true, sizeof(good));
	while (M--) cin >> L >> R, q[L - 1][R - 1] = true;
	for (int l = 0; l < s; l++)
		for (int r = 0; r < s; r++)
			if (q[l][r])
				for (int j = 0; j < N; j++)
					good[j] &= dp[j][l][r];
	int ans = 0;
	for (int i = 0; i < N; i++) ans += good[i];
	cout << ans << '\n'; 
	return 0;
}
