#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

bool grid[2000][2000];
int psa[2001][2001], diff[2001][2001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M; char ch;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> ch;
			grid[i][j] = ch == '#';
		}
	}

	psa[0][0] = grid[0][0];
	for (int i = 1; i < N; i++) psa[i][0] = psa[i - 1][0] + grid[i][0];
	for (int i = 1; i < M; i++) psa[0][i] = psa[0][i - 1] + grid[0][i];
	for (int i = 1; i < N; i++)
		for (int j = 1; j < M; j++)
			psa[i][j] = psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1] + grid[i][j];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << psa[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
