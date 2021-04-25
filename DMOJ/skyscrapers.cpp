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

int S[100001], W[100001], psa[100001], cnts[20001], cntw[20001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int M, N, c, C, mxs = 0, mxw = 0;
	cin >> M >> N >> c >> C;
	for (int i = 1; i <= M; i++) cin >> S[i], mxs = max(mxs, S[i]), ++cnts[S[i]];
	for (int i = 1; i <= N; i++) cin >> W[i], mxw = max(mxw, W[i]), ++cntw[W[i]];

	if (mxs != mxw) {
		cout << "Impossible\n";
		return 0;
	}

	int mx = 0;
	sort(W + 1, W + N + 1);
	for (int i = 1; i <= N; i++) psa[i] = psa[i - 1] + W[i];
	for (int i = 1; i <= M; i++) {
		int b = upper_bound(W + 1, W + N + 1, S[i]) - W;
		mx += psa[b - 1] + (N - b + 1) * S[i];
	}

	int mn = 0;
	for (int i = 0; i <= 20000; i++) mn += max(cnts[i], cntw[i]) * i;

	cout << "Minimum: " << mn * c << ", maximum: " << mx * C << '\n';
	return 0;
}
