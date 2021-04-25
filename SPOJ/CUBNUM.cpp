#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 100000, MAXCUBE = 47;
int dp[MAXN + 1], cubes[MAXCUBE + 1];

void init_cubes()
{
	for (int i = 1; i <= MAXCUBE; i++) cubes[i] = i * i * i;
}

int main()
{
	init_cubes();
	cin.sync_with_stdio(0);
	cin.tie(0);

	for (int i = 1; i <= MAXN; i++)
	{
		dp[i] = i;
		for (int j = 1; cubes[j] <= i; j++)
		{
			dp[i] = min(dp[i], dp[i - cubes[j]] + 1);
		}
	}

	int N;
	for (int i = 1; cin >> N; i++) cout << "Case #" << i << ": " << dp[N] << '\n';
	return 0;
}
