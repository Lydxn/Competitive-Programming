#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int P[100000], M;
unordered_set<int> s;

bool solve(int n) {
	s.clear();
	for (int i = 0; i <= n; i++)
		s.insert(round((double) i * 100.0 / n));

	for (int i = 0; i < M; i++)
		if (!s.count(P[i]))
			return false;
	return true;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> M;
	for (int i = 0; i < M; i++) cin >> P[i];

	for (int i = 1; ; i++) {
		if (solve(i)) {
			cout << i << '\n';
			return 0;
		}
	}
	return 0;
}
