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

int dp1[10001], dp2[10001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M; string A, B;
	cin >> N >> M >> A >> B;
	for (int i = 0; i <= M; i++) dp2[i] = i;
	for (int i = 1; i <= N; i++) {
		dp1[0] = i;
		for (int j = 1; j <= M; j++)
			dp1[j] = A[i - 1] == B[j - 1] ? dp2[j - 1] :
					min(min(dp1[j - 1], dp2[j]), dp2[j - 1]) + 1;
		memcpy(dp2, dp1, sizeof(dp1));
	}
	
	int ans = 0;
	for (int i = 1; i < M; i++) ans += dp1[i];
	cout << ans << '\n';
	return 0;
}
