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

ll A[1000001], psa[1000001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, H, P;
	cin >> N >> H >> P;
	for (int i = 1; i <= N; i++) cin >> A[i];
	sort(A + 1, A + N + 1);
	for (int i = 1; i <= N; i++) psa[i] = psa[i - 1] + A[i];
	ll ans = psa[N] * P;
	for (int i = 1; i <= N; i++)
		ans = min(ans, A[i] * H + (psa[N] - psa[i] - A[i] * (N - i)) * P);
	cout << ans << '\n';
	return 0;
}
