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

int S[1048577], seg[2097153], N;

void update(int i, int x) {
	for (S[i] = x, i += N - 1; i >>= 1; ) seg[i] = S[seg[i << 1]] > S[seg[i << 1 | 1]] ? seg[i << 1] : seg[i << 1 | 1];
}

int query(int i) {
	int res = 0;
	for (int x = i + N - 1; seg[x >>= 1] == i; ++res);
	return res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int M, A, B; char op;
	cin >> N >> M; N = 1 << N;
	for (int i = 1; i <= N; i++) cin >> S[i], seg[i + N - 1] = i;
	for (int i = N - 1; i; i--) seg[i] = S[seg[i << 1]] > S[seg[i << 1 | 1]] ? seg[i << 1] : seg[i << 1 | 1];

	while (M--) {
		cin >> op;
		if (op == 'R') cin >> A >> B, update(A, B);
		else if (op == 'W') cout << seg[1] << '\n';
		else cin >> A, cout << query(A) << '\n';
	}
	return 0;
}
