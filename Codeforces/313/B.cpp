#include <iostream>
#include <string>

using namespace std;

int dp[100001];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	string s;
	int m, l, r;
	cin >> s >> m;

	for (int i = 1; i < s.size(); i++)
	{
		dp[i + 1] = dp[i] + (s[i] == s[i - 1]);
	}

	while (m--)
	{
		cin >> l >> r;
		cout << dp[r] - dp[l] << '\n';
	}
	return 0;
}
