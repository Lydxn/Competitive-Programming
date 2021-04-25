#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, long long> dp;

long long max_dollars(int n)
{
	if (n < 12) return n;
	else if (dp.count(n)) return dp[n];
	else
	{
		return dp[n] = max_dollars(n / 2) + max_dollars(n / 3) + max_dollars(n / 4);
	}
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	while (cin >> n)
	{
		cout << max_dollars(n) << "\n";
	}
	return 0;
}
