#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

char grid[25][25];
string s;
int N, Q;
pii dir[8] = {{1, 1}, {1, 0}, {1, -1}, {0, 1}, {0, -1}, {-1, 1}, {-1, 0}, {-1, -1}};

bool rec(int i, int j, int idx, unordered_set<int> &vis) {
	if (idx == int(s.size())) return true;
	if (i < 0 || i >= N || j < 0 || j >= N || grid[i][j] != s[idx] || vis.count(i * N + j)) return false;
	vis.insert(i * N + j);

	bool ans = false;
	for (auto d : dir) ans |= rec(i + d.first, j + d.second, idx + 1, vis);
	return ans;
}

bool solve() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			unordered_set<int> vis;
			if (rec(i, j, 0, vis)) return true;
		}
	}
	return false;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> Q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> grid[i][j];
		}
	}

	while (Q--) {
		cin >> s;
		cout << (solve() ? "good" : "bad") <<  " puzzle!" << '\n';
	}
	return 0;
}
