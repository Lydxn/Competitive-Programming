#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 100001;
long long freq[MAXN], dp[MAXN];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, a, maxn = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a;
		freq[a]++;
		maxn = max(maxn, a);
	}

	dp[1] = freq[1];
	for (int i = 2; i < MAXN; i++)
	{
		dp[i] = max(dp[i - 1], dp[i - 2] + freq[i] * i);
	}

	cout << dp[MAXN - 1] << '\n';
	return 0;
}
