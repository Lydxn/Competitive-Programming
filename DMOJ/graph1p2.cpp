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

int dist[100];
bool grid[100][100];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> grid[i][j];

	queue<int> q; memset(dist, INF, sizeof(dist));
	q.push(0), dist[0] = 0;

	while (!q.empty()) {
		int cv = q.front(); q.pop();
		for (int i = 0; i < N; i++)
			if (grid[cv][i] && dist[i] == INF)
				q.push(i), dist[i] = dist[cv] + 1;
	}
	cout << dist[N - 1] << '\n';
	return 0;
}
