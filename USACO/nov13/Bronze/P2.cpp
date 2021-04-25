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

pii s[40000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("milktemp.in", "r", stdin);
	freopen("milktemp.out", "w", stdout);

	int N, X, Y, Z, A, B;
	cin >> N >> X >> Y >> Z;
	for (int i = 0; i < N; i++) {
		cin >> A >> B;
		s[i << 1] = {A, Y - X}, s[i << 1 | 1] = {B + 1, Z - Y};
	}

	sort(s, s + (N << 1));
	int cur = N * X, ans = cur;
	for (int i = 0; i < N << 1; i++)
		cur += s[i].second, ans = max(ans, cur);
	cout << ans << '\n';
	return 0;
}
