#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
int dp[7001];
bool sieve[7001];
vector<int> primes;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	memset(sieve, true, sizeof(sieve));
	for (int i = 2; i <= N; i++)
		for (int j = i * i; j <= N; j += i)
			sieve[j] = false;

	for (int i = 2; i <= N; i++)
		if (sieve[i])
			primes.push_back(i);

	memset(dp, INF, sizeof(dp));
	dp[0] = 0;

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j : primes) {
			if (j > i) break;
			dp[i] = min(dp[i], dp[i - j] + 1);
		}
		ans += dp[i] == K;
	}

	cout << ans << '\n';
	return 0;
}
