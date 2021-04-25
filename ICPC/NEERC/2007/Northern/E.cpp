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

priority_queue<plli, vector<plli>, greater<plli>> pq;
ll dist[100001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ll h, ans = 0; int a, b, c;
	cin >> h >> a >> b >> c;

	memset(dist, INFL, sizeof(dist)); dist[0] = 1; pq.emplace(1, 0);
	while (!pq.empty()) {
		auto v = pq.top(); pq.pop();
		if (v.first > dist[v.second]) continue;
		for (int i : {b, c}) {
			int nv = (v.second + i) % a; ll nw = v.first + i;
			if (nw < dist[nv]) pq.emplace(dist[nv] = nw, nv);
		}
	}

	for (int i = 0; i < a; i++)
		if (dist[i] <= h) ans += (h - dist[i]) / a + 1;
	cout << ans << '\n';
	return 0;
}
