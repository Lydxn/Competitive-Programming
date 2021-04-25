#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;
vector<int> adj[100001];
bool in[100001];
ll dp0[100001], dp1[100001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, a, b;
	cin >> N >> M;

	while (M--) {
		cin >> a >> b;
		adj[a].push_back(b), in[b] = true;
	}

	for (int i = 1; i <= N; i++)
		if (!in[i])
			dp0[i] = 1;

	for (int i = 1; i <= N; i++)
		for (int j : adj[i])
			dp0[j] = (dp0[j] + dp0[i]) % MOD, dp1[j] = (dp1[j] + dp1[i] + dp0[i]) % MOD;

	ll ans = 0;
	for (int i = 1; i <= N; i++)
		if (adj[i].empty())
			ans = (ans + dp1[i]) % MOD;
	cout << ans << '\n';
	return 0;
}
