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

struct shake {
	int t, x, y;
	bool operator< (const shake &s) const { return t < s.t; }
} s[100];
int N, T, cnt[101];
bool S[101], R[101];

bool f(int n, int k) {
	memset(cnt, 0, sizeof(cnt)); memset(R, false, sizeof(R));
	R[n] = true;
	for (int i = 0; i < T; i++) {
		if (R[s[i].x]) ++cnt[s[i].x];
		if (R[s[i].y]) ++cnt[s[i].y];
		if (R[s[i].x] && cnt[s[i].x] <= k) R[s[i].y] = true;
		if (R[s[i].y] && cnt[s[i].y] <= k) R[s[i].x] = true;
	}

	for (int i = 1; i <= N; i++)
		if (S[i] != R[i]) return false;
	return true;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("tracing.in", "r", stdin);
	freopen("tracing.out", "w", stdout);

	cin >> N >> T;
	char c;
	for (int i = 1; i <= N; i++) cin >> c, S[i] = c == '1';
	for (int i = 0; i < T; i++) cin >> s[i].t >> s[i].x >> s[i].y;
	sort(s, s + T);

	int ans1 = 0, ans2 = INF, ans3 = -INF;
	for (int i = 1; i <= N; i++) {
		bool b = false;
		for (int j = 0; j <= T; j++)
			if (f(i, j)) b = true, ans2 = min(ans2, j), ans3 = max(ans3, j);
		ans1 += b;
	}
	
	cout << ans1 << ' ' << ans2 << ' ';
	if (ans3 == T) cout << "Infinity\n";
	else cout << ans3 << '\n';
	return 0;
}
