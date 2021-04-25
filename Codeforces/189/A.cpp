#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 4001;
int dp[MAXN];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, a, b, c;
	cin >> n >> a >> b >> c;

	fill(dp + 1, dp + n, INT_MIN);
	for (int i = 1; i <= n; i++)
	{
		if (i >= a) dp[i] = max(dp[i], 1 + dp[i - a]);
		if (i >= b) dp[i] = max(dp[i], 1 + dp[i - b]);
		if (i >= c) dp[i] = max(dp[i], 1 + dp[i - c]);
	}

	cout << dp[n] << '\n';
	return 0;
}
