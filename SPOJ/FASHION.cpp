#include <algorithm>
#include <iostream>

using namespace std;

int men[1000], women[1000];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, N, j;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> N;
		for (j = 0; j < N; j++) cin >> men[j];
		for (j = 0; j < N; j++) cin >> women[j];

		sort(men, men + N);
		sort(women, women + N);

		int res = 0;
		for (j = 0; j < N; j++)
		{
			res += men[j] * women[j];
		}
		cout << res << "\n";
	}
	return 0;
}
