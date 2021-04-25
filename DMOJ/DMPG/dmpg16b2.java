#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T, N, B, M, S;
	cin >> T;

	cout << fixed << setprecision(2);
	while (T--)
	{
		cin >> N >> B;

		M = 0;
		for (int i = 0; i < N - 1; i++)
		{
			cin >> S;
			M += S > B;
		}
		cout << "Bob wins $" << sqrt(N - M) * 100.0 << " at IOI!\n";
	}
	return 0;
}
