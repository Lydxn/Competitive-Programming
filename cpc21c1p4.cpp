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

vector<int> radj[300001];
int mx[300001];

void dfs(int cur, int rep) {
	if (mx[cur]) return;
	mx[cur] = rep;
	for (int i : radj[cur]) dfs(i, rep);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, a, b;
	cin >> N >> M;
	while (M--) {
		cin >> a >> b;
		radj[b].push_back(a);
	}
	for (int i = N; i; i--) {
		if (mx[i]) { cout << i << ' ' << mx[i] << '\n'; return 0; }
		dfs(i, i);
	}
	cout << "-1\n";
	return 0;
}