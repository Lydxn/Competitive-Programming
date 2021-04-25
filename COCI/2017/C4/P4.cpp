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

int b[5000], bb[5000], dp[5001], good[2][5001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) cin >> b[i];
	for (int i = 0; i <= N; i++) good[0][i] = M - 1, good[1][i] = INF;
	for (int i = 0; i < N; i++) bb[i] = b[i] ^ b[(i + 1) % N] ^ 1;
	for (int i = M - 2; i >= 0; i--) {
		for (int j = 0; j < N; j++) dp[j] = good[bb[j]][j + 1] <= i + K;
		for (int j = 0; j < N; j++) good[dp[j]][j] = i;
		good[dp[0]][N] = i;
	}
	for (int i = 0; i < N; i++)
		cout << (dp[i] ^ b[i] ^ 1) << ' ';
	return 0;
}
