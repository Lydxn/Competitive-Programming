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

int L[100000], R[100000], N, M;

bool f(int x) {
	int p = 0;
	for (int i = 0; i < N; i++, p++) {
		while (p < M && abs(L[i] - R[p]) > x) ++p;
		if (p == M) return false;
	}
	return true;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> L[i];
	for (int i = 0; i < M; i++) cin >> R[i];

	if (N > M) swap(N, M), swap(L, R);
	sort(L, L + N), sort(R, R + M);

	int l = 0, r = 1e9, mid;
	while (l < r) {
		mid = (l + r) >> 1;
		if (f(mid)) r = mid;
		else l = mid + 1;
	}
	cout << l << '\n';
	return 0;
}
