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

struct line {
	ll m, b; int id;
	line() {}
	line(ll m, ll b, int id) : m(m), b(b), id(id) {}
	bool operator< (line &l) const { return m < l.m || (m == l.m && b < l.b); }
	ll eval(ll x) { return m * x + b; }
	double cross(line &l) { return (double) (b - l.b) / (l.m - m); }
};

line L[100000];
deque<line> dq;
pii q[500000];
int ans[500000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, Q, S, M;
	cin >> N >> Q;
	for (int i = 0; i < N; i++) {
		cin >> S >> M;
		L[i] = line(M, S, i);
	}

	sort(L, L + N);
	for (int i = 0; i < N; i++) {
		while (!dq.empty() && L[i].m == dq[dq.size() - 1].m) dq.pop_back();
		while (dq.size() >= 2 && L[i].cross(dq[dq.size() - 1]) < dq[dq.size() - 1].cross(dq[dq.size() - 2])) dq.pop_back();
		dq.push_back(L[i]);
	}

	for (int i = 0, x; i < Q; i++) cin >> x, q[i] = {x, i};
	sort(q, q + Q);

	for (int i = 0; i < Q; i++) {
		while (dq.size() >= 2) {
			ll ab = dq[0].eval(q[i].first), ac = dq[1].eval(q[i].first);
			if (ab > ac || (ab == ac && dq[0].id < dq[1].id)) break;
			dq.pop_front();
		}
		ans[q[i].second] = dq.front().id;
	}

	for (int i = 0; i < Q; i++) cout << ans[i] << '\n';
	return 0;
}
