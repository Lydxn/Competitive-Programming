#include <iostream>

using namespace std;

int packet[10000];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	while (cin >> N && N != -1)
	{
		int sum = 0;
		for (int i = 0; i < N; i++)
		{
			cin >> packet[i];
			sum += packet[i];
		}

		int mean = sum / N, res = 0;
		if (mean * N == sum)
		{
			for (int i = 0; i < N; i++)
			{
				if (packet[i] < mean)
				{
					res += mean - packet[i];
				}
			}
			cout << res << "\n";
		}
		else
		{
			cout << -1 << "\n";
		}
	}
	return 0;
}
