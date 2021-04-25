#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T;
	long long N;
	cin >> T;

	while (T--)
	{
		cin >> N;
		cout << (N * N - 1) * (3 * N + 2) * N / 12 << '\n';
	}
	return 0;
}
