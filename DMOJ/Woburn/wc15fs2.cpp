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

int C[1000000], T[1000000], N, M, K;

bool f(int x) {
	int j = 0;
	for (int i = 0; i < M; i++) {
		int s = j;
		while (j < N && j - s < x && C[j] - K <= T[i] && T[i] <= C[j]) ++j;
	}
	return j == N;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) cin >> C[i];
	for (int i = 0; i < M; i++) cin >> T[i];
	sort(C, C + N), sort(T, T + M);

	int l = 1, r = N;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (f(mid)) r = mid - 1;
		else l = mid + 1;
	}
	cout << (l == N + 1 ? -1 : l) << '\n';
	return 0;
}
