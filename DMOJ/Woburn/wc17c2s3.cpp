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

unordered_map<int, int> mp;
set<int> o;
struct qu { int l, r, i; } q[300000];
int t[300000], qidx;
bool b[300000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, E, A, B;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> E;
		if (E == 1) cin >> A, o.insert(A), mp[A] = i, b[i] = true;
		else cin >> A >> B, q[qidx++] = {A - B, A + B, i};
	}
	for (int i = 0; i < qidx; i++) {
		while (true) {
			auto it = o.lower_bound(q[i].l);
			if (it == o.end() || *it > q[i].r) break;
			++t[max(q[i].i, mp[*it])], o.erase(it);
		}
	}
	for (int i = 0, ans = 0; i < N; i++)
		ans += b[i], ans -= t[i], cout << ans << '\n';
	return 0;
}
