#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll N;
int solve(ll n) {
	if (n > N) return 0;
	return solve(n * 10 + 2) + solve(n * 10 + 3) + 1;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	cout << solve(2) + solve(3) << '\n';
	return 0;
}
