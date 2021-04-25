#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int v[1001], freq[100001];
vector<int> path, st, adj[1001];

void dfs(int x, int y, int prev, vector<int> st) {
	st.push_back(x);
	if (x == y) for (auto& i : st) path.push_back(v[i]);
	else for (auto& i : adj[x]) if (i != prev) dfs(i, y, x, st);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, Q, a, b, x, y, op;
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) cin >> v[i];
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		adj[a].push_back(b); adj[b].push_back(a);
	}

	while (Q--) {
		cin >> op >> x >> y; st.clear(); path.clear(); dfs(x, y, -1, st);
		if (op == 1) cout << round(accumulate(path.begin(), path.end(), 0.0) / path.size()) << '\n';
		else if (op == 2) {
			sort(path.begin(), path.end()); int sz = path.size();
			cout << round(sz % 2 ? path[sz >> 1] : (path[(sz - 1) >> 1] + path[sz >> 1]) / 2.0) << '\n';
		} else {
			memset(freq, 0, sizeof(freq)); int mx = 0, mi = 0;
			for (auto& i : path) {
				if (++freq[i] > mx) mx = freq[i], mi = i;
				else if (freq[i] == mx) mi = min(mi, i);
			}
			cout << mi << '\n';
		}
	}
	return 0;
}
