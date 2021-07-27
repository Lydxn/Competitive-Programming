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

int inv[3001], ans[3001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 2; i <= N; i++) {
		cout << "? " << 1 << ' ' << i << endl;
		cin >> inv[i];
	}
	for (int i = N; i; i--) inv[i] -= inv[i - 1];
	for (int i = 1; i <= N; i++) {
		int idx = N;
		while (ans[idx] || inv[idx] != idx - 1) --idx;
		for (int j = idx + 1; j <= N; j++) ++inv[j];
		ans[idx] = i;
	}
	cout << '!';
	for (int i = 1; i <= N; i++) cout << ' ' << ans[i];
	cout << endl;
	return 0;
}
