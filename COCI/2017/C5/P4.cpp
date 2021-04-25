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

int a[500000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> a[i];
	sort(a, a + N);
	for (int i = 0; i < K / 2; i++) swap(a[N - i - 1], a[N - K + i]);
	int f = 0;
	for (int i = N - 1; i >= 0; i--) f += f < a[i];
	if (f != K) cout << "-1";
	else for (int i = 0; i < N; i++) cout << a[i] << ' ';
	cout << '\n';
	return 0;
}
