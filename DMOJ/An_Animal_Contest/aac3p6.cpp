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

int N, M, ans, a[1000000], b[1000000], ansa[1000000], ansb[1000000];

void toobad() {
	for (int i = 0; i < N; i++) ansa[i] = a[i] & 1;
	for (int i = 0; i < M; i++) ansb[i] = (b[i] & 1) ^ 1;
	++ans;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int R, C;
	cin >> R >> C >> N >> M; ans = max(R, C) + 1;
	for (int i = 0; i < N; i++) cin >> a[i];
	for (int i = 0; i < M; i++) cin >> b[i];
	if (R < C) {
		for (int i = 0, j = 0, x = 0; i < M; i++) {
			x = max(x, b[i] - C + R);
			while (j < N && a[j] < x) ++j;
			while (j < N && a[j] == x) ++j, ++x;
			if (x <= b[i]) ansb[i] = b[i] - x;
			else { toobad(); break; }
		}
	} else {
		for (int i = 0, j = 0, x = 0; i < N; i++) {
			x = max(x, a[i] - R + C);
			while (j < M && b[j] < x) ++j;
			while (j < M && b[j] == x) ++j, ++x;
			if (x <= a[i]) ansa[i] = a[i] - x;
			else { toobad(); break; }
		}
	}
	cout << ans << '\n';
	for (int i = 0; i < N; i++) cout << ansa[i] << " \n"[i == N - 1];
	for (int i = 0; i < M; i++) cout << ansb[i] << " \n"[i == M - 1];
	return 0;
}
