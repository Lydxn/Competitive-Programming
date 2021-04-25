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

int h[100001]; ll s[200001];
int N, M, K;

bool f(int x) {
	ll k = 0; memset(s, 0, sizeof(s));
	for (int i = 1; i <= N; i++) {
		s[i] += s[i - 1];
		ll diff = x - s[i] - h[i];
		if (diff > 0) k += diff, s[i] += diff, s[i + M] -= diff;
	}
	return k <= K;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) cin >> h[i];
	
	int l = 0, r = 2e9, m;
	while (l <= r) {
		m = l + (r - l) / 2;
		if (f(m)) l = m + 1;
		else r = m - 1;
	}
	cout << l - 1 << '\n';
	return 0;
}
