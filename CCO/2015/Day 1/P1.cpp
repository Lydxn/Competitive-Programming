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

int T[100000], N, W;

ll f(int x) {
	ll res = 0;
	for (int i = 0, j, p = W; i < N; i++, x ^= 1) {
		j = x % 2 ? i / 2 : N - i / 2 - 1;
		res += max(abs(T[j] - p), abs(T[j] - W));
		p = T[j];
	}
	return res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int mn = 0; ll mx = 0;
	cin >> N >> W;
	for (int i = 0; i < N; i++) cin >> T[i];
	sort(T, T + N);
	
	if (W < T[0]) mn = T[N - 1] - W;
	else if (W > T[N - 1]) mn = W - T[0];
	else mn = T[N - 1] - T[0];
	mx = max(f(0), f(1));
	
	cout << mn << ' ' << mx << '\n';
	return 0;
}
