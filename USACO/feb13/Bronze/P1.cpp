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

vector<int> adj[1001];
int col[1001];
bool cycle; int cnt;

void dfs(int cur) {
	col[cur] = 1, ++cnt;
	for (int i : adj[cur]) {
		if (col[i] == 1) cycle = true;
		else if (col[i] == 0) dfs(i);
	}
	col[cur] = 2;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("relay.in", "r", stdin);
	freopen("relay.out", "w", stdout);

	int N, f, ans = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> f;
		if (f) adj[f].push_back(i);
	}
	vector<int> check;
	for (int i = 1; i <= N; i++) {
		if (col[i] == 0) {
			cycle = false; dfs(i);
			if (cycle) check.push_back(i);
		}
	}
	memset(col, 0, sizeof(col));
	for (int i : check) {
		cnt = 0; dfs(i);
		ans += cnt;
	}
	cout << N - ans << '\n';
	return 0;
}
