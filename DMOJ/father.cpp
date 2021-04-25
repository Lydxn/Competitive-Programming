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

int N, S, s[5000], b[5000], st[5000], bt[5000], sidx, bidx;

bool f(int x) {
	memcpy(st, s, N << 2), memcpy(bt, b, N << 2);
	for (int i = 0; i < bidx; i++) {
		sort(st, st + sidx); int cur = bt[i];
		for (int j = 0; j < sidx && cur >= S; j++) {
			if (st[j] + 1 >= S) continue;
			int m = min(x, min(cur - S + 1, S - st[j] - 1));
			cur -= m, st[j] += m;
		}
		if (cur >= S) return false;
	}
	return true;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> S; --N;
	for (int i = 0, P; i < N; i++) {
		cin >> P;
		if (P < S) s[sidx++] = P;
		else b[bidx++] = P;
	}

	int l = 0, r = 1e6;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (f(mid)) r = mid - 1;
		else l = mid + 1;
	}

	if (l > 1e6) cout << "impossible\n";
	else cout << l << '\n';
	return 0;
}