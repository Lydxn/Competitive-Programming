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

vector<int> p[500001];
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int X, N, T, F, mx = 0, ans = 0;
	cin >> X >> N;
	for (int i = 0; i < N; i++) {
		cin >> T >> F;
		int l = max(0, T - X);
		p[l].push_back(F);
		mx = max(mx, F);
	}
	for (int i = 0; i <= mx; i++) {
		for (int j : p[i]) pq.push(j);
		while (!pq.empty() && pq.top() < i) pq.pop();
		if (!pq.empty() && pq.top() >= i) ++ans, pq.pop();
	}
	cout << ans << '\n';
	return 0;
}
