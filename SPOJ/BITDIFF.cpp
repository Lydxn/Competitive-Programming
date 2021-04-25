#include <iostream>

using namespace std;

const int MOD = 10000007;
int nums[10000];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T, N;
	cin >> T;

	long long res;
	for (int i = 1, ones; i <= T; i++)
	{
		cin >> N;
		for (int j = 0; j < N; j++) cin >> nums[j];

		res = 0;
		for (int j = 0; j < 32; j++)
		{
			ones = 0;
			for (int k = 0; k < N; k++)
			{
				if (nums[k] & (1 << j)) ++ones;
			}

			res += ones * (N - ones);
			if (res >= MOD) res %= MOD;
		}

		res <<= 1;
		if (res >= MOD) res %= MOD;
		cout << "Case " << i << ": " << res << '\n';
	}
	return 0;
}
