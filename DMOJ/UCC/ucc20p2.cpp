#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, m, mn = INT_MAX;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> M; int sum = 0;
		for (int i = 0; i < M; i++) cin >> m, sum += m;
		mn = min(mn, sum);
	}
	cout << mn << '\n';
	return 0;
}
