#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll summ(ll N) { return N * (N + 1) / 2; }
ll solve(ll N, ll T) {
	return N * T - 2 * summ((T - 1) / 2) - (T % 2 == 0 ? T / 2 : 0);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ll N, T;
	cin >> N >> T;
	cout << solve(N, T) * (N / T) + solve(N, N % T);
	return 0;
}
