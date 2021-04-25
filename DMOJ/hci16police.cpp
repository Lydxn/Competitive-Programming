#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

const int MAXN = 100001;
int N, H, criminals[MAXN], dp[MAXN];

int fuel_cost(int A, int B)
{
	return (criminals[A] - criminals[B]) * (criminals[A] - criminals[B]);
}

int min_money(int A)
{
	if		(A > N) return 0;
	else if (dp[A] != 0) return dp[A];
	else
	{
		int res = INT_MAX;
		int cost = 0;
		for (int B = A; B <= N && cost <= H << 1; B++)
		{
			cost = fuel_cost(A, B);
			res = min(res, min_money(B + 1) + cost + H);
		}
		return dp[A] = res;
	}
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> H;
	for (int i = 1; i <= N; i++)
	{
		cin >> criminals[i];
	}
	cout << min_money(1) << "\n";
	return 0;
}
