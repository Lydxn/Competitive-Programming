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

int x[50], y[50], e[50], n[50], ans[50], eidx, nidx;
bool vis[50];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; char d;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> d >> x[i] >> y[i];
		if (d == 'E') e[eidx++] = i;
		else n[nidx++] = i;
	}

	sort(e, e + eidx, [&] (int &a, int &b) { return y[a] < y[b]; });
	sort(n, n + nidx, [&] (int &a, int &b) { return x[a] < x[b]; });
	memset(ans, INF, sizeof(ans));
	
	for (int i = 0; i < eidx; i++) {
		for (int j = 0; j < nidx; j++) {
			int ee = e[i], nn = n[j];
			if (x[ee] > x[nn] || y[ee] < y[nn] || vis[ee] || vis[nn]) continue;
			int dx = x[nn] - x[ee], dy = y[ee] - y[nn];
			if (dx > dy) ans[ee] = min(ans[ee], dx), vis[ee] = true;
			if (dx < dy) ans[nn] = min(ans[nn], dy), vis[nn] = true;
		}
	}

	for (int i = 0; i < N; i++)
		if (ans[i] == INF) cout << "Infinity\n";
		else cout << ans[i] << '\n';
	return 0;
}
