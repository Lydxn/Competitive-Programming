#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int P, N, R, sum, ans = 0;
	cin >> P >> N >> R;

	for (sum = N; sum <= P; ans++) N *= R, sum += N;
	cout << ans << '\n';
	return 0;
}
