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

struct wtf {
	double v; int i;
	bool operator> (const wtf &w) const { return v > w.v; }
} w[10000];
bool vis[101];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, K; double ans = 0;
	cin >> N >> M >> K;
	for (int i = 0; i < M * N; i++)
		cin >> w[i].i >> w[i].v;
	sort(w, w + M * N, greater<wtf>());
	for (int i = 0; i < M * N && K; i++)
		if (!vis[w[i].i])
			ans += w[i].v, vis[w[i].i] = true, --K;
	cout << fixed << setprecision(1) << ans << '\n';
	return 0;
}
