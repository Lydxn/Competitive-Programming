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

string s;
vector<int> adj[100001];
int c[100001];

void dfs(int cur, int prev, int rep) {
	c[cur] = rep;
	for (int i : adj[cur])
		if (i != prev && s[i] == s[rep])
			dfs(i, cur, rep);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("milkvisits.in", "r", stdin);
	freopen("milkvisits.out", "w", stdout);

	int N, M;
	cin >> N >> M >> s; s = " " + s;
	for (int i = 0; i < N - 1; i++) {
		int X, Y; cin >> X >> Y;
		adj[X].push_back(Y), adj[Y].push_back(X);
	}
	for (int i = 1; i <= N; i++)
		if (c[i] == 0) dfs(i, 0, i);
	while (M--) {
		int A, B; char C; cin >> A >> B >> C;
		cout << (c[A] != c[B] || s[A] == C);
	}
	return 0;
}
