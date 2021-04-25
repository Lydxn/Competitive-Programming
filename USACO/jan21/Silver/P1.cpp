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

set<int> s[100001];
int p[100001], nxt[100001], ans[100001];
bool vis[100001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, K, a, b;
	cin >> N >> K;
	for (int i = 1; i <= N; i++) s[i].insert(i), p[i] = i;
	while (K--) {
		cin >> a >> b;
		s[p[a]].insert(b), s[p[b]].insert(a);
		swap(p[a], p[b]);
	}
	for (int i = 1; i <= N; i++) nxt[p[i]] = i;
	for (int i = 1; i <= N; i++) {
		if (vis[i]) continue;
		set<int> res = s[i];
		for (int cur = nxt[i]; cur != i; cur = nxt[cur])
			vis[cur] = true, res.insert(s[cur].begin(), s[cur].end());
		for (int cur = nxt[i]; cur != i; cur = nxt[cur])
			ans[cur] = res.size();
		ans[i] = res.size();
	}
	for (int i = 1; i <= N; i++) cout << ans[i] << '\n';
	return 0;
}
