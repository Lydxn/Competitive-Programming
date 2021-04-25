#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll v1[100000], v2[100000];
int i1, i2;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, S, P;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> S >> P;
		(P == 1 ? v1[i1++] : v2[i2++]) = S;
	}

	sort(v1, v1 + i1); sort(v2, v2 + i2);
	for (int i = 1; i < i1; i++) v1[i] += v1[i - 1];

	ll ans = 0, sum = 0;
	for (int i = 0; i <= i2 && sum <= M; i++) {
		int ones = upper_bound(v1, v1 + i1, M - sum) - v1;
		ans = max(ans, 2LL * i + ones);

		sum += v2[i];
	}
	cout << ans << '\n';
	return 0;
}
