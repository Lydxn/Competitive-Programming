#include <iostream>

using namespace std;

int sum_bits(int N)
{
	int res = 0;
	for (int i = 1; i <= N; i <<= 1)
	{
		res += ((N >> 1) & ~(i - 1)) + (N & i ? (N & ((i << 1) - 1)) - (i - 1) : 0);
	}
	return res;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T, N;
	cin >> T;

	while (T--)
	{
		cin >> N;
		cout << sum_bits(N) << '\n';
	}
	return 0;
}
