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

int S[500001];
ll p[500001], s[500002];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> S[i];

	for (int i = 1, mx = INT_MIN; i <= N; i++) {
		mx = max(mx, S[i]);
		p[i] = p[i - 1] + (mx - S[i]);
	}

	for (int i = N, mx = INT_MIN; i >= 1; i--) {
		mx = max(mx, S[i]);
		s[i] = s[i + 1] + (mx - S[i]);
	}

	ll ans = LLONG_MAX;
	for (int i = 1; i < N; i++) ans = min(ans, p[i] + s[i + 1]);
	cout << ans << '\n';
	return 0;
}
