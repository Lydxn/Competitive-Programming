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

struct platform {
	int Y, X1, X2;
	bool operator< (const platform &p) { return Y < p.Y; }
} p[100];

int h[10000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> p[i].Y >> p[i].X1 >> p[i].X2;
	
	sort(p, p + N);
	for (int i = 0; i < N; i++) {
		ans += 2 * p[i].Y - h[p[i].X1] - h[p[i].X2 - 1];
		for (int j = p[i].X1; j < p[i].X2; j++) h[j] = p[i].Y;
	}
	cout << ans << '\n';
	return 0;
}
