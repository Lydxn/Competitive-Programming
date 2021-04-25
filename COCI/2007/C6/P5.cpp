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

struct pt {
	int x, y, a, b, c, d;
} p[100000];
int d1[100000], d2[100000], idxs[100000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, K, X, Y; string S;
	cin >> N >> K >> S;
	for (int i = 0; i < N; i++) {
		cin >> X >> Y, p[i] = {X, Y, -1, -1, -1, -1};
		d1[i] = X - Y, d2[i] = X + Y, idxs[i] = i;
	}
	
	sort(idxs, idxs + N, [&] (int &a, int &b) { return d1[a] < d1[b] || (d1[a] == d1[b] && p[a].x < p[b].x); });
	for (int i = 1; i < N; i++)
		if (d1[idxs[i]] == d1[idxs[i - 1]])
			p[idxs[i - 1]].a = idxs[i], p[idxs[i]].d = idxs[i - 1];
	sort(idxs, idxs + N, [&] (int &a, int &b) { return d2[a] < d2[b] || (d2[a] == d2[b] && p[a].x < p[b].x); });
	for (int i = 1; i < N; i++)
		if (d2[idxs[i]] == d2[idxs[i - 1]])
			p[idxs[i - 1]].b = idxs[i], p[idxs[i]].c = idxs[i - 1];

	int cur = 0;
	for (char c : S) {
		int nxt = c == 'A' ? p[cur].a : c == 'B' ? p[cur].b : c == 'C' ? p[cur].c : p[cur].d;
		if (nxt == -1) continue;
		p[p[cur].a].d = p[cur].d, p[p[cur].d].a = p[cur].a, p[p[cur].b].c = p[cur].c, p[p[cur].c].b = p[cur].b;
		cur = nxt;
	}
	cout << p[cur].x << ' ' << p[cur].y << '\n';
	return 0;
}
