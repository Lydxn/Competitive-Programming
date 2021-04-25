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

int t[3][100000], freq[3][100001];
bool vis[100000];
vector<int> cols[100001];
queue<int> q;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, x, ans = 0;
	cin >> N;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < N; j++)
			cin >> x, t[i][j] = x, ++freq[i][x], cols[x].push_back(j);
	
	for (int i = 1; i <= N; i++)
		if (freq[1][i] == 0 || freq[2][i] == 0) q.push(i);
	while (!q.empty()) {
		int v = q.front(); q.pop();
		for (int j : cols[v]) {
			if (!vis[j]) {
				vis[j] = true, ++ans;
				for (int k = 0; k < 3; k++)
					if (--freq[k][t[k][j]] == 0) q.push(t[k][j]);
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
