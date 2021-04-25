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

int N, sx[100000], sy[100000];
vector<pii> px[20001], py[20001];

void solve(int x, vector<pii> &p, int s[]) {
	int cur = 0, sz = p.size();
	for (int i = 0; i < sz; i++) cur += p[i].first - p[0].first;
	for (int i = 0; i < sz; i++) {
		if (i) cur += (2 * i - sz) * (p[i].first - p[i - 1].first);
		s[p[i].second] = cur;
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("triangles.in", "r", stdin);
	freopen("triangles.out", "w", stdout);

	int X, Y;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> X >> Y;
		px[X + 10000].emplace_back(Y, i), py[Y + 10000].emplace_back(X, i);
	}

	for (int i = 0; i <= 20000; i++) {
		if (!px[i].empty()) sort(px[i].begin(), px[i].end()), solve(0, px[i], sx);
		if (!py[i].empty()) sort(py[i].begin(), py[i].end()), solve(1, py[i], sy);
	}

	int ans = 0;
	for (int i = 0; i < N; i++) ans = (ans + 1LL * sx[i] * sy[i]) % MOD;
	cout << ans << '\n';
	return 0;
}
