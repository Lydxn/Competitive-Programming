#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, x; ll sum = 0;
	cin >> N;
	for (int i = 1; i < N; i++) cin >> x, sum += x;
	cout << N * (N + 1) / 2 - sum << '\n';
	return 0;
}
