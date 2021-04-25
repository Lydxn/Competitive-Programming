#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000;
int par[MAXN + 1], sz[MAXN + 1];
pair<int, int> wt[MAXN];

int find(int v) { return par[v] == v ? v : par[v] = find(par[v]); }
bool join(int u, int v) {
	if ((u = find(u)) == (v = find(v))) return false;
	if (sz[u] < sz[v]) swap(u, v);
	par[v] = u, sz[u] += sz[v];
	return true;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, K, mst = 0, v;
	cin >> N >> K;

	for (int i = 1; i < N; i++) {
		cin >> v;
		wt[i] = {v, i};
	}

	memset(sz, 1, sizeof(sz));
	for (int i = 1; i <= N; i++) par[i] = i;

	sort(wt + 1, wt + N);
	for (int i = 1; i + K <= N; i++) join(i, i + K);

	for (int i = 1; i < N; i++) {
		if (join(wt[i].second, wt[i].second + 1)) mst += wt[i].first;
	}

	cout << mst << '\n';
	return 0;
}
