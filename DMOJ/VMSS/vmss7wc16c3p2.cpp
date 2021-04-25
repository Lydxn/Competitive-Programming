#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<int> adj[2001];
bool vis[2001];

void dfs(int A, int B) {
	if (A == B) { cout << "GO SHAHIR!\n"; exit(0); }
	if (vis[A]) return;
	vis[A] = true;
	for (int i : adj[A]) dfs(i, B);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, A, B, X, Y;
	cin >> N >> M >> A >> B;

	while (M--) cin >> X >> Y, adj[X].push_back(Y), adj[Y].push_back(X);
	dfs(A, B); cout << "NO SHAHIR!\n";
	return 0;
}
