#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct edge { int u, v, w; bool operator< (const edge& e) const { return w < e.w; } };
unordered_map<int, edge> mp;
vector<edge> edges;
int nodes[8], par[101], sz[101];

int find(int v) { return v == par[v] ? v : par[v] = find(par[v]); }
bool join(int u, int v) {
	if ((u = find(u)) == (v = find(v))) return false;
	if (sz[u] < sz[v]) swap(u, v);
	par[v] = u, sz[u] += sz[v];
	return true;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int M, e, c, ans1 = 0, ans2 = 0;
	cin >> M;
	for (int i = 1; i <= M; i++) {
		cin >> e;
		for (int j = 0; j < e; j++) cin >> nodes[j];
		for (int j = 0; j < e; j++) {
			cin >> c;
			int ed = min(nodes[j], nodes[(j + 1) % e]) * 1000 + max(nodes[j], nodes[(j + 1) % e]);
			if (mp.count(ed)) mp[ed].v = i;
			else mp[ed] = {i, 0, c};
		}
	}

	for (auto m : mp) edges.push_back(m.second);
	sort(edges.begin(), edges.end());

	for (int i = 0; i <= M; i++) par[i] = i, sz[i] = 1;
	for (int i = 0, j = 0; i < int(edges.size()) && j <= M; i++) if (join(edges[i].u, edges[i].v)) ans1 += edges[i].w, ++j;

	for (int i = 0; i <= M; i++) par[i] = i, sz[i] = 1;
	for (int i = 0, j = 0; i < int(edges.size()) && j <= M; i++) if (edges[i].v && join(edges[i].u, edges[i].v)) ans2 += edges[i].w, ++j;
	cout << min(ans1, ans2) << '\n';
	return 0;
}
