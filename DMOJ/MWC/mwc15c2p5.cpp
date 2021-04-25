#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll diff[4][100002];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, K, J, Xi, Xf, I, T;
	cin >> N >> K >> J;

	while (J--) {
		cin >> Xi >> Xf >> I >> T;
		diff[T][Xi] += I, diff[T][Xf + 1] -= I;
	}

	for (int i = 1; i <= 3; i++) {
		int cnt = 0;
		for (int j = 1; j <= N; j++) cnt += (diff[i][j] += diff[i][j - 1]) < K;
		cout << cnt << '\n';
	}
	return 0;
}
