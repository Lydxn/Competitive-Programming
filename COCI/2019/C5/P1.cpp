#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

char grid[100][100];
bool vis[100][100];
int N, M;

void flood(int i, int j) {
	if (i >= 0 && i < N && j >= 0 && j < M && !vis[i][j] && grid[i][j] == '*')
		vis[i][j] = true, flood(i + 1, j), flood(i, j + 1), flood(i - 1, j), flood(i, j - 1);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> grid[i][j];

	int ans = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (!vis[i][j] && grid[i][j] == '*')
				flood(i, j), ++ans;
	cout << ans << '\n';
	return 0;
}
