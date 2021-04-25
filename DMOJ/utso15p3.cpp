#include <cstring>
#include <iostream>

typedef long long ll;

using namespace std;

ll dp[5][100001];
const ll MOD = 1000000007;

ll a(int N);
ll b(int N);
ll c1(int N);
ll c2(int N);
ll d(int N);

ll a(int N)
{
	if (N <= 0)			return 0;
	else if (~dp[0][N]) return dp[0][N];
	else				return dp[0][N] = (a(N - 1) + b(N - 2) + c1(N - 3)) % MOD;
}

ll b(int N)
{
	if (N <= 0)			return 0;
	else if (~dp[1][N]) return dp[1][N];
	else				return dp[1][N] = (a(N - 2) + c2(N - 3) + d(N - 1) + d(N - 3)) % MOD;
}

ll c1(int N)
{
	if (N <= 0)			return 0;
	else if (~dp[2][N]) return dp[2][N];
	else				return dp[2][N] = (a(N - 2) + c2(N)) % MOD;
}

ll c2(int N)
{
	if (N <= 0)			return 0;
	else if (~dp[3][N]) return dp[3][N];
	else				return dp[3][N] = (a(N - 1) + a(N - 2) + c2(N - 3) + d(N - 1) + d(N - 3)) % MOD;
}

ll d(int N)
{
	if (N <= 0)			return 0;
	else if (~dp[4][N])	return dp[4][N];
	else				return dp[4][N] = (a(N) + b(N - 1)) % MOD;
}

ll f(int N)
{
	if (N <= 0)			return 0;
	else if (~dp[0][N]) return dp[0][N];
	else				return dp[0][N] = (f(N - 1) + f(N - 3)) % MOD;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	memset(dp, -1, sizeof(dp));
	dp[0][1] = 1;

	if (M == 1)		 cout << 1 << '\n';
	else if (M == 2) cout << f(N) << '\n';
	else			 cout << a(N) << '\n';
	return 0;
}
