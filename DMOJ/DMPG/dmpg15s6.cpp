#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

unordered_map<string, int> mp;
vector<pair<int, double>> adj[500];
queue<int> q;
double dist[500];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M; string a, b; double c;
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> a, mp[a] = i;
	for (int i = 0; i < M; i++) cin >> a >> b >> c, adj[mp[a]].emplace_back(mp[b], c);

	int s = mp["APPLES"]; dist[s] = 1.0, q.push(s);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		if (cur == s && dist[cur] - 1.0 > 1e-6) {
			cout << "YA\n";
			return 0;
		}

		for (auto i : adj[cur]) {
			double d = dist[cur] * i.second;
			if (d > dist[i.first]) dist[i.first] = d, q.push(i.first);
		}
	}
	cout << "NAW\n";
	return 0;
}
