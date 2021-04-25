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

pair<int, bool> c[50002];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("learning.in", "r", stdin);
	freopen("learning.out", "w", stdout);

	int N, A, B, W, ans = 0; string S;
	cin >> N >> A >> B;
	for (int i = 1; i <= N; i++) {
		cin >> S >> W;
		c[i] = {W, S == "S"};
	}

	sort(c + 1, c + N + 1); c[0] = {-INF, true}, c[N + 1] = {INF, true};
	for (int i = 1; i <= N + 1; i++) {
		int l = c[i - 1].first, r = c[i].first;
		if (c[i - 1].second) ans += max(0, min(B, (l + r - 1) / 2) - max(A, l + 1) + 1);
		if (c[i].second) ans += max(0, min(B, r - 1) - max(A, (l + r + 2) / 2) + 1);
		ans += (r - l) % 2 == 0 && (c[i - 1].second || c[i].second) && A <= (l + r) / 2 && (l + r) / 2 <= B;
	}
	
	for (int i = 1; i <= N; i++)
		if (A <= c[i].first && c[i].first <= B)
			ans += c[i].second;
	cout << ans << '\n';
	return 0;
}
