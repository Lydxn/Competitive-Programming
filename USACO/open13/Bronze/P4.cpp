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

int N, ans = INF, f[13][3], p[13];

int check() {
	int res = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 0; j < 3; j++)
			res += abs(p[i] - p[f[i][j]]);
	return res >> 1;
}

void solve(double what) {
	// 1st try at simulated annealing
	while (what > 1e-9) {
		int a = rand() % N + 1, b = rand() % N + 1;
		swap(p[a], p[b]);
		int cur = check();
		if (cur < ans) ans = cur;
		else if (exp((ans - cur) / what) < (double) rand() / RAND_MAX) swap(p[a], p[b]);
		what *= 0.99;
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("haywire.in", "r", stdin);
	freopen("haywire.out", "w", stdout);

	srand(time(0));

	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 0; j < 3; j++)
			cin >> f[i][j];
	for (int i = 1; i <= N; i++) p[i] = i;
	for (int i = 0; i < 50; i++) solve(300);
	cout << ans << '\n';
	return 0;
}
