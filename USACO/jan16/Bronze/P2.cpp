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

int x[100], dist[100];
queue<int> q;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("angry.in", "r", stdin);
	freopen("angry.out", "w", stdout);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> x[i];

	int ans = 0;
	for (int i = 0; i < N; i++) {
		memset(dist, -1, sizeof(dist));
		q.push(i), dist[i] = 1;
		int cur = 1;
		while (!q.empty()) {
			int v = q.front(); q.pop();
			for (int j = 0; j < N; j++)
				if (v != j && dist[j] == -1 && abs(x[j] - x[v]) <= dist[v])
					dist[j] = dist[v] + 1, q.push(j), ++cur;
		}
		ans = max(ans, cur);
	}
	cout << ans << '\n';
	return 0;
}
