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

pii p[100001];
int N, M, T;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> T;
	for (int i = 1; i <= N; i++) cin >> p[i].first >> p[i].second;
	sort(p + 1, p + N + 1);

	int ans = 0, cur = 0;
	for (int i = 1; i <= N; i++) {
		int sz = (M - p[i].first * 2) / T;
		if (sz <= 0) break;
		pq.push(p[i].second), cur += p[i].second;
		while (int(pq.size()) > sz) cur -= pq.top(), pq.pop();
		ans = max(ans, cur);
	}
	cout << ans << '\n';
	return 0;
}
