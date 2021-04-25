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

int t[2000000], d[2000000], H, J;
queue<int> q;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int H, J, N, A, B;
	cin >> H >> J >> N;
	while (N--) cin >> A >> B, ++t[A], --t[B + 1];
	for (int i = 1; i <= H; i++) t[i] += t[i - 1];

	memset(d, -1, sizeof(d)); d[0] = 0; q.push(0);
	int mx = 0;
	while (!q.empty()) {
		int v = q.front(); q.pop();
		if (v >= H) { cout << d[v] << '\n'; return 0; }
		if (!t[v + J] && d[v + J] == -1) d[v + J] = d[v] + 1, q.push(v + J);
		for (int i = mx + 1; i < v; i++)
			if (!t[i] && d[i] == -1) d[i] = d[v] + 1, q.push(i);
		mx = max(mx, v);
	}
	cout << "-1\n";
	return 0;
}
