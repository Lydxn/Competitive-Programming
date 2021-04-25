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

int seg[800005], suf[800005], pref[800005];
bool l[800005], r[800005];

void merge(int si, int s, int e) {
	int mid = (s + e) >> 1; bool cc = r[si << 1] != l[si << 1 | 1];
	l[si] = l[si << 1], r[si] = r[si << 1 | 1];
	pref[si] = pref[si << 1] + (mid - s + 1 == pref[si << 1] && cc ? pref[si << 1 | 1] : 0);
	suf[si] = suf[si << 1 | 1] + (e - mid == suf[si << 1 | 1] && cc ? suf[si << 1] : 0);
	seg[si] = max(seg[si << 1], seg[si << 1 | 1]);
	if (cc) seg[si] = max(seg[si], suf[si << 1] + pref[si << 1 | 1]);
}

void build(int si, int s, int e) {
	if (s == e) { seg[si] = suf[si] = pref[si] = 1; return; }
	int mid = (s + e) >> 1;
	build(si << 1, s, mid), build(si << 1 | 1, mid + 1, e);
	merge(si, s, e);
}

void update(int x, int si, int s, int e) {
	if (e < x || s > x) return;
	if (s == e) { l[si] ^= true, r[si] ^= true; return; }
	int mid = (s + e) >> 1;
	update(x, si << 1, s, mid), update(x, si << 1 | 1, mid + 1, e);
	merge(si, s, e);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, Q, p;
	cin >> N >> Q;
	build(1, 1, N);
	
	while (Q--) {
		cin >> p; update(p, 1, 1, N);
		cout << seg[1] << '\n';
	}
	return 0;
}
