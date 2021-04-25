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

int V[100002], H[100002];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int Xe, Ye, X, Y, N, M, C;
	cin >> Xe >> Ye >> N >> M >> C;
	for (int i = 1; i <= N; i++) cin >> V[i];
	for (int i = 1; i <= M; i++) cin >> H[i];
	V[N + 1] = H[M + 1] = 1000000;
	sort(V, V + N + 2), sort(H, H + M + 2);
	
	auto vt = upper_bound(V, V + N + 2, Xe), ht = upper_bound(H, H + N + 2, Ye);
	int vl = *(vt - 1), vr = *vt, hl = *(ht - 1), hr = *ht;
	
	while (C--) {
		cin >> X >> Y;
		cout << "NY"[vl <= X && X <= vr && hl <= Y && Y <= hr] << '\n';
	}
	return 0;
}
